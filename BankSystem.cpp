/**
 *  Project Name: BanK Management System
 *  File: main.cpp
 *  Authors: Thalia Valle Chavez | David Bentazos
 *  Class: COP 3003, CRN: 85147
 *  Purpose: Creation and Management of Costumers Bank Accounts.
 */
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include "global_defs.h"
#include "Menu.h"
#include "NewAccount.h"
#include "Account.h"
using namespace std;


/**
 * The main function
 * @return OS status message (0=Success)
 */
int main() {
    int userInput;
    Account user;

    do {
        user.DisplayTitle();
        user.DisplayMenu0();

        cin >> userInput;
        //system("CLS");

        switch (userInput) {
        case 1:
            system("CLS");
            user.AccountAccess();
            if (user.Log_in()) {
                int userInput0;
                do {
                    system("CLS");
                    user.DisplayMenu();
                    cin >> userInput0;
                    system("CLS");

                    switch (userInput0) {

                    case EditAccount:
                        system("CLS");
                        user.EditAccount();
                        Sleep(SLEEP_TIME);
                        system("CLS");

                        break;
                    case CheckBalance:
                        system("CLS");
                        user.CheckBalance();
                        Sleep(SLEEP_TIME);
                        system("CLS");

                        break;
                    case AccountInformation:
                        system("CLS");
                        user.DisplayInformation();
                        Sleep(SLEEP_TIME);
                        system("CLS");

                        break;
                    case DepositFunds:
                        system("CLS");
                        user.DepositFunds();
                        Sleep(SLEEP_TIME);
                        system("CLS");

                        break;
                    case WithdrawFunds:
                        system("CLS");
                        user.WithdrawFunds();
                        Sleep(SLEEP_TIME);
                        system("CLS");

                        break;
                    case CloseAccount:
                        user.CloseAccount();
                        Sleep(SLEEP_TIME); // Halts the program

                        break;
                    case SignOut:
                        system("CLS");
                        cout << "\t\t\t\t\tSigning Out...\n";
                        Sleep(SLEEP_TIME);
                        system("CLS");

                        break;

                    default:
                        cout << "\t\t\t\t\tIncorrect Input. Try Again.\n";
                        Sleep(SLEEP_TIME);
                        system("CLS");


                    };

                } while (userInput0 != 7);

            }

            break;
        case 2:
            system("CLS");
            user.CreateAccount();
            Sleep(SLEEP_TIME);
            system("CLS");
            break;

        case 3:
            user.ClearAccounts(); // Delete all the accounts (frees up the memory)
            cout << "\t\t\t\t\tThank you!\n";

            break;
        default:

            cout << "\t\t\t\t\tIncorrect Input. Try Again.\n";
            Sleep(SLEEP_TIME);
            system("CLS");

        }


    } while (userInput != 3);


    return 0;
}

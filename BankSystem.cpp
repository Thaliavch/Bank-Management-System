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
        user.DisplayMenu0();
        cin >> userInput;
        system("CLS");

        switch (userInput) {
        case 1:
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
                        user.EditAccount();

                        break;
                    case CheckBalance:
                        user.CheckBalance();

                        break;
                    case AccountInformation:
                        user.DisplayInformation();

                        break;
                    case DepositFunds:
                        user.DepositFunds();

                        break;
                    case WithdrawFunds:
                        user.WithdrawFunds();

                        break;
                    case CloseAccount:
                        user.CloseAccount();

                        break;
                    case SignOut:
                        cout << "Signing Out...";

                        break;
                    default:
                        cout << "Incorrect Input. Try Again.";


                    };
                   
                } while (userInput0 != 7);

            }

            break;
        case 2:
            user.CreateAccount();

            break;
        case 3:
            cout << "Thank you!";

            break;
        default:

            cout << "Incorrect Input. Try Again.";

        }
        

    } while (userInput != 3);


    return 0;
}


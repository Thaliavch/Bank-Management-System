#include "NewAccount.h"
#include "global_defs.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;

int NewAccount::account_index = 0; // initialization of static variable account_index;


/**
  * Create user account and store user information in a the vector usersList of type userInfo.
  * Check for password requirements.
  * Assign account number to user.
  * @param: None
  * @return: Void
  */
void NewAccount::CreateAccount() {

    userInfo info; // struct declaration
    info.account_number = FIRST_ACCOUNT_NUMBER + account_index;
    account_index++;

    cout << "First name:       ";
    cin >> info.holder_name;

    cout << "Last name:        ";
    cin >> info.holder_last_name;

    cout << "E-mail:           ";
    cin >> info.e_mail;

    // Setting password____________________________________________
    cout << "Please enter a password of at least 8 digits: ";
    cin >> *psw_ptr;
    while (psw_ptr->length() < MIN_PASSWORD || psw_ptr->length() > MAX_PASSWORD) {
        cout << "The password must have at least 8 digits and no more than 50 digits \nTry again: ";
        cin >> *psw_ptr;
    }
    info.password = *psw_ptr;
    // End of password setting_____________________________________

    
    cout << "Amount to deposit in checking account        ";
    //cin >> info.checking_funds;

    info.checking_funds = GetValidDeposit();

    cout << "Amount to deposit in savings account        ";
    info.savings_funds = GetValidDeposit();

    //cin >> info.savings_funds;


    cout << "\n**********************************************************",
        cout << "\nCongratulations! Your account has been successfully created";
    cout << "\n\n\t\tYour account number is: " << info.account_number;
    cout << "\n**********************************************************";

    users.push_back(info);

}


/**
 * Asks the user to enter the account number
 * Asks the user to enter their password while the user has not exceeded attempts
 * Checks if the account is found in the system with the account number and password the user enters
 * @parm: None
 * @return: void
 * */
void NewAccount::AccountAccess() {

    // Checking for valid account number
    cout << "\nAccount Number: ";
    cin >> *accNum_ptr;

    do {
        for (int i = 0; i < users.size(); i++) {
            if (*accNum_ptr == users[i].account_number) {
                *user_index_ptr = i;
                *acc_found_ptr = true;
            }
        }
        if (!(*acc_found_ptr)) {
            cout << "\nAccount Not Found";
            cout << "\n1. Try Again";
            cout << "\n2. Exit";
            cout << "\nOption: ";
            cin >> *input_ptr;
            switch (*input_ptr) {
            case 1:
                cout << "Account Number: ";
                cin >> *accNum_ptr;

                break;
            case 2:
                cout << "Redirecting you to Main Menu...\n";

                *go_to_menu_ptr = true;
                *acc_found_ptr = true;

                break;
            default:
                cout << "Incorrect Input. Try Again.";
            }

        }

    } while (!*acc_found_ptr);
    // End of checking account number

    if (!(*go_to_menu_ptr)) {


        // Password Checking
        cout << "\nEnter Password: ";
        cin >> *psw_ptr;

        for (int i = 1; i < (MAX_PASSWORD_VERIFICATION_ATTEMPTS + 1); i++) // We have to go to the users file to retrieve his/her password and compare it to the user's input
        {                          // I am using the for loop to give him 8 attempts to enter the correct password.

            if (*psw_ptr != users[*user_index_ptr].password) {
                if (i == MAX_PASSWORD_VERIFICATION_ATTEMPTS) {
                    cout << "\nThis was your last attempt. This account will be temporary restricted. Try again later.";
                    *access_granted_ptr = false;
                }
                else {
                    cout << "\nWrong password. You have " << MAX_PASSWORD_VERIFICATION_ATTEMPTS - i << " attempts left. ";
                    cout << "\nTry again: ";
                    cin >> *psw_ptr;
                }
            }
            else {
                *access_granted_ptr = true;
                break;
            }
        }
    }

};


/**
/ Checks if a new valid account has been created for the user
/ @parm: None
/ @return: void
**/
bool NewAccount::Log_in() {
    return *access_granted_ptr;

}


// METHODS BY DAVID ADDED 12/2


/**
/ Chekcis if a the user enter a valid deposit to work with in the system
/ @parm: None
/ @return: int (deposit amount)
/
/**/
int NewAccount::GetValidDeposit() {
    int deposit_amount;
    bool valid_deposit = false;
    do {
        try {

            cout << "Amount:";

            if (!(cin >> deposit_amount)) { // First we must check if the user enter a number at all


                cout << "Not a number. Please try again " << endl;

                cin.clear();

                cin.ignore(INT_MAX, '\n');

            }

            else if (deposit_amount < 0) // The deposit amount is less than 0 (it can't be)
                throw(deposit_amount); // throw the number

            else
                valid_deposit = true;
        }

        catch (int exception) {

            cout << "Invalid depsoit. It can't be " << exception << endl;
        }

    } while (!valid_deposit);

    return deposit_amount;

}

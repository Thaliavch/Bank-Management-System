#include "NewAccount.h"
#include "global_defs.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int NewAccount::account_index = 0; // initialization of static variable account_index;
// NEW ADDITION MADE BY ME
/**
  * Exception handling for when the user enters a incorrect ipnut (ex. a letter when it asks 
  * for a number. Return whther the user inputs is valid or not.
  * @parm: input the user enters for deposit amount and withdraw amount
  * @return: bool
  */
bool NewAccount:: ValidInput(int number){
bool valid_input = true;
 try{
  throw(number);
 }
 catch(...){
    cerr << "Not a valid input. Please try again. " << endl;
    valid_input = false;
 }
 
 return valid_input;
}

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
 
    // Get a valid input from the user to deposit and withdraw
    do{
    cout << "Amount to deposit in checking account:        ";
    cin >> info.checking_funds;
    
    }while(!ValidInput(info.checking_funds));
 
    do{
    cout << "Amount to deposit in savings account:         ";
    cin >> info.savings_funds;
    }while(!ValidInput(info.checking_funds));

    cout << "\n**********************************************************",
        cout << "\nCongratulations! Your account has been successfully created";
    cout << "\n\n\t\tYour account number is: " << info.account_number;
    cout << "\n**********************************************************";

    usersList.push_back(info);

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
        for (int i = 0; i < usersList.size(); i++) {
            if (*accNum_ptr == usersList[i].account_number) {
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
                cout << "Redirecting you to Main Menu...";
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

            if (*psw_ptr != usersList[*user_index_ptr].password) {
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

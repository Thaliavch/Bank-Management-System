/**
 *  Project Name: BanK Management System
 *  File: main.cpp
 *  Authors: Thalia Valle Chavez | David Bentazos | Shabah Gonzales
 *  Class: COP 3003, CRN: 85147
 *  Purpose: Creation and Management of Costumers Bank Accounts.
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include "defs.h"
using namespace std;

//--------------------------------------------------------
// Class declarations start here
//--------------------------------------------------------
class Menu{
public:
    Menu(){
        cout << "*********************************************";
        cout << "   BANK MANAGEMENT SYSTEM   ";
        cout << "*********************************************" << endl;
    }
    void DisplayMenu();
};// end of Menu Class


//-------------------------------
class NewAccount: public Menu{
    static int account_index;

protected:
    string psw;
    int user_index;
    int accNum;
    int input;
    bool access_granted;
    bool acc_found;

    //Pointer to variables above;
    string* psw_ptr = &psw;
    int* user_index_ptr = &user_index;
    int* accNum_ptr = &accNum;
    int* input_ptr = &input;
    bool* access_granted_ptr = &access_granted;
    bool* acc_found_ptr = &acc_found;

    struct userInfo{
        string holder_name;
        string holder_last_name;
        int account_number;
        string password;
        int savings_funds;
        int checking_funds;
    };
    vector<userInfo>usersList;

public:
    void CreateAccount();
    void AccountAccess();
    
}; // End of NewAccount


//-------------------------------
class Account: public NewAccount{
    
public:
    void EditAccount();
    void CheckBalance();
    void DisplayInformation();
    void DepositFunds();
    void WithdrawFunds();
    void CloseAccount();
}; // End of Account class
//--------------------------------------------------------
// End of class declarations
//--------------------------------------------------------
int NewAccount::account_index = 0; // initialization of static variable account_index;


/**
 * The main function
 * @return OS status message (0=Success)
 */
int main() {
    int userInput;
    Account user;

    do{
        
        user.DisplayMenu();
        cin >> userInput;
        system("clear");

        switch(userInput){

            case CreateAccount:
                user.CreateAccount();
                sleep(SLEEP_TIME);
                
                break;
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
            case ExitProgram:
                cout << "Thank You for Using our Bank Management System.";
                
                break;
            default:
                cout << "Incorrect Input. Try Again.";
                

        };
        sleep(SLEEP_TIME);
        system("clear");

    }while(userInput != 8);


    return 0;
}// end of main


//----------------------------------------------------------
// Method definitions start here
//----------------------------------------------------------
/**
 * Displays the options for the user to select from in the main menu
 * @param: None
 * @return: void
 **/
void Menu::DisplayMenu(){
    cout << "\n\nPlease select an option below:";
    cout << "\n\n1. CREATE NEW ACCOUNT";
    cout << "\n\n2. EDIT AN ACCOUNT";
    cout << "\n\n3. CHECK ACCOUNT BALANCE";
    cout << "\n\n4. DISPLAY ACCOUNT INFORMATION";
    cout << "\n\n5. DEPOSIT FUNDS";
    cout << "\n\n6. WITHDRAW FUNDS";
    cout << "\n\n7. CLOSE ACCOUNT";
    cout << "\n\n8. EXIT FROM PROGRAM";
    cout << "\n\nOPTION: ";
}


/**
 * Creates users account and stores user information in a the vector usersList of type userInfo.
 * Check for password requirements.
 * Assign account number to user.
 * @param: None
 * @return: Void
 */
 void NewAccount::CreateAccount(){

    userInfo info; // struct declaration
    info.account_number = FIRST_ACCOUNT_NUMBER + account_index;
    account_index++;

    cout<< "First name:       ";
    cin >>  info.holder_name;

    cout<< "Last name:        ";
    cin >>  info.holder_last_name;

    // Setting password____________________________________________
    cout << "Please enter a password of at least 8 digits: ";
    cin >> *psw_ptr;
    while(psw_ptr->length() < MIN_PASSWORD || psw_ptr->length() > MAX_PASSWORD ){
        cout << "The password must have at least 8 digits and no more than 50 digits \nTry again: ";
        cin >> *psw_ptr;
    }
    info.password = *psw_ptr;
    // End of password setting_____________________________________

    cout << "Amount to deposit in checking account:        ";
    cin >> info.checking_funds;

    cout << "Amount to deposit in savings account:         ";
    cin >> info.savings_funds;

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
void NewAccount::AccountAccess(){

     // Checking for valid account number
    cout << "\nAccount Number: ";
    cin >> *accNum_ptr;

    do{
        for (int i = 0; i < account_index; i++) {
            if (*accNum_ptr == usersList[i].account_number) {
                *user_index_ptr = i;
                *acc_found_ptr = true;
            }else{
                *acc_found_ptr = false;
            }
        }if(!(*acc_found_ptr)) {
            cout << "\nAccount Not Found. Try Again";
            cout << "\nAccount Number: ";
            cin >> *accNum_ptr;
        }

    }while(!*acc_found_ptr);
    // End of checking account number

    // Password Checking
    cout << "\nEnter Password: ";
    cin >> *psw_ptr;

    for (int i = 1; i < (MAX_PASSWORD_VERIFICATION_ATTEMPTS + 1); i++) // We have to go to the users file to retrieve his/her password and compare it to the user's input
    {                          // I am using the for loop to give him 8 attempts to enter the correct password.

        if (*psw_ptr != usersList[*user_index_ptr].password) {
            if (i == MAX_PASSWORD_VERIFICATION_ATTEMPTS) {
                cout << "\nThis was your last attempt. This account will be temporary restricted. Try again later.";
                *access_granted_ptr = false;
            } else {
                cout << "\nWrong password. You have " << MAX_PASSWORD_VERIFICATION_ATTEMPTS - i << " attempts left. ";
                cout << "\nTry again: ";
                cin >> *psw_ptr;
            }
        }else{
            *access_granted_ptr = true;
            break;
        }
    }

};
 

/**
 * Displays options for user to edit their account
 * Asks the user for input from the options displayed while the user does not exit the editor
 * User enters what ever option they selected
 * 
 * @parm: None
 * @return: void
 * */
void Account::EditAccount(){

    AccountAccess();
    if(*access_granted_ptr){
        do{
            cout << "\nPlease select an option below";
            cout << "\n\n1. HOLDER NAME";
            cout << "\n\n2. HOLDER LAST NAME";
            cout << "\n\n3. PASSWORD";
            cout << "\n\n4. EXIT EDITOR";
            cout << "\n\nOPTION: ";
            cin >> *input_ptr;

            switch(*input_ptr){
                case 1:
                    cout << "\nEnter New Name: "; // add check to avoid repetition of account numbers later
                    cin >> usersList[*user_index_ptr].holder_name;
                    break;
                case 2:
                    cout << "\nEnter New Last Name: "; // add check to avoid repetition of account numbers later
                    cin >> usersList[*user_index_ptr].holder_last_name;
                    break;
                case 3:
                    cout << "\nEnter New Password      : ";
                    cin >> usersList[*user_index_ptr].password;
                    break;
                case 4:
                    cout << "\nExiting Editor...\n";
                    break;
                default:
                    cout << "\nIncorrect Input. Try Again.\n";

            };

        }while(*input_ptr != 4);
    }
}


/**
 * First, Checks if the user is stored in the system
 * Then displays options as to what account they want to look at and gets the input from user
 * Displays either the balance in the checking account and the balance in the
 * savings account (depending on what option the user picks)
 * @parm: None
 * @return: void
 * */
void Account::CheckBalance(){

    AccountAccess();
    if(*access_granted_ptr) {
        cout << "\nPlease select an option below";
        cout << "\n\n1. CHECKING ACCOUNT";
        cout << "\n\n2. SAVINGS ACCOUNT";
        cout << "\n\nOPTION: ";
        cin >> *input_ptr;

        switch (*input_ptr) {
            case 1:
                cout << "\nBalance: " << usersList[*user_index_ptr].checking_funds;
                break;
            case 2:
                cout << "\nBalance: " << usersList[*user_index_ptr].savings_funds;
                break;
        }
    }

}


/**
 * First, checks if the user is valid in the system
 *  Then, displays the account information of the user 
 * - First Name
 * - Last name
 * - Account Number
 * - Account Password
 * - Balance in their savings account
 * - Balance in their checking account
 * @parm: None
 * @return: void
 * */
void Account::DisplayInformation() {

    AccountAccess();
    if (*access_granted_ptr) {
        cout << "User:                     " << usersList[*user_index_ptr].holder_name << usersList[*user_index_ptr].holder_last_name << endl;
        cout << "Account Number:           " << usersList[*user_index_ptr].account_number << endl;
        cout << "Account Password:         " << usersList[*user_index_ptr].password << endl;
        cout << "Savings Account Balance:  " << usersList[*user_index_ptr].savings_funds << endl;
        cout << "Checking Account Balance: " << usersList[*user_index_ptr].checking_funds << endl;

    }
}


/**
 * First checks if the user is valid in the system
 * If the user is valid, it will display what account the user wants to deposit in
 * User inputs the option as to what account to deposit to
 * User inputs the amount of money
 * Adds the amount of money inputted to the current balance stored in the account they choose to select
 * @parm: None
 * @return: void
 * */
void Account::DepositFunds(){

    AccountAccess();
    if(*access_granted_ptr) {
        cout << "\nPlease select in which account you want to deposit: ";
        cout << "\n\n1. CHECKING ACCOUNT";
        cout << "\n\n2. SAVINGS ACCOUNT";
        cout << "\n\nOPTION: ";
        cin >> *input_ptr;

        switch (*input_ptr) {
            case 1:
                cout << "\nAmount: ";
                cin >> *input_ptr;
                usersList[*user_index_ptr].checking_funds += *input_ptr;
                cout << "\n**** New Balance: " << usersList[*user_index_ptr].checking_funds << " ****";
                break;
            case 2:
                cout << "\nAmount: ";
                cin >> *input_ptr;
                usersList[*user_index_ptr].savings_funds += *input_ptr;
                cout << "\n**** New Balance: " << usersList[*user_index_ptr].savings_funds << " ****";
                break;
        }
    }

}


/**
 * First checks if the user is valid in the system
 * If the user is valid, it will display what account the user wants to withdraw from
 * User inputs the option as to what account to deposit to
 * User inputs the amount of money
 * subtracts the amount of money inputted from the current balance stored in the account they choose to select
 * @parm: None
 * @return: void
 * */
void Account::WithdrawFunds(){

    AccountAccess();
    if(*access_granted_ptr) {
        cout << "\nPlease select in which account you want to withdraw: ";
        cout << "\n\n1. CHECKING ACCOUNT";
        cout << "\n\n2. SAVINGS ACCOUNT";
        cout << "\n\nOPTION: ";
        cin >> *input_ptr;

        switch (*input_ptr) {
            case 1:
                cout << "\nAmount: ";
                cin >> *input_ptr;
                usersList[*user_index_ptr].checking_funds -= *input_ptr;
                cout << "\n**** New Balance: " << usersList[*user_index_ptr].checking_funds << " ****";

                break;
            case 2:
                cout << "\nAmount: ";
                cin >> *input_ptr;
                usersList[*user_index_ptr].savings_funds -= *input_ptr;
                cout << "\n**** New Balance: " << usersList[*user_index_ptr].savings_funds << " ****";

                break;
        }
    }

}


/**
 * First, checks if the user is stored in the system
 * Will delete the account from the index stored in our array of structures for that
 * account
 * @parm: None
 * @return: void
 * */
void Account::CloseAccount(){

    AccountAccess();
    if(*access_granted_ptr){
        vector<userInfo>::iterator position;
        position = usersList.begin() + *user_index_ptr;
        usersList.erase(position);
    }

}

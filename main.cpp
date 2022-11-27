#include <iostream>
#include <vector>
#include <string>
#include "defs.h"
using namespace std;

// Classes declaration start here
class Menu{
public:
    Menu(){
        cout << "*********************************************";
        cout << "   BANK MANAGEMENT SYSTEM   ";
        cout << "*********************************************" << endl;
    }
    void DisplayMenu();
};// end of Menu Class


class NewAccount: public Menu{
    static int account_index;

    string psw;
    int user_index;
    int accNum;
    int input;
    bool access_granted;
    bool acc_found;

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
    void EditAccount();
    void CheckBalance();
    void DisplayInformation();
    void DepositFunds();
    void WithdrawFunds();
    void CloseAccount();
}; // End of NewAccount class
int NewAccount::account_index = 0; // initialization of static variable account_index;


int main() {
    int userInput;
    NewAccount user;

    do{
        user.DisplayMenu();
        cin >> userInput;

        switch(userInput){

            case CreateAccount:
                user.CreateAccount();

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
                cout << "Thank you for using our Bank Management System.";
                break;
            default:
                cout << "Incorrect input. Try again.";

        };

    }while(userInput != 8);


    return 0;
}

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


 void NewAccount::CreateAccount(){
    userInfo info; // struct declaration
    info.account_number = FIRST_ACCOUNT_NUMBER + account_index;
    account_index++;


    cout<< "Please enter the costumer's first name:       ";
    cin >>  info.holder_name;

    cout<< "Please enter the costumer's last name:        ";
    cin >>  info.holder_last_name;

    cout << "Please enter a password of at least 8 digits: ";
    cin >> psw;
    while(psw.length() < MIN_PASSWORD || psw.length() > MAX_PASSWORD ){
        cout << "The password must have at least 8 digits and no more than 50 digits \n Please try again: ";
        cin >> psw;
    }
    info.password = psw;

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

void NewAccount::AccountAccess(){
    cout << "\nPlease enter your account number: ";
    cin >> accNum;

    do{
        for (int i = 0; i < account_index; i++) {
            if (accNum == usersList[i].account_number) {
                user_index = i;
                acc_found = true;
            }else{
                acc_found = false;
            }
        }if(!acc_found) {
            cout << "\nAccount not found. Please try again";
            cout << "\nAccount number: ";
            cin >> accNum;
        }

    }while(!acc_found);



    cout << "\nEnter password: ";
    cin >> psw;

    for (int i = 1; i < (MAX_PASSWORD_VERIFICATION_ATTEMPTS + 1); i++) // We have to go to the users file to retrieve his/her password and compare it to the user's input
    {                          // I am using the for loop to give him 8 attempts to enter the correct password.

        if (psw != usersList[user_index].password) {
            if (i == MAX_PASSWORD_VERIFICATION_ATTEMPTS) {
                cout << "This was your last try. This account will be temporary restricted.";
                access_granted = false;
            } else {
                cout << "Wrong password. You have " << MAX_PASSWORD_VERIFICATION_ATTEMPTS - i
                     << " attempts left. Please try again: ";
                cin >> psw;
            }
        }else{
            access_granted = true;
            break;
        }
    }

};

void NewAccount::EditAccount(){

    AccountAccess();
    if(access_granted){
        do{
            cout << "\nPlease select an option below";
            cout << "\n\n1. ACCOUNT NUMBER";
            cout << "\n\n2. PASSWORD";
            cout << "\n\n3. EXIT EDITOR";
            cout << "\n\nOPTION: \n";

            cin >> input;

            switch(input){

                case 1:
                    cout << "\nEnter new account number: "; // add check to avoid repetition of account numbers later
                    cin >> usersList[user_index].account_number;
                    break;
                case 2:
                    cout << "\nEnter new password      : ";
                    cin >> usersList[user_index].password;
                    break;
                case 3:
                    cout << "\nExiting editor...\n";
                    break;
                default:
                    cout << "\nIncorrect input. Try again.\n";

            };

        }while(input != 3);
    }
}



void NewAccount::CheckBalance(){

    AccountAccess();

    if(access_granted) {
        cout << "\nPlease select an option below";
        cout << "\n\n1. CHECKING ACCOUNT";
        cout << "\n\n2. SAVINGS ACCOUNT";
        cout << "\n\nOPTION: \n";

        cin >> input;

        switch (input) {
            case 1:
                cout << "\nBalance: " << usersList[user_index].checking_funds;
                break;
            case 2:
                cout << "\nBalance: " << usersList[user_index].savings_funds;
                break;
        }
    }


}

void NewAccount::DisplayInformation() {
    AccountAccess();

    if (access_granted) {
        cout << user_index;
        cout << "User:                     " << usersList[user_index].holder_name << usersList[user_index].holder_last_name << endl;
        cout << "Account Number:           " << usersList[user_index].account_number << endl;
        cout << "Savings Account Balance:  " << usersList[user_index].savings_funds << endl;
        cout << "Checking Account Balance: " << usersList[user_index].checking_funds << endl;

    }
}

void NewAccount::DepositFunds(){

    AccountAccess();

    if(access_granted) {
        cout << "\nPlease select in which account you want to deposit: ";
        cout << "\n\n1. CHECKING ACCOUNT";
        cout << "\n\n2. SAVINGS ACCOUNT";
        cout << "\n\nOPTION: \n";

        cin >> input;

        switch (input) {
            case 1:
                cout << "\nAmount: ";
                cin >> input;
                usersList[user_index].checking_funds += input;
                cout << "\n**** Balance after deposit: " << usersList[user_index].checking_funds << " ****";

                break;
            case 2:
                cout << "\nAmount: ";
                cin >> input;
                usersList[user_index].savings_funds += input;
                cout << "\n**** Balance after deposit: " << usersList[user_index].savings_funds << " ****";

                break;
        }
    }

}

void NewAccount::WithdrawFunds(){

    AccountAccess();

    if(access_granted) {
        cout << "\nPlease select in which account you want to withdraw: ";
        cout << "\n\n1. CHECKING ACCOUNT";
        cout << "\n\n2. SAVINGS ACCOUNT";
        cout << "\n\nOPTION: \n";

        cin >> input;

        switch (input) {
            case 1:
                cout << "\nAmount: ";
                cin >> input;
                usersList[user_index].checking_funds -= input;
                cout << "\n**** Balance after withdraw: " << usersList[user_index].checking_funds << " ****";

                break;
            case 2:
                cout << "\nAmount: ";
                cin >> input;
                usersList[user_index].savings_funds -= input;
                cout << "\n**** Balance after withdraw: " << usersList[user_index].savings_funds << " ****";

                break;
        }
    }

}

void NewAccount::CloseAccount(){

    AccountAccess();
    if(access_granted){
        vector<userInfo>::iterator position;
        position = usersList.begin() + user_index;

        usersList.erase(position);
    }

}

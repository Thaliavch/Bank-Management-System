#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Constants declaration
const int MIN_PASSWORD_LENGTH = 8;
const int MAX_PASSWORD_LENGTH = 50;
const long long int FIRST_ACCOUNT_NUMBER = 10000;
const int MAX_PASSWORD_VERIFICATION_ATTEMPTS = 8;

// enums for user inputs, used later in the switch statements.
enum UserInput {
    CreateAccount = 1,
    EditAccount,
    CheckBalance,
    AccountInformation,
    DepositFunds,
    WithdrawFunds,
    CloseAccount,
    ExitProgram

};


// Class declaration start here.
class NewAccount {
    // Private variables

    static int account_index;  // static variable to register the numbers of calls of createNewAccount, and use in the incrementation/initalization of costumers account #

    // global variables used in the class
    string psw;
    int user_index;
    int accNum;
    int input;
    bool access_granted;
    bool acc_found;

    // structure type userInfo to declare and store costumer's information
    struct userInfo {
        string holder_name;
        string holder_last_name;
        int account_number;
        string password;
        int savings_funds;
        int checking_funds;
    };
    // vector "usersList"(identifier)  of type "userInfo"(user defined data type --> dfined above ^) 
    vector<userInfo>usersList;

    // methods declarations and definitions
public:

    void CreateAccount() {
        userInfo info; // Creating a vector of structure UserInfo called info for stroiing every accounts information

        // store the users account number
        info.account_number = FIRST_ACCOUNT_NUMBER + account_index; 
        account_index++; // update the account index for the next account number

        // Ask the user for their name and valid password
        cout << "Please enter the costumer's first name:       ";
        cin >> info.holder_name;

        cout << "Please enter the costumer's last name:        ";
        cin >> info.holder_last_name;

        cout << "Please enter a password of at least 8 digits: ";
        cin >> psw;
        while (psw.length() < MIN_PASSWORD_LENGTH|| psw.length() > MAX_PASSWORD_LENGTH ) {
            cout << "The password must have at least 8 digits and no more than 50 digits \n Please try again: ";
            cin >> psw;
        }
        info.password = psw;

        /* When crreating a new account, the user must desposit money into a checking account and a savings account.
          Here we are asking the user to enter how much they want to depsoit for the checking and savings account */

        cout << "Amount to deposit in checking account:        ";
        cin >> info.checking_funds;

        cout << "Amount to deposit in savings account:         ";
        cin >> info.savings_funds;

        cout << "\n**********************************************************",
            cout << "\nCongratulations! Your account has been successfully created";
        cout << "\n\n\t\tYour account number is: " << info.account_number;
        cout << "\n**********************************************************";

        //push the important info for the account to the array of usersList
        usersList.push_back(info);


    }

    void AccountAccess() { // Needed for accessing the users accounts information for any transactions it goes through or 
        // if the user wants to change their password or account number

        // Ask the user for their account number
        cout << "\nPlease enter your account number: ";
        cin >> accNum;

        
        do {
            for (int i = 0; i < account_index; i++) { // Iterate over all the account indexes
                if (accNum == usersList[i].account_number) { // If the accoutn num if found in the account number stored fro that partiuclar element
                    // Set the user_index to i and the users account has now been found
                    user_index = i;
                    acc_found = true;
                }
                else { // There was no match for the account number when iterating over the account indexes
                    // account is found
                    acc_found = false;
                }
            }if (!acc_found) {
                // Prompt the user to enter theier account number again
                cout << "\nAccount not found. Please try again";
                cout << "\nAccount number: ";
                cin >> accNum;
            }

        } while (!acc_found);


        // Propting the user for the password
        cout << "\nEnter password: ";
        cin >> psw;

        for (int i = 1; i < (MAX_PASSWORD_VERIFICATION_ATTEMPTS + 1); i++) // We have to go to the users file to retrieve his/her password and compare it to the user's input
        {                          // I am using the for loop to give him 8 attempts to enter the correct password.

            if (psw != usersList[user_index].password) {
                if (i == MAX_PASSWORD_VERIFICATION_ATTEMPTS) {
                    cout << "This was your last try. This account will be temporary restricted.";
                    access_granted = false;
                }
                else { // The password is not found in our array of structures
                    cout << "Wrong password. You have " << MAX_PASSWORD_VERIFICATION_ATTEMPTS - i
                        << " attempts left. Please try again: ";
                    cin >> psw;
                }
            }
            else {
                access_granted = true;
                break;
            }
        }

    };

    void EditAccount() {

        AccountAccess(); // Check the users accounts credentials first
        if (access_granted) { // If the user enters the proper credentials
            do {
                // Display options to edit their account below and get their input
                cout << "\nPlease select an option below";
                cout << "\n\n1. ACCOUNT NUMBER";
                cout << "\n\n2. PASSWORD";
                cout << "\n\n3. EXIT EDITOR";
                cout << "\n\nOPTION: \n";

                cin >> input;

                switch (input) {

                case 1: // Account number
                    cout << "\nEnter new account number: "; // add check to avoid repetition of account numbers later
                    cin >> usersList[user_index].account_number;
                    break;
                case 2: // Password 
                    cout << "\nEnter new password      : ";
                    cin >> usersList[user_index].password;
                    break;
                case 3: // Exit editor
                    cout << "\nExiting editor...\n";
                    break;
                default: // The user does not type the correct input
                    cout << "\nIncorrect input. Try again.\n";

                };

            } while (input != 3); // While the user does not want to exit the editor
        }
    }


    void CheckBalance() { // Displays the current balance the user has in thier savings and checking account

        AccountAccess(); // FIrst they must have the proper credentials

        if (access_granted) { // If they enter the correct credentials stored in the system
            // Display the options for what account they would like to see (Checking or savings) amd get their input
            cout << "\nPlease select an option below";
            cout << "\n\n1. CHECKING ACCOUNT";
            cout << "\n\n2. SAVINGS ACCOUNT";
            cout << "\n\nOPTION: \n";

            cin >> input;

            switch (input) {
            case 1: // Checking account
                cout << "\nBalance: " << usersList[user_index].checking_funds;
                break;
            case 2: // Savings account
                cout << "\nBalance: " << usersList[user_index].savings_funds;
                break;
            }
        }
    }

    void DisplayInformation() { // Display's the account info to the user

        AccountAccess(); // First we must check the user's credentials to display their info

        if (access_granted) { // If the user entered the right credentials stored in the system

            // Display their accoutn information(User's name, account number, and balance for both checking and savings)
            cout << user_index;
            cout << "User:                     " << usersList[user_index].holder_name << usersList[user_index].holder_last_name << endl;
            cout << "Account Number:           " << usersList[user_index].account_number << endl;
            cout << "Savings Account Balance:  " << usersList[user_index].savings_funds << endl;
            cout << "Checking Account Balance: " << usersList[user_index].checking_funds << endl;

        }
    }

    void DepositFunds() { // Deposits the funds

        AccountAccess();

        if (access_granted) {
            // Displaying the options and getting use input for what account they want to deposit their money in
            cout << "\nPlease select in which account you want to deposit: ";
            cout << "\n\n1. CHECKING ACCOUNT";
            cout << "\n\n2. SAVINGS ACCOUNT";
            cout << "\n\nOPTION: \n";

            cin >> input;

            switch (input) {
            case 1: // Checking Account
                cout << "\nAmount: ";
                cin >> input;
                usersList[user_index].checking_funds += input; // Add to the orginal money stored in the system (CHecking acount)
                cout << "\n**** Balance after deposit: " << usersList[user_index].checking_funds << " ****";

                break;
            case 2: // SavingAccount
                cout << "\nAmount: ";
                cin >> input;
                usersList[user_index].savings_funds += input; // Add to the orginal money stored in the system (Savings acount)
                cout << "\n**** Balance after deposit: " << usersList[user_index].savings_funds << " ****";

                break;
            }
        }
    }

    void WithdrawFunds() {

        AccountAccess(); // Ask the user for their password and account number

        if (access_granted) { // If the user enter a valid password and account number he can now withdraw funds
            // Displaying the options for which the user can pick which account they want to withdrwa their moeny from

            cout << "\nPlease select in which account you want to withdraw: ";
            cout << "\n\n1. CHECKING ACCOUNT";
            cout << "\n\n2. SAVINGS ACCOUNT";
            cout << "\n\nOPTION: \n";

            cin >> input;

            switch (input) {
            case 1: // Checking Account

                // Get input for the amount to withdraw
                cout << "\nAmount: ";
                cin >> input;
                usersList[user_index].checking_funds -= input; // Subtarct the input the user entered from the current amount in their checking account
                cout << "\n**** Balance after withdraw: " << usersList[user_index].checking_funds << " ****";

                break;
            case 2: // Savings Account

                // Get input for the amount to withdraw
                cout << "\nAmount: ";
                cin >> input;
                usersList[user_index].savings_funds -= input; // subtract the input the user entered from the current amount in their savings account
                cout << "\n**** Balance after withdraw: " << usersList[user_index].savings_funds << " ****";

                break;
            }
        }
    }

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   
   // Close account method goes here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void CloseAccount() {

        AccountAccess();
        if (access_granted) {

            // Close account definition goes here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            // It is important that the definition goes here inside the if-statement.


        }

    }// end of CloseAccount


}; // end of class NewAccount

int NewAccount::account_index = 0; // Initalize the account_index to 0 at the start of the program

int main() {
    
    int userInput; // For the user to input the option they want to choose

    NewAccount user; 

    // Main Title of the program and greeting
    cout << "*********************************************";
    cout << "   BANK MANAGEMENT SYSTEM   ";
    cout << "*********************************************" << endl;
    cout << "Welcome to your Bank Management System. ";

    do {
        // Display options to the user and get the option to user wants to pick
        cout << "\n\nPlease select an option below";
        cout << "\n\n1. CREATE NEW ACCOUNT";
        cout << "\n\n2. EDIT AN ACCOUNT";
        cout << "\n\n3. CHECK ACCOUNT BALANCE";
        cout << "\n\n4. DISPLAY ACCOUNT INFORMATION";
        cout << "\n\n5. DEPOSIT FUNDS";
        cout << "\n\n6. WITHDRAW FUNDS";
        cout << "\n\n7. CLOSE ACCOUNT";
        cout << "\n\n8. EXIT FROM PROGRAM";
        cout << "\n\nOPTION: ";
        cin >> userInput;

        switch (userInput) {

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

            break;
        case ExitProgram:
            cout << "Thank you for using our Bank Management System.";
            break;

        default: // The user enters a number outside the range of options
            cout << "Incorrect input. Try again.";

        };

    } while (userInput != 8); // Whule the user does not want to exit the program


    return 0;
}


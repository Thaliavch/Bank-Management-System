#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

// Constants declaration
const int MIN_PASSWORD_LENGTH = 5;
const int MAX_PASSWORD_LENGTH = 50;
const long long int FIRST_ACCOUNT_NUMBER = 10000;
const int MAX_PASSWORD_VERIFICATION_ATTEMPTS = 8;
const int SLEEPTIME = 4000;

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


class MenuAndTitles {

public: // Methods for displaying any options the user clicked on and the main menu

    void DisplayMainMenu() {

        cout << "**********************************************************************";
        cout << "   BANK MANAGEMENT SYSTEM   ";
        cout << "************************************************************************" << endl;
        cout << "\n";
        cout << "\n";
        cout << "\n";

        cout << "\t\t\t\t\t\t\t\tWelcome to your Bank Management System. ";

        cout << "\n";

        cout << "\n\n\t\t\t\t\t\t\t\tPlease select an option below";
        cout << "\n\n\t\t\t\t\t\t\t\t1. CREATE NEW ACCOUNT";
        cout << "\n\n\t\t\t\t\t\t\t\t2. EDIT AN ACCOUNT";
        cout << "\n\n\t\t\t\t\t\t\t\t3. CHECK ACCOUNT BALANCE";
        cout << "\n\n\t\t\t\t\t\t\t\t4. DISPLAY ACCOUNT INFORMATION";
        cout << "\n\n\t\t\t\t\t\t\t\t5. DEPOSIT FUNDS";
        cout << "\n\n\t\t\t\t\t\t\t\t6. WITHDRAW FUNDS";
        cout << "\n\n\t\t\t\t\t\t\t\t7. CLOSE ACCOUNT";
        cout << "\n\n\t\t\t\t\t\t\t\t8. EXIT FROM PROGRAM";
        cout << "\n\n\t\t\t\t\t\t\t\tOPTION: ";
    }

    void DisplayCreateAccoutTitle() {

        cout << "**********************************************************************";
        cout << "   CREATE ACCOUNT   ";
        cout << "************************************************************************" << endl;

        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
    }

    void DisplayEditAccountTitle() {
        cout << "**********************************************************************";
        cout << "   EDIT ACCOUNT   ";
        cout << "************************************************************************" << endl;

        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
    }

    void DisplayCheckBalanceTitle() {
        cout << "**********************************************************************";
        cout << "   CHECK BALANCE   ";
        cout << "************************************************************************" << endl;

    }

    void DisplayDepositFundsTitle() {

        cout << "**********************************************************************";
        cout << "   DEPOSIT FUNDS   ";
        cout << "************************************************************************" << endl;

        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
    }

    void DisplayWithdrawFundsTitle() {

        cout << "**********************************************************************";
        cout << "   WITHDRAW FUNDS   ";
        cout << "**********************************************************************";

        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
    }

    void DisplayAccountInfoTitle() {

        cout << "**********************************************************************";
        cout << "   ACCOUNT INFOMRATION   ";
        cout << "**********************************************************************";

        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
    }

    void DisplayCloseAccountTitle() {

        cout << "**********************************************************************";
        cout << "   CLOSE ACCOUNT   ";
        cout << "**********************************************************************";

        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";

    }

    void DisplayAccessGrantedOptions() {

        cout << "\n\t\t\t\t\tPlease select an option below";
        cout << "\n\n\t\t\t\t\t1. NAME";
        cout << "\n\n\t\t\t\t\t2. PASSWORD";
        cout << "\n\n\t\t\t\t\t3. EXIT EDITOR";

    }

    void DisplayCheckBalanceOptions() {

        cout << "\n\t\t\t\t\tPlease select an option below";
        cout << "\n\n\t\t\t\t\t1. CHECKING ACCOUNT";
        cout << "\n\n\t\t\t\t\t2. SAVINGS ACCOUNT";

    }

    void DisplayWitdrawOPtions() {

        cout << "\n\t\t\t\t\tPlease select in which account you want to withdraw: ";
        cout << "\n\n\t\t\t\t\t1. CHECKING ACCOUNT";
        cout << "\n\n\t\t\t\t\t2. SAVINGS ACCOUNT";

    }

};


// Class declaration start here.
class NewAccount : public MenuAndTitles {

private: // Private memebers of this class

    static int account_index;  // static variable to register the numbers of calls of createNewAccount, and use in the incrementation/initalization of costumers account #

    // global variables used in the class
    // 
    // Important Account info  
    string psw;
    int user_index{0};
    int accNum{0};
    int input{0};
    bool access_granted{0};
    bool acc_found{0};
    bool accountcreated{0};
    bool acc_open{0};

    // Balance transactions for the account
    int deposit_amount_checking{0};
    int deposit_amount_savings{0};
    int withdraw_amount_checking{0};
    int withdraw_amount_savings{0};

    // structure type userInfo to declare and store costumer's information

    struct userInfo {
        int account_number{0};
        string holder_name;
        string holder_last_name;
        string password;
        int savings_funds{0};
        int checking_funds{0};
    };

    // vector "usersList"(identifier)  of type "userInfo"(user defined data type --> dfined above ^) 
    vector<userInfo>usersList;
    


public:  // methods declarations and definitions

 
    int GetValidInput() { // Gets valid input for any strange excpetions thrown to the program and return an integer

        int number{0};

        cin >> number;

        while (!cin.good() || number <= 0) { // While the user does not give a valid input or the number is less than 0 (for deposits and withdraws)

            // Display error
            cout << "\t\t\t\t\t\Incorrect Input. Please try again" << endl;

            cin.clear();
            cin.ignore(INT_MAX, '\n');

            // Get the input again

            cin >> number;
        }

        return number;
    }

    bool AccountExists() { // Method to check if there is account stored in the system

        if (accountcreated)
            return true;
        else
            return false;
    }

    void CreateAccount() {

        DisplayCreateAccoutTitle();

        userInfo info;

        info.account_number = FIRST_ACCOUNT_NUMBER + account_index; // Creating an account number for the user

        account_index++; // Incrementing the account index for the next user

        // Getting basic new customers information (first name, last name, new password they want to create)
        cout << "Please enter the costumer's first name:"; 
        cin >> info.holder_name;

        cout << "Please enter the costumer's last name:";
        cin >> info.holder_last_name;

        do {
            // Ask for a new password from the user
            cout << "Please enter a password of at least " << MIN_PASSWORD_LENGTH << " digits:";
            cin >> psw;

            if(psw.length()< MIN_PASSWORD_LENGTH || psw.length() > MAX_PASSWORD_LENGTH) // If the password does meet the requirement length
                cout << "The password must have at least 8 digits and no more than 50 digits \n Please try again: ";

        } while (psw.length() < MIN_PASSWORD_LENGTH || psw.length() > MAX_PASSWORD_LENGTH); // The password does not meet the length requirements
           
        // store the psw the user created 
        info.password = psw;

        /* When crreating a new account, the user must desposit money into a checking account and a savings account.
           Here we are asking the user to enter how much they want to depsoit for the checking and savings account */


          // Ask the user to enter a desposit for the checking and savings account. Then setting the checking and savings
          // account 
          cout << "Amount to deposit in CHECKING account:";
          info.checking_funds = GetValidInput();

          cout << "Amount to deposit in SAVINGS account:";
          info.savings_funds = GetValidInput();


        // Display that they successfully created their account and show them their account number
         cout << "\n**********************************************************",
         cout << "\n""Congratulations!" << info.holder_name << " " << info.holder_last_name << ".Your account has been successfully created!";
         cout << "\n\n\t\tYour account number is: " << info.account_number; 
         cout << "\n**********************************************************";

         accountcreated = true;

        // Store the information we asked from the user

        usersList.push_back(info);

    }

   
    void AccountAccess() { // Needed for verfiying the user to do anything with their account in the system
        
        // Getting valid input for the account number
        cout << "\nPlease enter your account number: ";
        accNum = GetValidInput();
      
        do {
            for (int i = 0; i < account_index; i++) { // Iterate through all the account indexes in userList vector
                if (accNum == usersList[i].account_number) { // If the accNUm is found in our userList vector (This logic is a bit complicated though lol)

                    user_index = i; // We will look at that vector index with that person's info.
                    acc_found = true;
                    break;
                }
                else { // The account number is not stored in the vector
                    acc_found = false;
                }
            }if (!acc_found) { // If the account has not been found but the user still has attempts to enter the account number
                // Display that we could not find the account number and ask them again
                cout << "\nAccount not found. Please try again";
                cout << "\nAccount number: ";
                accNum = GetValidInput();
            }

        } while (!acc_found);


        cout << "\nEnter password: ";
        cin >> psw;

        for (int i = 1; i < (MAX_PASSWORD_VERIFICATION_ATTEMPTS + 1); i++) // We have to go to the users file to retrieve his/her password and compare it to the user's input
        {                          // I am using the for loop to give him 8 attempts to enter the correct password.

            if (psw != usersList[user_index].password) { // If the password is not found in Userslist
                if (i == MAX_PASSWORD_VERIFICATION_ATTEMPTS) { // If the user has already used up all their attempts
                    cout << "This was your last try. This account will be temporary restricted.";
                    access_granted = false; // deny them access to the account and the for lopp stops
                }
                else { // The user types a wrong psw found in the system, but still has attempts left
                    cout << "Wrong password. You have " << MAX_PASSWORD_VERIFICATION_ATTEMPTS - i
                        << " attempts left. Please try again: ";
                    // Ask the user for their psw again
                    cin >> psw;
                }
            }
            else { // The user provides a valid password found in the system

                // The for loop stops and the user can access their account
                access_granted = true;
                break;
            }
        }
    }

    void EditAccount() {

        DisplayEditAccountTitle();

        AccountAccess();

        if (access_granted) { // If the user has entered their correct previous username and password

            do {
                // Display the options for the user wants to edit

                DisplayAccessGrantedOptions();

                // Get a valid option from the user
                cout << "\n\nOPTION:";
                input = GetValidInput();
                
              
                switch (input) {

                case 1:
                    cout << "\nEnter new first name: "; // add check to avoid repetition of account numbers later (COME BACK TO). CHanged it to name instead(easier)
                    cin >> usersList[user_index].holder_name;

                    cout << "\nEnter new last name: "; 
                    cin >> usersList[user_index].holder_last_name;

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

            } while (input != 3);
        }
    }


    void CheckBalance() {

        DisplayCheckBalanceTitle();

        AccountAccess();

        if (access_granted) {
            DisplayCheckBalanceOptions();

            // Get a valid input for the options displayed above
            do {
                cout << "\n\nOPTION:";
                input = GetValidInput();
            } while (input != 1 && input != 2);

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

    void DisplayInformation() { // Displays USER NAME, ACCOUNT NUMBER, and balance in their savings and checking account
        DisplayAccountInfoTitle();

        AccountAccess();

        if (access_granted) {
            cout << user_index;
            cout << "\t\t\t\t\tUSER:                     " << usersList[user_index].holder_name << " " << usersList[user_index].holder_last_name << endl;
            cout << "\t\t\t\t\tACCOUNT NUMBER:           " << usersList[user_index].account_number << endl;
            cout << "\t\t\t\t\tSAVINGS ACCOUNT BALANCE:  " << usersList[user_index].savings_funds << endl;
            cout << "\t\t\t\t\tCHECKING ACCOUNT BALANCE: " << usersList[user_index].checking_funds << endl;

        }
    }


    void DepositFunds() {

        DisplayDepositFundsTitle();

        AccountAccess();

        if (access_granted) {

            DisplayCheckBalanceOptions();

            // Get a valid option input
            do {
                cout << "\n\nOPTION:";
                input = GetValidInput();

            } while (input != 1 && input != 2);

            switch (input) {

            case 1: // The user wants to deposit to the checking account
                cout << "Enter amount to deposit in checking account:";
                deposit_amount_checking = GetValidInput();

                usersList[user_index].checking_funds += deposit_amount_checking; 

                cout << "\n**** Balance after deposit: " << usersList[user_index].checking_funds << " ****";

                break;

            case 2: // The user wants to deposit to the savings account
                cout << "Enter amount to deposit in savings account:";
                deposit_amount_savings = GetValidInput();

                usersList[user_index].savings_funds += deposit_amount_savings;
                cout << "\n**** Balance after deposit: " << usersList[user_index].savings_funds << " ****";

                break;
            }
        }
    }

    void WithdrawFunds() {

        DisplayWithdrawFundsTitle();

        AccountAccess();

        if (access_granted) {

            DisplayWitdrawOPtions();
            // Get a valid option input
            do {
                cout << "\n\nOPTION:";
                input = GetValidInput();

            } while (input != 1 && input != 2);

            switch (input) {
            case 1: // The user wants to withdraw from the checking account

                // Ask the user for a valid withdraw amount in the savings account
                do {
                    cout << "\nAmount: ";
                    withdraw_amount_checking = GetValidInput();

                    if (withdraw_amount_checking > usersList[user_index].checking_funds) // If the user wants to withdraw more than what he has in thier bank account display that they cannot do that and ask them again
                        cout << "You cannot take out more than what you have in your checking account. Please try again." << endl;

                } while (withdraw_amount_checking > usersList[user_index].checking_funds);

                // Take out the money the user wanted out in the checking account and display their new balance 

                usersList[user_index].checking_funds -= withdraw_amount_checking;

                cout << "\n**** Balance after withdraw: " << usersList[user_index].checking_funds << " ****";

                break;

            case 2: // The user wants to withdraw from the savings account

                // Ask the user for a valid withdraw amount in the checking account
                do {
                    cout << "\nAmount: ";
                    withdraw_amount_savings = GetValidInput();

                    if (withdraw_amount_savings > usersList[user_index].savings_funds) // If the user wants to withdraw more than what they have in their savings account
                        cout << "You cannot take out more than what you have in your savings account. Please try again." << endl;

                } while (withdraw_amount_savings > usersList[user_index].savings_funds);

                // Take out the money the user wanted out in the savings account and display their new balance
                usersList[user_index].savings_funds -= withdraw_amount_savings;

                cout << "\n**** Balance after withdraw: " << usersList[user_index].savings_funds << " ****";

                break;
            }
        }
    }

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   
   // Close account method goes here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void CloseAccount() {
        DisplayCloseAccountTitle();

        AccountAccess();
        //Erases the vector where we stored all the users information
        if (access_granted) {

           vector<userInfo>::iterator it1;
           it1 = usersList.begin() + user_index;
           //it2 = usersList.end();


            usersList.erase(it1);

            cout << "Your account has been closed. Redirecting you to the main menu" << endl;

            account_index = account_index - 1; // An element from our vector of strcutures has been deleted so we have to subtarct 1 from the account index


            if(usersList.empty()) // If there is no more account info for anybody in our vector
                accountcreated = false; // There is no account created in the system 

            // Close account definition goes here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            // It is important that the definition goes here inside the if-statement.


        }

    }// end of CloseAccount


}; // end of class NewAccount
int NewAccount::account_index = 0;



int main() {
    int userInput{0};
    NewAccount user;
   
    do {
        // Display the main menu to the user
        user.DisplayMainMenu();

        // Getting a valid number from the user
        userInput = user.GetValidInput();

        switch (userInput) {

        case CreateAccount:
            system("CLS"); // Used to clear the screen
            user.CreateAccount();

            Sleep(SLEEPTIME);
            system("CLS");

            break;

        // For each option below we must check if there is an account that exists in the system or not
        case EditAccount:
            system("CLS");
            if (user.AccountExists())
                user.EditAccount();
            else
                cout << "There are no accounts in our system at the moment. You will be redirected" << endl;

            Sleep(SLEEPTIME);

            system("CLS");

            break;
        case CheckBalance:
            system("CLS");

            if (user.AccountExists())
                user.CheckBalance();
            else
                cout << "There are no accounts in our system at the moment. You will be redirected" << endl;

            Sleep(SLEEPTIME);

            system("CLS");

            break;

        case AccountInformation:
            system("CLS");
            if (user.AccountExists())
                user.DisplayInformation();
            else
                cout << "There are no accounts in our system at the moment. You will be redirected" << endl;
            Sleep(SLEEPTIME);

            system("CLS");

            break;

        case DepositFunds:
            system("CLS");
            if (user.AccountExists())
                user.DepositFunds();
            else
                cout << "There are no accounts in our system at the moment. You will be redirected" << endl;

            Sleep(SLEEPTIME);

            system("CLS");

            break;

        case WithdrawFunds:
            system("CLS");
            if (user.AccountExists())
                user.WithdrawFunds();
            else
                cout << "There are no accounts in our system at the moment. You will be redirected" << endl;
            Sleep(SLEEPTIME);

            system("CLS");

            break;

        case CloseAccount:
            system("CLS");

            if (user.AccountExists())
                user.CloseAccount();
            else
                cout << "There are no accounts in our system at the moment. You will be redirected" << endl;

            Sleep(SLEEPTIME);

            system("CLS");
            break;

        case ExitProgram:
            cout << "\t\t\t\t\tThank you for using our Bank Management System.";
      
            break;

        default: // Enter a number outside the range of options
            system("CLS");
            cout << "Incorrect input. Try again.";
            
            Sleep(SLEEPTIME);
            system("CLS");
        };

    } while (userInput != 8);


    return 0;

}

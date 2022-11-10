#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

// Constants declaration

const int MIN_PASSWORD_LENGTH = 8;
const int MIN_USERNAME_LENGTH = 8;
const int MAX_PASSWORD_VERIFICATION_ATTEMPTS = 8; // constant used for verifications like to check password
const int MAX_NUMBER_OF_ATTEMPTS = 5;
const int SLEEP = 1500;
long long int ACCOUNT_NUMBER = 10000;




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

// Starting of project
class Menu {
public:
    void DisplayOptions() {

        // Title
        cout << "*********************************************";
        cout << "   BANK MANAGEMENT SYSTEM   ";
        cout << "*********************************************" << endl;

        cout << "\n";

        // Greeting
        cout << "\t\t\t\t\tWELCOME TO YOUR BANK MANAGEMENT SYSTEM. ";

        cout << "\n";

        // Options
        cout << "\n\t\t\t\t\t\tPlease select an option below:";
        cout << "\n\n\t\t\t\t\t1. CREATE NEW ACCOUNT";
        cout << "\n\n\t\t\t\t\t2. EDIT AN ACCOUNT";
        cout << "\n\n\t\t\t\t\t3. CHECK ACCOUNT BALANCE";
        cout << "\n\n\t\t\t\t\t4. DISPLAY ACCOUNT INFORMATION";
        cout << "\n\n\t\t\t\t\t5. DEPOSIT FUNDS";
        cout << "\n\n\t\t\t\t\t6. WITHDRAW FUNDS";
        cout << "\n\n\t\t\t\t\t7. CLOSE ACCOUNT";
        cout << "\n\n\t\t\t\t\t8. EXIT FROM PROGRAM";
        cout << "\n\n\t\t\t\t\tOPTION: ";
    }
};

class Bank {

private: // private variables for an account
    string username;
    string password;
    double checking;

public:
    bool UsernameCreated = false;
    bool PasswordCreated = false;

    string new_user_name;
    string new_password;

    ofstream AccountFile;

    void PrintCreateAccountMenu() {
        cout << "*********************************************";
        cout << "   CREATE AN ACCOUNT   ";
        cout << "*********************************************" << endl;

        cout << "\n\n\n\n\n\n\n";
    }


    // Get a valid username method
    void CreateAndSetValidUsername() {
        do {
            cout << "\t\t\t\t\t"; // Centering the text prompoted

            cout << "Enter your new USERNAME:";
            cin >> new_user_name;

            if (new_user_name.length() < MIN_USERNAME_LENGTH) { // User does not enter valid username length for username
                cout << "\t\t\t\t";
                cout << new_user_name << " only has " << new_user_name.length() << " letters. The minium required is " << MIN_USERNAME_LENGTH << endl;
            }

            else { // User enters a valid username
                cout << "\t\t\t\t\t";
                cout << "Your new USERNAME will be: " << new_user_name << endl;
                this->username = new_user_name;
                UsernameCreated = true;
            }

        } while (new_user_name.length() < MIN_USERNAME_LENGTH);

    }

    void WriteAccountToDatabase() {

        AccountFile.open("AccountInfo.txt", ios::app); // Append account info to the file "AccountInfo.txt"

        if (AccountFile.is_open()) { // If the file is open
            AccountFile << password;  // Write the password to the file
            AccountFile << username;  // Write the username to the file
            AccountFile.close();
        }
    }


  
    //Get and set a valid password method

    void CreateAndSetValidPassword() {
        do {
            cout << "\t\t\t\t\t"; // Centering the text prompted

            cout << "Enter your new PASSWORD:";
            cin >> new_password;

            if (new_password.length() < MIN_PASSWORD_LENGTH) { // User does not enter valid username for password
                cout << "\t\t\t\t\t";
                cout << new_password << "only has " << new_password.length() << " letters. The minimum required is " << MIN_PASSWORD_LENGTH << endl;
            }

            else { // User enters a valid password
                cout << "\t\t\t\t\t";
                cout << "Your new PASSWORD will be: " << new_password << endl;
                this->password = new_password;
                PasswordCreated = true;
            }
        } while (new_password.length() < MIN_PASSWORD_LENGTH);
    }

    void DisplayAccountNumber() {
        cout << "\t\t\t\t\t";
        cout << "Your ACCOUNT NUMBER IS: " << ACCOUNT_NUMBER << endl;
    }

    void UpdateAccountNumber() { ACCOUNT_NUMBER++; }

    bool AccountExists() {
        bool AccountExists = false;

        if (UsernameCreated && PasswordCreated)
            AccountExists = true;

        return AccountExists;   
    }
  

    // Edit an account

    void PrintEditAccountMenu() {

        cout << "***********************************************************EDIT ACCOUNT**************************************************" << endl;
    }

    void EditAnAccount() {
        //Components needed to verify an account

        string password_to_verify;
        string username_to_verify;
        string option_to_change;

        int numberofattempts = 0;

        // Getting the previous account info from the user (Username and password)

        do {
            cout << "Enter your previous password: ";
            cin >> username_to_verify;

            cout << "Enter your previous username: ";
            cin >> password_to_verify;

            if (password_to_verify == password && username_to_verify == username) { // If the password the user gives is the same as stored in the system
                cout << "Success!" << endl;
                cout << "What would you like to change?" << endl;
               
                cout << "Type PASSWORD for password. Type USERNAME for username. Type BOTH for username and password" << endl;

                cin >> option_to_change;

                if (option_to_change == "PASSWORD")
                    CreateAndSetValidPassword();

                else if (option_to_change == "USERNAME")
                    CreateAndSetValidUsername();

                else if (option_to_change == "BOTH") {
                    CreateAndSetValidPassword();
                    CreateAndSetValidUsername();
                }
            }

            else
                cout << "Not valid. Try again." << endl;

            numberofattempts++;

            if (numberofattempts == MAX_NUMBER_OF_ATTEMPTS)
                cout << "MAX number of attempts used. You will be redirected to the home screen." << endl;

        } while (!(password_to_verify == password && username_to_verify == username) && (numberofattempts != MAX_NUMBER_OF_ATTEMPTS));

    }


    // Function for displaying user's information.
    void displayInfo() {
        string psw;
        string usn;
        cout << "Enter account username: ";
        cin >> usn;

        // Now we need to access his/her account information. I'll be able to do so once
        // we set a way to store users' information on the createAccount method.
        // Then I need ot write a check in case the username is wrong ( it is not registered so
        // an account with that username does not exist

        cout << "Enter password: ";
        cin >> psw;

        for (int i = 1; i < (MAX_PASSWORD_VERIFICATION_ATTEMPTS + 1); i++) // We have to go to the users file to retrieve his/her password and compare it to the user's input
        {                          // I am using the for loop to give him 8 attempts to enter the correct password.

            if (psw == password) {
                cout << "Display user's information." << endl;
                break;
            }
            else {
                if (i == MAX_PASSWORD_VERIFICATION_ATTEMPTS) {
                    cout << "This was your last try. This account will be temporary restricted.";
                }
                else {
                    cout << "Wrong password. You have " << MAX_PASSWORD_VERIFICATION_ATTEMPTS - i
                        << " attempts left. Please try again: ";
                    cin >> psw;
                }

            }
        }
    }// end of displayInfo()

    
    void SetAndDepositFunds(double n) { //deposits an amount "n" into account.
        checking += n;
    }
    void SetAndWithdrawFunds(double n) { //withdraws an amount "n" from account.
        checking -= n;
    }
    int GetBalance() { //returns new balance after deposit.
        return checking;
    }

};

int main() {
    //NewAccount user;

    // Objects start here

    Menu menu;
    Bank account;


    // Options

    int userInput;
    double userMoney;

    do {

        system("CLS");

        menu.DisplayOptions();

        // Get an option choice from the user
        cin >> userInput;

        switch (userInput) {

        case CreateAccount:
            system("CLS");
           
            account.PrintCreateAccountMenu();

            // Getting and displaying important Info to the user
            account.CreateAndSetValidPassword();
            account.CreateAndSetValidUsername();
            account.DisplayAccountNumber();

            // Storing and updating the info
            account.UpdateAccountNumber();
            account.WriteAccountToDatabase();

            Sleep(1500);

            break;

        case EditAccount:
            system("CLS");
            if (account.AccountExists()) {
                account.PrintEditAccountMenu();
                account.EditAnAccount();
            }
            else {
                cout << "\t\t\t\t";
                cout << "You do not have an account yet. You will be redirected." << endl;
            }
            Sleep(1500); // Sleep the program for the user to see

            break;

        case CheckBalance:
            system("CLS");

            break;

        case AccountInformation:
            system("CLS");
            account.displayInfo();

            break;

        case DepositFunds:
            system("CLS");
            cout << "enter amount you want to deposit into the account";
            cin >> userMoney;
            account.SetAndDepositFunds(userMoney);
            cout << "your new balance is" << account.GetBalance();

            break;

        case WithdrawFunds:
            system("CLS");
            cout << "Enter amount you want to withdraw from the account";
            cin >> userMoney;
            account.SetAndWithdrawFunds(userMoney);
            cout << "your new balance is" << account.GetBalance();

            break;
        case CloseAccount:
            system("CLS");

            break;

        case ExitProgram:
            cout << "Thank you for using our Bank Management System." << endl;
            break;

        default:
            cout << "Incorrect input. Try again." << endl;
            break;
        };

    } while (userInput != 8);


    return 0;

}

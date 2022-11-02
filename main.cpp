#include <iostream>
#include <windows.h>

using namespace std;

// Constants declaration

const int MIN_PASSWORD = 8;
const int MIN_USERNAME = 8;
const int MAX_PASSWORD_VERIFICATION_ATTEMPTS = 8; // constant used for verifications like to check password
const int MAX_NUMBER_OF_ATTEMPTS = 5;
const long long int FIRST_ACCOUNT_NUMBER = 10000;


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
class Menu{
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

    void PrintCreateAccountMenu() {
        cout << "*********************************************";
        cout << "   CREATE AN ACCOUNT   ";
        cout << "*********************************************" << endl;

        cout << "\n\n\n\n\n\n\n";
    }


    // Ger a valid username method
    void GetAndSetValidUserName() {

        //cout << "\t\t\t\t\t\t\tCREATE AN ACCOUNT" << endl
        string username;

        do {
            cout << "\t\t\t\t\t"; // Centering the text prompoted

            cout << "Enter your new USERNAME:";
            cin >> username;



            if (username.length() < MIN_USERNAME) { // User does not enter valid username lenght for username
                cout << username << " only has " << username.length() << " letters. The minium required is " << MIN_USERNAME << endl;
            }

            else { // User enters a valid username
                cout << "\t\t\t\t\t";
                cout << "Your new USERNAME will be: " << username << endl;
                this->username = username;
            }

        } while (username.length() < MIN_USERNAME);

    }



    //Get and set a valid password method

    void GetAndSetValidPassword() {
        string password;
        do {
            cout << "\t\t\t\t\t"; // Centering the text prompted

            cout << "Enter your new PASSWORD:";
            cin >> password;

            if (password.length() < MIN_PASSWORD) // User does not enter valid username for password
                cout << password << "only has " << password.length() << " letters. The minimum required is " << MIN_PASSWORD << endl;

            else { // User enters a valid password
                cout << "\t\t\t\t\t";
                cout << "Your new PASSWORD will be: " << password << endl;
                this->password = password;
            }

        } while (password.length() < MIN_PASSWORD);

    }


    // Edit an account

    void EditAnAccount() {
        //Components needed to verify an account

        string password_to_verify;
        string username_to_verify;

        // Getting the previous account info from the user (Username and password)
        cout << "Enter your previous password: ";
        cin >> username_to_verify;

        cout << "Enter your previous username: ";
        cin >> password_to_verify;


        if (password_to_verify == password) // If the password the user gives is the same as stored in the system
            cout << "Success" << endl;
        else
            cout << "Not valid" << endl;//placeholder

        if (username_to_verify == username) // If the username the user gives is the same as stored in the system
            cout << "Sucesss" << endl;
        else
            cout << "Not valid" << endl;
    }

    
    // Function for displaying user's information.
    void displayInfo(){
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

        for(int i = 1; i < (MAX_PASSWORD_VERIFICATION_ATTEMPTS + 1); i++) // We have to go to the users file to retrieve his/her password and compare it to the user's input
        {                          // I am using the for loop to give him 8 attempts to enter the correct password.

            if(psw == password){
                cout << "Display user's information." << endl;
                break;
            }else{
                if(i == MAX_PASSWORD_VERIFICATION_ATTEMPTS){
                    cout << "This was your last try. This account will be temporary restricted.";
                }else {
                    cout << "Wrong password. You have " << MAX_PASSWORD_VERIFICATION_ATTEMPTS - i
                         << " attempts left. Please try again: ";
                    cin >> psw;
                }

            }
        }
    }// end of displayInfo()


    void DepositFunds(double n){ //deposits an amount "n" into account.
        checking+=n;
    }
    void WithdrawFunds(double n){ //withdraws an amount "n" from account.
        checking-=n;
    }
    int returnBalance(){ //returns new balance after deposit.
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
                account.GetAndSetValidUserName();
                account.GetAndSetValidPassword();

                break;

            case EditAccount:
                system("CLS");

                account.EditAnAccount();
                Sleep(1000); // Sleep the program for the user to see

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
                cout<<"enter amount you want to deposit into the account";
                cin>>userMoney;
                account.DepositFunds( userMoney);
                cout<<"your new balance is"<< account.returnBalance();

                break;

            case WithdrawFunds:
                system("CLS");
                cout<<"enter amount you want to withdraw from the account";
                cin>> userMoney;
                account.WithdrawFunds(userMoney);
                cout<<"your new balance is"<< account.returnBalance();

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

    }while (userInput != 8);


    return 0;

}

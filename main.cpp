#include <iostream>
using namespace std;

// Constants declaration
const int MIN_PASSWORD = 8;
const long long int FIRST_ACCOUNT_NUMBER = 10000;

// enums for user inputs, used later in the switch statements.
enum UserInput{
    CreateAccount = 1,
    EditAccount,
    CheckBalance,
    AccountInformation,
    DepositFunds,
    WithdrawFunds,
    CloseAccount,
    ExitProgram

};

// Classes declarations start here.
class NewAccount{
    static int account_call;

    struct userInfo{
        string holder_name;
        int account_number;
        int password;
        int savings_funds;
        int checking_funds;
    };
    struct userInfo *usersList = new userInfo[account_call];
    userInfo info;

public:
    void CreateAccount(){
        info.account_number = FIRST_ACCOUNT_NUMBER + account_call;
        account_call++;


        cout<< "Please enter the costumer's name: ";
        cin >>  info.holder_name;

        cout << "Please enter a password of at least 8 digits: ";
        cin >> info.password;

        cout << "Amount to deposit in checking account: ";
        cin >> info.checking_funds;

        cout << "Amount to deposit in savings account: ";
        cin >> info.savings_funds;

        cout << "Congratulations. Your account has been created successfully. \n Your account number is: " << info.account_number;

        usersList[account_call] = {info.holder_name, info.account_number, info.password, info.savings_funds, info.checking_funds};



        cout << account_call;
    }
    void DisplayInformation(){
        int user_index;
        int accNum;
        cout << "Enter account number: ";
        cin >> accNum;

        for (int i = 0; i < account_call; i++){
            if (accNum == usersList[i].account_number){
                user_index = i;
            }
        }
        cout << user_index;
        /*?cout << "User Name: " << usersList[user_index].holder_name << endl;
        cout << "Account Number: " << usersList[user_index].account_number << endl;
        cout << "Savings Account Balance: " << usersList[user_index].savings_funds << endl;
        cout << "Checking Account Balance:" << usersList[user_index].checking_funds << endl;*/
    }

};

int NewAccount::account_call = 0;


int main() {
    int userInput;
    NewAccount user;

    cout << "*********************************************";
    cout << "   BANK MANAGEMENT SYSTEM   ";
    cout << "*********************************************" << endl;
    cout << "Welcome to your Bank Management System. ";

    do{
        cout << "\nPlease select an option below";
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

        switch(userInput){

            case CreateAccount:
                user.CreateAccount();

                break;
            case EditAccount:

                break;
            case CheckBalance:

                break;
            case AccountInformation:
                user.DisplayInformation();

                break;
            case DepositFunds:

                break;
            case WithdrawFunds:

                break;
            case CloseAccount:

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

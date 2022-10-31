#include <iostream>
using namespace std;

// Startted with the project
/* class Mwnu{
public:
    void DisplLyOptions(){
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
     bool CheckOption(){
     
     
     }
    
    }

}; */
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

#include "Account.h"

bool Account::Go_back() {
    return *go_to_menu_ptr;
}


void Account::EditAccount() {

    if (*access_granted_ptr) {
        do {
            cout << "\nPlease select an option below";
            cout << "\n\n1. HOLDER NAME";
            cout << "\n\n2. HOLDER LAST NAME";
            cout << "\n\n3. PASSWORD";
            cout << "\n\n4. E-MAIL";
            cout << "\n\n5. EXIT EDITOR";
            cout << "\n\nOPTION: ";
            cin >> *input_ptr;

            switch (*input_ptr) {
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
                cout << "\nEnter New E-mail        : ";
                cin >> usersList[*user_index_ptr].e_mail;
                break;
            case 5:
                cout << "\nExiting Editor...\n";
                break;
            default:
                cout << "\nIncorrect Input. Try Again.\n";

            };

        } while (*input_ptr != 5);
    }
}



void Account::CheckBalance() {

    if (*access_granted_ptr) {
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

void Account::DisplayInformation() {

    if (*access_granted_ptr) {
        cout << "User:                     " << usersList[*user_index_ptr].holder_name << usersList[*user_index_ptr].holder_last_name << endl;
        cout << "Account Number:           " << usersList[*user_index_ptr].account_number << endl;
        cout << "Account E-mail:           " << usersList[*user_index_ptr].e_mail << endl;
        cout << "Account Password:         " << usersList[*user_index_ptr].password << endl;
        cout << "Savings Account Balance:  " << usersList[*user_index_ptr].savings_funds << endl;
        cout << "Checking Account Balance: " << usersList[*user_index_ptr].checking_funds << endl;

    }
}

void Account::DepositFunds() {

    if (*access_granted_ptr) {
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

void Account::WithdrawFunds() {

    if (*access_granted_ptr) {
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

void Account::CloseAccount() {

    if (access_granted) {

        vector<userInfo>::iterator it1;
        it1 = usersList.begin() + user_index;


        usersList.erase(it1);

        cout << "Your account has been closed. Redirecting you to the main menu" << endl;




    }
}

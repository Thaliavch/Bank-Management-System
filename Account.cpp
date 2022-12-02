#include "Account.h"

/**
 * Goes back to the main menu of the bank managment system
 * Parm: None
 * Return: Void
 **/
bool Account::Go_back() {
    return *go_to_menu_ptr;
}

/**
 * Displays options for user to edit their account
 * Asks the user for input from the options displayed while the user does not exit the editor
 * User enters what ever option they selected
 *
 * @parm: None
 * @return: void
 * */
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
                cin >> users[*user_index_ptr].holder_name;
                break;
            case 2:
                cout << "\nEnter New Last Name: "; // add check to avoid repetition of account numbers later
                cin >> users[*user_index_ptr].holder_last_name;
                break;
            case 3:
                cout << "\nEnter New Password      : ";
                cin >> users[*user_index_ptr].password;
                break;
            case 4:
                cout << "\nEnter New E-mail        : ";
                cin >> users[*user_index_ptr].e_mail;
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


/**
 * First, Checks if the user is stored in the system
 * Then displays options as to what account they want to look at and gets the input from user
 * Displays either the balance in the checking account and the balance in the
 * savings account (depending on what option the user picks)
 * @parm: None
 * @return: void
 * */
void Account::CheckBalance() {

    if (*access_granted_ptr) {
        cout << "\nPlease select an option below";
        cout << "\n\n1. CHECKING ACCOUNT";
        cout << "\n\n2. SAVINGS ACCOUNT";
        cout << "\n\nOPTION: ";
        cin >> *input_ptr;

        switch (*input_ptr) {
        case 1:
            cout << "\nBalance: " << users[*user_index_ptr].checking_funds;
            break;
        case 2:
            cout << "\nBalance: " << users[*user_index_ptr].savings_funds;
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
 * - Email
 * - Balance in their savings account
 * - Balance in their checking account
 * @parm: None
 * @return: void
 * */
void Account::DisplayInformation() {

    if (*access_granted_ptr) {
        cout << "User:                     " << users[*user_index_ptr].holder_name << users[*user_index_ptr].holder_last_name << endl;
        cout << "Account Number:           " << users[*user_index_ptr].account_number << endl;
        cout << "Account E-mail:           " << users[*user_index_ptr].e_mail << endl;
        cout << "Account Password:         " << users[*user_index_ptr].password << endl;
        cout << "Savings Account Balance:  " << users[*user_index_ptr].savings_funds << endl;
        cout << "Checking Account Balance: " << users[*user_index_ptr].checking_funds << endl;

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
            users[*user_index_ptr].checking_funds += *input_ptr;
            cout << "\n**** New Balance: " << users[*user_index_ptr].checking_funds << " ****";
            break;
        case 2:
            cout << "\nAmount: ";
            cin >> *input_ptr;
            users[*user_index_ptr].savings_funds += *input_ptr;
            cout << "\n**** New Balance: " << users[*user_index_ptr].savings_funds << " ****";
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
            users[*user_index_ptr].checking_funds -= *input_ptr;
            cout << "\n**** New Balance: " << users[*user_index_ptr].checking_funds << " ****";

            break;
        case 2:
            cout << "\nAmount: ";
            cin >> *input_ptr;
            users[*user_index_ptr].savings_funds -= *input_ptr;
            cout << "\n**** New Balance: " << users[*user_index_ptr].savings_funds << " ****";

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
void Account::CloseAccount() {

    if (access_granted) {

        vector<userInfo>::iterator it1;
        it1 = users.begin() + user_index;


        users.erase(it1);

        cout << "Your account has been closed. Redirecting you to the main menu" << endl;




    }
}

void Account:: ClearAccounts() {
    delete& users; 
}

#pragma once
#include "Menu.h"
#include <iostream>
#include <vector>
using namespace std;

class NewAccount : public Menu {
    static int account_index;

protected:
    string psw;
    int user_index;
    int accNum;
    int input;
    bool access_granted;
    bool acc_found = false;
    bool go_to_menu = false;

    //Pointer to variables above;
    string* psw_ptr = &psw;
    int* user_index_ptr = &user_index;
    int* accNum_ptr = &accNum;
    int* input_ptr = &input;
    bool* access_granted_ptr = &access_granted;
    bool* acc_found_ptr = &acc_found;
    bool* go_to_menu_ptr = &go_to_menu;

    struct userInfo {
        string holder_name;
        string holder_last_name;
        int account_number;
        string password;
        string e_mail;
        int savings_funds;
        int checking_funds;
    };

    vector<userInfo> * users_ptr = new vector<userInfo>;// Cretae a pointer to a vector of userInfo;

    vector<userInfo>& users = *users_ptr; //Create a reference to the pointer (to perform easier operations)


public:
    void CreateAccount();
    void AccountAccess();
    bool Log_in();
    bool ValidTransaction(int number);


};

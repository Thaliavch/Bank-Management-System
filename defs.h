//
// Created by Thalia on 11/26/2022.
//

#ifndef MAIN_CPP_DEFS_H
#define MAIN_CPP_DEFS_H

// Constants declaration
const int MIN_PASSWORD = 8;
const int MAX_PASSWORD = 50;
const long long int FIRST_ACCOUNT_NUMBER = 10000;
const int MAX_PASSWORD_VERIFICATION_ATTEMPTS = 8;

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

#endif //MAIN_CPP_DEFS_H

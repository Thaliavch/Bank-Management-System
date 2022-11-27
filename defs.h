/* --------------------------------------------------------
 *    File: defs.h
 *  Author: Thalia Valle Chavez | David Bentazos | Sahbah Gonzales
 *   Class: COP 3003, CRN: 85147
 * Purpose: Bank Management System elements' definitions.
 * -------------------------------------------------------- */
#ifndef MAIN_CPP_DEFS_H
#define MAIN_CPP_DEFS_H


// Constants declaration
const int MIN_PASSWORD = 8;
const int MAX_PASSWORD = 50;
const long long int FIRST_ACCOUNT_NUMBER = 10000;
const int MAX_PASSWORD_VERIFICATION_ATTEMPTS = 8;
const int SLEEP_TIME = 2;
const int MENU_SLEEP_TIME = 0.5;



// Enums for user inputs, used later in the switch statements.
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

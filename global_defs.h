#pragma once
#include "Account.h"

// Constants declaration
const int MIN_PASSWORD = 8;
const int MAX_PASSWORD = 50;
const long long int FIRST_ACCOUNT_NUMBER = 10000;
const int MAX_PASSWORD_VERIFICATION_ATTEMPTS = 8;
const int SLEEP_TIME = 4000;




// Enums for user inputs, used later in the switch statements.
enum UserInput {
    EditAccount = 1,
    CheckBalance,
    AccountInformation,
    DepositFunds,
    WithdrawFunds,
    CloseAccount,
    SignOut
 
};

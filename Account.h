#include "Menu.h"
#include "NewAccount.h"

class Account : public NewAccount {

public:
    bool Go_back();
    void EditAccount();
    void CheckBalance();
    void DisplayInformation();
    void DepositFunds();
    void WithdrawFunds();
    void CloseAccount();
};

#include "Menu.h"
#include <iostream>
using namespace std;


/**
 * Displays the options for the user to select from in the main menu
 * @param: None
 * @return: void
 **/
void Menu::DisplayTitle() {
    cout << "*********************************************";
    cout << "   BANK MANAGEMENT SYSTEM   ";
    cout << "*********************************************" << endl;
}
void Menu::DisplayMenu() {
    cout << "\n\n\t\t\t\t\tPlease select an option below:";
    cout << "\n\n\t\t\t\t\t1. EDIT ACCOUNT";
    cout << "\n\n\t\t\t\t\t2. CHECK ACCOUNT BALANCE";
    cout << "\n\n\t\t\t\t\t3. DISPLAY ACCOUNT INFORMATION";
    cout << "\n\n\t\t\t\t\t4. DEPOSIT FUNDS";
    cout << "\n\n\t\t\t\t\t5. WITHDRAW FUNDS";
    cout << "\n\n\t\t\t\t\t6. CLOSE ACCOUNT";
    cout << "\n\n\t\t\t\t\t7. SIGN OUT";
    cout << "\n\n\t\t\t\t\tOPTION: ";
}
void Menu::DisplayMenu0() {
    cout << "\n\n\t\t\t\t\t1. LOGIN ";
    cout << "\n\n\t\t\t\t\t2. CREATE NEW ACCOUNT ";
    cout << "\n\n\t\t\t\t\t3. EXIT ";
    cout << "\n\n\t\t\t\t\tOPTION: ";

}
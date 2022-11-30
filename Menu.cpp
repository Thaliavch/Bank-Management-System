#include "Menu.h"
#include <iostream>
using namespace std;


/**
 * Displays the options for the user to select from in the main menu
 * @param: None
 * @return: void
 **/
Menu::Menu() {
    cout << "*********************************************";
    cout << "   BANK MANAGEMENT SYSTEM   ";
    cout << "*********************************************" << endl;
}
void Menu::DisplayMenu() {
    cout << "\n\nPlease select an option below:";
    cout << "\n\n1. EDIT ACCOUNT";
    cout << "\n\n2. CHECK ACCOUNT BALANCE";
    cout << "\n\n3. DISPLAY ACCOUNT INFORMATION";
    cout << "\n\n4. DEPOSIT FUNDS";
    cout << "\n\n5. WITHDRAW FUNDS";
    cout << "\n\n6. CLOSE ACCOUNT";
    cout << "\n\n7. SIGN OUT";
    cout << "\n\nOPTION: ";
}
void Menu::DisplayMenu0() {
    cout << "\n\n1. LOGIN ";
    cout << "\n\n2. CREATE NEW ACCOUNT ";
    cout << "\n\n3. EXIT ";
    cout << "\n\nOPTION: ";

}

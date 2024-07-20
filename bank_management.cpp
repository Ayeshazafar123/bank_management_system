#include <iostream>
#include <string>

using namespace std;

// Structure to hold account information
struct Account {
    string name;
    double balance;
};

// Function to create a new account
void createAccount(Account &acc, const string &name, double initialBalance) {
    acc.name = name;
    acc.balance = initialBalance;
    cout << "Account created for " << acc.name << " with initial balance $" << acc.balance << endl;
}

// Function to deposit money into an account
void deposit(Account &acc, double amount) {
    if (amount > 0) {
        acc.balance += amount;
        cout << "Deposited $" << amount << ". New balance: $" << acc.balance << endl;
    } else {
        cout << "Invalid deposit amount." << endl;
    }
}

// Function to withdraw money from an account
void withdraw(Account &acc, double amount) {
    if (amount > 0 && amount <= acc.balance) {
        acc.balance -= amount;
        cout << "Withdrew $" << amount << ". New balance: $" << acc.balance << endl;
    } else if (amount > acc.balance) {
        cout << "Insufficient funds." << endl;
    } else {
        cout << "Invalid withdrawal amount." << endl;
    }
}

// Function to check the account balance
void checkBalance(const Account &acc) {
    cout << "Account balance: $" << acc.balance << endl;
}

int main() {
    Account myAccount;
    string name;
    double initialBalance, amount;
    int choice;

    // Create account
    cout << "Enter account holder's name: ";
    getline(cin, name);
    cout << "Enter initial balance: $";
    cin >> initialBalance;
    cin.ignore();  // To ignore the leftover newline character in the input buffer

    createAccount(myAccount, name, initialBalance);

    // Main menu loop
    while (true) {
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();  // To ignore the leftover newline character in the input buffer

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                deposit(myAccount, amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                withdraw(myAccount, amount);
                break;
            case 3:
                checkBalance(myAccount);
                break;
            case 4:
                cout << "Exiting. Thank you!" << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}


#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;

public:
    Account() {}
    Account(int accNo, string accName, double bal) {
        accountNumber = accNo;
        name = accName;
        balance = bal;
    }

    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void showAccount() const {
        cout << left << setw(15) << accountNumber
             << setw(20) << name
             << fixed << setprecision(2) << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "Insufficient balance!" << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    string getName() const {
        return name;
    }

    void updateAccount(string newName) {
        name = newName;
    }
};

class BankSystem {
private:
    vector<Account> accounts;

public:
    void addAccount() {
        Account acc;
        acc.createAccount();
        accounts.push_back(acc);
        cout << "Account Created Successfully!\n";
    }

    void displayAccounts() const {
        if (accounts.empty()) {
            cout << "No accounts to display.\n";
            return;
        }

        cout << left << setw(15) << "Account No"
             << setw(20) << "Name"
             << "Balance" << endl;
        cout << "--------------------------------------------------\n";

        for (const auto& acc : accounts)
            acc.showAccount();
    }

    void depositToAccount() {
        int accNo;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Deposit Amount: ";
        cin >> amount;

        for (auto& acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                acc.deposit(amount);
                cout << "Deposit Successful!\n";
                return;
            }
        }
        cout << "Account Not Found!\n";
    }

    void withdrawFromAccount() {
        int accNo;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Withdrawal Amount: ";
        cin >> amount;

        for (auto& acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                acc.withdraw(amount);
                cout << "Withdrawal Processed.\n";
                return;
            }
        }
        cout << "Account Not Found!\n";
    }

    void updateAccountDetails() {
        int accNo;
        cout << "Enter Account Number to Update: ";
        cin >> accNo;

        for (auto& acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                string newName;
                cout << "Enter New Name: ";
                cin.ignore();
                getline(cin, newName);
                acc.updateAccount(newName);
                cout << "Account Updated Successfully!\n";
                return;
            }
        }
        cout << "Account Not Found!\n";
    }

    void deleteAccount() {
        int accNo;
        cout << "Enter Account Number to Delete: ";
        cin >> accNo;

        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if (it->getAccountNumber() == accNo) {
                accounts.erase(it);
                cout << "Account Deleted Successfully!\n";
                return;
            }
        }
        cout << "Account Not Found!\n";
    }

    void findAccount() const {
        int accNo;
        cout << "Enter Account Number to Search: ";
        cin >> accNo;

        for (const auto& acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                cout << "Account Found:\n";
                acc.showAccount();
                return;
            }
        }
        cout << "Account Not Found!\n";
    }
};

int main() {
    BankSystem bank;
    int choice;

    do {
        cout << "\n====== Bank Management System ======\n";
        cout << "1. Create New Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Update Account\n";
        cout << "6. Delete Account\n";
        cout << "7. Find Account\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bank.addAccount();
            break;
        case 2:
            bank.displayAccounts();
            break;
        case 3:
            bank.depositToAccount();
            break;
        case 4:
            bank.withdrawFromAccount();
            break;
        case 5:
            bank.updateAccountDetails();
            break;
        case 6:
            bank.deleteAccount();
            break;
        case 7:
            bank.findAccount();
            break;
        case 0:
            cout << "Exiting system...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

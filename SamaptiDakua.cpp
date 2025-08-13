#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Account {
    int accNumber;
    string name;
    double balance;
    string password;
};

vector<Account> accounts;

void loadAccounts() {
    accounts.clear();
    ifstream file("accounts.csv");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string accNumStr, name, balanceStr, password;

        getline(ss, accNumStr, ',');
        getline(ss, name, ',');
        getline(ss, balanceStr, ',');
        getline(ss, password);

        Account acc;
        acc.accNumber = stoi(accNumStr);
        acc.name = name;
        acc.balance = stod(balanceStr);
        acc.password = password;

        accounts.push_back(acc);
    }
    file.close();
}

void saveAccounts() {
    ofstream file("accounts.csv");
    for (const auto& acc : accounts) {
        file << acc.accNumber << "," << acc.name << "," << acc.balance << "," << acc.password << "\n";
    }
    file.close();
}

Account* findAccount(int accNumber) {
    for (auto& acc : accounts) {
        if (acc.accNumber == accNumber)
            return &acc;
    }
    return nullptr;
}

void createAccount() {
    Account acc;
    cout << "Enter new account number: ";
    cin >> acc.accNumber;
    if (findAccount(acc.accNumber) != nullptr) {
        cout << "Account number already exists!\n";
        return;
    }
    cin.ignore();
    cout << "Enter account holder's name: ";
    getline(cin, acc.name);
    cout << "Set account password: ";
    getline(cin, acc.password);
    acc.balance = 0.0;

    accounts.push_back(acc);
    saveAccounts();
    cout << "Account created successfully!\n";
}

void deposit() {
    int accNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accNumber;
    Account* acc = findAccount(accNumber);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }
    cout << "Enter amount to deposit: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Invalid amount.\n";
        return;
    }
    acc->balance += amount;
    saveAccounts();
    cout << "Deposit successful. New balance: " << acc->balance << "\n";
}

void withdraw() {
    int accNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accNumber;
    Account* acc = findAccount(accNumber);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount <= 0 || amount > acc->balance) {
        cout << "Invalid amount or insufficient funds.\n";
        return;
    }
    acc->balance -= amount;
    saveAccounts();
    cout << "Withdrawal successful. New balance: " << acc->balance << "\n";
}

void balanceInquiry() {
    int accNumber;
    cout << "Enter account number: ";
    cin >> accNumber;
    Account* acc = findAccount(accNumber);
    if (!acc) {
        cout << "Account not found.\n";
        return;
    }
    cout << "Current balance: " << acc->balance << "\n";
}

void transferFunds() {
    int fromAccNum, toAccNum;
    double amount;

    cout << "Enter your account number: ";
    cin >> fromAccNum;
    Account* fromAcc = findAccount(fromAccNum);
    if (!fromAcc) {
        cout << "Sender account not found.\n";
        return;
    }

    cout << "Enter recipient account number: ";
    cin >> toAccNum;
    Account* toAcc = findAccount(toAccNum);
    if (!toAcc) {
        cout << "Recipient account not found.\n";
        return;
    }

    cout << "Enter amount to transfer: ";
    cin >> amount;
    if (amount <= 0 || amount > fromAcc->balance) {
        cout << "Invalid amount or insufficient funds.\n";
        return;
    }

    fromAcc->balance -= amount;
    toAcc->balance += amount;
    saveAccounts();
    cout << "Transfer successful!\n";
}

void menu() {
    loadAccounts();
    int choice;

    do {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Transfer Funds\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: balanceInquiry(); break;
            case 5: transferFunds(); break;
            case 6: cout << "Thank you for using our banking system. Goodbye!\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}



# Banking System 
## Overview
A console-based banking application in C++ which allows users to:
- Create new accounts with password protection
- Deposit and withdraw funds
- Check account balances
- Transfer money between accounts  
Account data persists across sessions via `accounts.csv`, utilizing file I/O, C++ structures, and vector storage.

## Features
- **Create Account** with unique number, holder’s name, and password  
- **Deposit / Withdraw** with input validation  
- **Balance Inquiry** to display current balance  
- **Transfer Funds** between accounts  
- **Persistent Storage** using CSV file (`accounts.csv`)

- ## Setup & Requirements

**Prerequisites**
- C++ compiler (e.g., `g++`, `clang++`)
- Compatible IDE (Dev C++, Code::Blocks, VS Code)

**Compilation**
```bash
g++ -std=c++11 -o banking_system main.cpp

Run:
./banking_system

Usage Guide:
Upon launching, the menu displays options:
--- Banking System Menu ---
1. Create Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. Transfer Funds
6. Exit
Select an option (1–6) and follow prompts:
Create Account: Enter account number, name, and password

Deposit/Withdraw: Input account number and amount (validation included)

Transfer Funds: Provide sender and receiver account numbers and amount

Check Balance: Enter account number to view balance

Exit: Saves data and terminates the application

Project Structure:
main.cpp              # Contains the full implementation (menu + operations)
accounts.csv          # Stores accountNumber,name,balance,password 

System Design & Implementation:

Data Model
Account struct: holds account number, name, balance, password

Storage Mechanism
vector<Account> loads all accounts using loadAccounts(), and writes them back using saveAccounts() after any change

Core Functionalities

createAccount() — ensures unique account number

deposit() / withdraw() — validates amount and updates balance

balanceInquiry() — shows current balance

transferFunds() — transfers amount after validation

findAccount(int accNumber) — returns a pointer to account or nullptr

Control Flow
menu() function loops, presenting options until the user exits

Test Plan:

Functional Testing:

Creating accounts (including duplicate ID handling)

Deposits and withdrawals (valid/invalid amounts)

Balance inquiries

Transfers (valid, insufficient funds, non-existent accounts)

Persistence across restarts

Edge Cases:

Negative or zero amounts

Non-existent account operations

Invalid input handling (e.g., non-numeric entries)

Limitations & Future Work:

Current Limitations: 

Passwords stored in plain text

No encryption, logging, multithreading, or transaction history

Data access via linear search (inefficient for many accounts)

Future Enhancements: 

Use password hashing and authentication

Track transaction history with logs

Move to a GUI interface for better UX

Replace CSV persistence with a database (e.g., SQLite)

Optimize search with maps or hash-based structures 


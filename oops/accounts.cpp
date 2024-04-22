#include <iostream>
#include <string>

class Account {
protected:
  int accountNumber;
  double balance;

public:
  // Constructor to initialize base class members
  Account(int accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}

  // Function to deposit an amount
  void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      std::cout << "Deposit Successful! New balance: $" << balance << std::endl;
    } else {
      std::cout << "Invalid deposit amount. Please enter a positive value." << std::endl;
    }
  }

  // Function to withdraw an amount after checking balance
  void withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
      balance -= amount;
      std::cout << "Withdrawal Successful! New balance: $" << balance << std::endl;
    } else {
      std::cout << "Insufficient funds or invalid withdrawal amount." << std::endl;
    }
  }

  // Function to display account number and balance
  void displayBalance() {
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
  }
};

class SavingsAccount : public Account {
private:
  std::string name;
  double interestRate;
  std::string dateOfBirth; // Assuming date of birth is stored as a string

public:
  // Constructor to initialize SavingsAccount members and call base class constructor
  SavingsAccount(int accountNumber, double balance, double interestRate, const std::string& name, const std::string& dateOfBirth)
      : Account(accountNumber, balance), interestRate(interestRate), name(name), dateOfBirth(dateOfBirth) {}

  // No additional functions needed for deposit, withdraw, or displayBalance as they are inherited from the base class Account
};

int main() {
  // Create a SavingsAccount object
  SavingsAccount mySavings(123456789, 1000.00, 0.02, "John Doe", "1980-01-01");

  // Simulate transactions
  mySavings.deposit(500.00);
  mySavings.withdraw(200.00);

  // Display account balance
  mySavings.displayBalance();

  return 0;
}

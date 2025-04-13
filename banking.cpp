#include <iostream>
#include <iomanip>
#include <limits> // for std::numeric_limits

using namespace std;

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main()
{
    double balance = 0;
    int choice = 0;

    do {
        cout << "******************\n";
        cout << "Enter your choice:\n";
        cout << "******************\n";
        cout << "1. Show Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        // Clear any input error and ignore leftover characters in input buffer
        if(cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0; // set to invalid choice so default case runs
        }

        switch(choice) {
            case 1:
                showBalance(balance);
                break;
            case 2:
                balance += deposit();
                showBalance(balance);
                break;
            case 3:
                balance -= withdraw(balance);
                showBalance(balance);
                break;
            case 4:
                std::cout << "Thanks for visiting!\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }

    } while(choice != 4);

    return 0;
}

void showBalance(double balance) {
    std::cout << "Your balance is: $" << std::fixed << std::setprecision(2) << balance << '\n';
}

double deposit() {
    double amount = 0;

    cout << "Enter amount to be deposited: ";
    cin >> amount;

    if(cin.fail() || amount <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "That's not a valid amount.\n";
        return 0;
    }

    return amount;
}

double withdraw(double balance) {
    double amount = 0;

    cout << "Enter amount to be withdrawn: ";
    cin >> amount;

    if(cin.fail() || amount < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "That's not a valid amount.\n";
        return 0;
    } else if(amount > balance) {
        cout << "Insufficient funds.\n";
        return 0;
    }

    return amount;
}


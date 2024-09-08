#include<iostream>
#include<string.h>
#include<fstream>
#include<string>

using namespace std;

int a_number = 1234;
int pin = 123;
double balance = 25000;

void e_balance() {
    cout << "Your balance is: " << balance << endl;
}

void withdraw() {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount > balance) {
        cout << "Insufficient balance" << endl;
    }
    else {
        balance = balance - amount;
        cout << "Amount withdrawn: " << amount << endl;
        cout << "Remaining balance: " << balance << endl;
    }
}

void deposit() {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    balance = balance + amount;
    cout << "Amount deposited: " << amount << endl;
    cout << "New balance: " << balance << endl;
}

int main() {
    int attempts = 0;

    cout << "Welcome to ATM System" << endl;

    while (attempts < 3) {
        int e_num, e_Pin;
        cout << "Enter account number: ";
        cin >> e_num;
        cout << "Enter PIN: ";
        cin >> e_Pin;

        if (e_num == a_number && e_Pin == pin) {
            cout << "Login successful" << endl;
            break;
        }
        else {
            cout << "Invalid account number or PIN" << endl;
            attempts++;
        }
    }

    if (attempts == 3) {
        cout << "Too many attempts. Exiting program." << endl;
        return 0;
    }
    cout << endl;

    int  type;
    cout << "Select an Option " << endl;
    cout << "Press 1 for Quick Withdrawl" << endl;
    cout << "Press 2 if Saviing  account" << endl;
    cout << "Press 3 if you want to request for a ATM card" << endl;
    cin >> type;

    if (type == 3)
    {
        int n = 0;
        cout << "Do you want to request a ATM card " << endl;
        cout << "1.Yes  and  2.NO" << endl;
        cin >> n;

        if (n == 1) {


            cout << "You can give your personal information for Processing" << endl;
            cout << "************ Format ************" << endl;
            cout << "Name, Father Name, Age, CNIC, City   " << endl;



            string Abc;
            cin.ignore();

            getline(cin, Abc);

            fstream data;
            data.open("Danii.txt", ios::app);  //ios:: out(clears previous and stores new data)
            if (data.is_open()) {

                data << Abc << endl;

                data.close();

            }
            else
            {
                cout << "Requsted information file is Currupted";
            }

            cout << endl;
            cout << "Reqeuste Successfully Processesd and Stored" << endl;
            cout << endl;

            string b;
            fstream read;
            read.open("Danii.txt", ios::in);
            if (read.is_open()) {
                while (getline(read, b)) {

                    cout << b << endl;

                }

                read.close();

            }
            else
            {
                cout << "Requsted information file does not open";
            }

        }
        else if (n == 2) {

            cout << "Requet cancelled,  Thank you" << endl;
            return 0;

        }
    }

    else if (type == 2) {


        while (true) {
            cout << "*********** ATM System  ***********" << endl;
            cout << "1. Check Balance" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Deposit" << endl;
            cout << "4. Exit" << endl;
            cout << "Select an above option: ";
            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                e_balance();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                deposit();
                break;
            case 4:
                cout << "Thank you for using ATM System" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    else if (type == 1) {
        int n1;
        cout << endl;

        cout << "Current balance: " << balance << endl;

        cout << " you have following options: " << endl;

        cout << "1. 500          2. 1000 " << endl;
        cout << "3. 1500         4. 2000 " << endl;
        cout << "5. 2500         6. 3000 " << endl;
        cout << "7. 4500         8. 5000 " << endl;
        cin >> n1;

        switch (n1) {
        case 1:
            balance = balance - 500;
            break;
        case 2:
            balance = balance - 1000;
            break;
        case 3:
            balance = balance - 1500;
            break;
        case 4:
            balance = balance - 2000;
        case 5:
            balance = balance - 2500;
            break;
        case 6:
            balance = balance - 3000;
            break;
        case 7:
            balance = balance - 4500;
            break;
        case 8:
            balance = balance - 5000;
            break;
        default:
            cout << "Invalid amount Please try again." << endl;
            break;
        }
        cout << "Withdrawl Successful " << endl;
        cout << "Remaining balance: " << balance << endl;

    }
    else
        cout << "Invalid option. Please try again." << endl;
    return 0;
}


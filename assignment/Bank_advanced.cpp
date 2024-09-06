#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Bank {
    int balance, accNo;
    string name;
public:
    void createAccount() {
        static int accCounter = 1000; // Starting account number
        balance = 0;
        accNo = ++accCounter; // Increment and assign unique account number
        cout << "\n\nAccount Created successfully \n Your Acc No is " << accNo;
    }

    void deposit(int dep_accNo, int amt) {
        if (accNo != dep_accNo) {
            cout << "\n\nThis account number is not recognised!";
        } else {
            if (amt > 0) {
                balance += amt;
                cout << "\n\nDeposit is Successful\n";
            } else {
                cout << "Please Enter Positive Amount!";
            }
        }
    }

    void withdraw(int w_accNo, int w_amt) {
        if (accNo != w_accNo) {
            cout << "\n\nThis account number is not recognised!";
        } else {
            if (w_amt <= balance) {
                balance -= w_amt;
                cout << "\n\nWithdrawal is successful\n";
            } else {
                cout << "\n\nYou do not have enough balance!";
            }
        }
    }

    void displayAcc(int disp_accNo) {
        if (accNo == disp_accNo) {
            cout << "\n\nYour Account Number is : " << accNo << "\nBalance : " << balance;
        } else {
            cout << "\n\nThis account number is not recognised!";
        }
    }

    int getAccNo() const { // Marked as const
        return accNo;
    }
};

int findAccount(int accNo, const vector<Bank>& accounts) {
    for (int i = 0; i < accounts.size(); ++i) {
        if (accounts[i].getAccNo() == accNo) {
            return i;
        }
    }
    return -1; // Account not found
}

int main() {
    vector<Bank> accounts;
    int choice = 0;

    cout << "\n\n__________ Welcome to Bank Application __________________";
    while (choice != 5) {
        cout << "\n\nEnter Your Choice \n 1.Create Account \n 2.Deposit \n 3.Withdraw \n 4.Display Account \n 5.Exit \n Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Bank newAccount;
                newAccount.createAccount();
                accounts.push_back(newAccount);
                break;
            }
            case 2: {
                int accNo, amt;
                cout << "\n\nEnter your Account Number : ";
                cin >> accNo;
                int index = findAccount(accNo, accounts);
                if (index != -1) {
                    cout << "\n\nEnter the Amount to be deposited : ";
                    cin >> amt;
                    accounts[index].deposit(accNo, amt);
                } else {
                    cout << "\n\nAccount not found!";
                }
                break;
            }
            case 3: {
                int accNo, amt;
                cout << "\n\nEnter your Account Number : ";
                cin >> accNo;
                int index = findAccount(accNo, accounts);
                if (index != -1) {
                    cout << "\n\nEnter the amount to be withdrawn : ";
                    cin >> amt;
                    accounts[index].withdraw(accNo, amt);
                } else {
                    cout << "\n\nAccount not found!";
                }
                break;
            }
            case 4: {
                int accNo;
                cout << "\n\nEnter your Account Number : ";
                cin >> accNo;
                int index = findAccount(accNo, accounts);
                if (index != -1) {
                    accounts[index].displayAcc(accNo);
                } else {
                    cout << "\n\nAccount not found!";
                }
                break;
            }
            case 5:
                cout << "\n\n*---*---*_--*----*---*--- Thank you *---*---*_--*----*---*---";
                break;
            default:
                cout << "\nEnter proper choice!";
                break;
        }
    }
}

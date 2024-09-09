#include <iostream>
#include <vector>
using namespace std;

class User{
    int rrno,pass,prev_Reading,curr_Reading;
    string name;

    public:
    User(const string& name,const int rr_no,const int pass){
        this->name=name;
        rrno=rr_no;
        prev_Reading=0;
    }

    int getRRno() const{
        return rrno;
    }

    int getPass() const{
        return pass;
    }

    int getPrevReading() const{
        return prev_Reading;
    }

    string getName() const{
        return name;
    }

    void setName(string name){
        this->name=name;
    }

    void setRRno(int no){
        rrno=no;
    }

    void setPass(int pswd){
        pass=pswd;
    }

    void setCurrent(int cur_read){
        curr_Reading=cur_read;
    }

    void setPrevious(int prev_read){
        prev_Reading=prev_read;
    }

    int calculateBill() const{
        int final_unit,bill;
        bill=0;
        final_unit=prev_Reading-curr_Reading;
        if(final_unit<50){
            bill=final_unit*4;
        }
        else if(final_unit>50&&final_unit<200){
            bill=50*4+(final_unit-50)*6;
        }else if(final_unit>200){
            bill=50*4+150*6+(final_unit-200)*8;
        }else{
            cout<<"\n\nEnter proper units";
        }
        return bill;
    }

    void updateReading(int newReading){
        prev_Reading=curr_Reading;
        curr_Reading=newReading;    
        }

    bool chechPass(const int paswd){
        return pass==paswd;
    }

    void displayInfo() const{
        cout<<"\nUsername  :  "<<getName()<<"\n RR.NO  :  "<<getRRno()<<endl;
    }

};



class Admin {
private:
    string username = "admin";
    string password = "admin123";

public:
    bool checkAdminLogin(const string& inputUsername, const string& inputPassword) const {
        return username == inputUsername && password == inputPassword;
    }

    void viewAllUsers(const vector<User>& users) const {
        std::cout << "All Registered Users:\n";
        for (const auto& user : users) {
            user.displayInfo();
        }
    }

    void viewUserDetails(const vector<User>& users, const int rrNumber) const {
        for (const auto& user : users) {
            if (user.getRRno() == rrNumber) {
                user.displayInfo();
                cout << "Bill Amount: " << user.calculateBill() << " Rs\n";
                return;
            }
        }
        cout << "User with RR Number " << rrNumber << " not found.\n";
    }
};

class SmartMeterSystem {
private:
    vector<User> users;
    Admin admin;

public:
    SmartMeterSystem() {
        // Initialize with some users (for testing purposes)
        users.push_back(User("Vijay", 123, 1221));
        users.push_back(User("Raju", 124, 1234));
    }

    void adminMenu() {
        string username, password;
        cout << "Enter Admin Username: ";
        cin >> username;
        cout << "Enter Admin Password: ";
        cin >> password;

        if (admin.checkAdminLogin(username, password)) {
            int choice;
            while (true) {
                cout << "Admin Menu:\n";
                cout << "1. View All Users\n";
                cout << "2. View User Details\n";
                cout << "3. Logout\n";
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1) {
                    admin.viewAllUsers(users);
                } else if (choice == 2) {
                    int rrNumber;
                    cout << "Enter RR Number: ";
                    cin >> rrNumber;
                    admin.viewUserDetails(users, rrNumber);
                } else if (choice == 3) {
                    break;
                } else {
                    cout << "Invalid choice. Please try again.\n";
                }
            }
        } else {
            cout << "Invalid admin credentials.\n";
        }
    }

    void userMenu(const int rrNumber) {
        for (auto& user : users) {
            if (user.getRRno() == rrNumber) {
                int choice;
                while (true) {
                    cout << "User Menu:\n";
                    cout << "1. Check Bill\n";
                    cout << "2. Update Meter Reading\n";
                    cout << "3. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> choice;

                    if (choice == 1) {
                        cout << "Current Bill: " << user.calculateBill() << " Rs\n";
                    } else if (choice == 2) {
                        int newReading;
                        cout << "Enter new meter reading: ";
                        cin >> newReading;
                        user.updateReading(newReading);
                        cout << "Meter reading updated.\n";
                    } else if (choice == 3) {
                        break;
                    } else {
                        cout << "Invalid choice. Please try again.\n";
                    }
                }
                return;
            }
        }
        cout << "User with RR Number " << rrNumber << " not found.\n";
    }

    void mainMenu() {
        while (true) {
            cout << "1. Admin Login\n";
            cout << "2. User Login\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                adminMenu();
            } else if (choice == 2) {
                int rrNumber, password;
                cout << "Enter RR Number: ";
                cin >> rrNumber;
                cout << "Enter Password: ";
                cin >> password;

                bool isValidUser = false;
                for (auto& user : users) {
                    if (user.getRRno() == rrNumber && user.chechPass(password)) {
                        userMenu(rrNumber);
                        isValidUser = true;
                        break;
                    }
                }
                if (!isValidUser) {
                    cout << "Invalid login credentials.\n";
                }
            } else if (choice == 3) {
                break;
            } else {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    const vector<User>& getUsers() const {
        return users;
    }
};

int main() {
    SmartMeterSystem system;
    system.mainMenu();
    return 0;
}


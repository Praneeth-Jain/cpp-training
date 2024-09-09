#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product{
    int productId;
    string productName;
    double productPrice;
    int quantity;

    public:
    Product(int id, const string& name, double price,int qty){
        productId=id;
        productName=name;
        productPrice=price;
        quantity=qty;
    }

    
    int getProd_Id() const{
        return productId;
    }

    int getQuantity() const{
        return quantity;
    }

    double getPrice() const{
        return productPrice;
    }

    string getProdName () const{
        return productName;
    }

    void setProdId(int id){
        productId=id;
    }
    void setProdName(string name){
        productName=name;
    }

    void setQuantity(int qty){
        quantity=qty;
    }

    void setPrice(double amt){
        productPrice=amt;
    }

    void displayProducts () const{
        cout<<"\n "<<getProd_Id()<<"\t"<<getProdName()<<"\t"<<getPrice()<<"\t"<<getQuantity();
    }
};


class Order{
    int orderID;
    vector<Product> orderedProducts;
    string orderDate;

    public:
     Order(int id, const vector<Product>& products, string& date) {
        orderID = id;
        orderedProducts = products;
        orderDate = date;
    }

    int getOrderID() const{
        return orderID;
    }

    string getOrderDate() const{
        return orderDate;
    }

    vector<Product> getOrderedProds() const{
        return orderedProducts;
    }

    void setOrderID(int id){
        orderID=id;
    }

    void setOrderDate(string& date){
        orderDate=date;
    }

    void setOrderedProduct(const vector<Product>& products){
        orderedProducts=products;
    }

    void viewOrders() const{
        
        cout<<"\n"<<getOrderID()<<"\t"<<getOrderDate()<<"\t";
        for (const auto& product : orderedProducts) {
            product.displayProducts();
        }
}
};

class User {
private:
    std::string username;
    std::string password;

public:
    User(const std::string& uname, const std::string& pwd)
        : username(uname), password(pwd) {}

    string getUsername() const 
    { 
        return username; 
    }

    bool checkPassword(const string& pwd) const 
    { 
        return password == pwd; 
    }

    void displayUser() const {
        cout << "Username: " << username << std::endl;
    }
};

class ApplicationManager {
private:
    std::vector<User> users;
    std::vector<Product> products;
    std::vector<Order> orders;

public:
    ApplicationManager() {
        // Adding some initial products (for simplicity)
        products.push_back(Product(1, "Laptop", 999.99,10));
        products.push_back(Product(2, "Smartphone", 499.99,5));
        products.push_back(Product(3, "Headphones", 79.99,20));
    }

    void adminMenu() {
        int choice;
        do {
            std::cout << "\nAdmin Menu\n";
            std::cout << "1. Add Product\n2. View Products\n3. View Orders\n4. Exit\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                cout<<"|  Order ID  |  OrderedDate   |  Ordered Product |\n";
                viewOrders();
                break;
            case 4:
                std::cout << "Exiting admin menu...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 4);
    }

    void userMenu(User& user) {
        int choice;
        do {
            std::cout << "\nUser Menu\n";
            std::cout << "1. View Products\n2. Place Order\n3. Exit\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                cout<<"\n ID   |  Name    | Price   |  Quantity  |";
                viewProducts();
                break;
            case 2:
                placeOrder(user);
                break;
            case 3:
                std::cout << "Exiting user menu...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != 3);
    }

    void addProduct() {
        int id,qty;
        string name;
        double price;

        cout << "\nEnter Product ID: ";
        cin >> id;
        cout << "\nEnter Product Name: ";
        cin >> name;
        cout << "\nEnter Product Price: ";
        cin >> price;
        cout << "\nEnter the No of Products : ";
        cin>>qty;



        products.push_back(Product(id, name, price,qty));
        std::cout << "Product added successfully!\n";
    }

    void viewProducts() const {
        std::cout << "\nAvailable Products:\n";
        for (const auto& product : products) {
            product.displayProducts();
        }
    }

    void placeOrder(User& user) {
        int orderId = orders.size() + 1;
        std::string date;
        std::vector<Product> orderProducts;
        int productId;
        char addMore;

        std::cout << "Enter Order Date (YYYY-MM-DD): ";
        std::cin >> date;

        do {
            std::cout << "Enter Product ID to add to order: ";
            std::cin >> productId;

            bool productFound = false;
            for (const auto& product : products) {
                if (product.getProd_Id() == productId) {
                    orderProducts.push_back(product);
                    productFound = true;
                    break;
                }
            }

            if (!productFound) {
                std::cout << "Product not found!\n";
            }

            std::cout << "Add another product? (y/n): ";
            std::cin >> addMore;

        } while (addMore == 'y' || addMore == 'Y');

        orders.push_back(Order(orderId, orderProducts, date));
        std::cout << "Order placed successfully!\n";
    }

    void viewOrders() const {
        std::cout << "\nAll Orders:\n";
        for (const auto& order : orders) {
            order.viewOrders();
        }
    }

    void createUserAccount() {
        string uname, pwd;

        cout << "Enter username: ";
        cin >> uname;
        cout << "Enter password: ";
        cin >> pwd;

        users.push_back(User(uname, pwd));
        cout << "User account created successfully!\n";
    }

    User* loginUser() {
        string uname, pwd;
        cout << "Enter username: ";
        cin >> uname;
        cout << "Enter password: ";
        cin >> pwd;

        for (auto& user : users) {
            if (user.getUsername() == uname && user.checkPassword(pwd)) {
                cout << "Login successful!\n";
                return &user;
            }
        }
        cout << "Invalid credentials!\n";
        return nullptr;
    }
};

int main() {
    ApplicationManager appManager;
    string adminUsername = "admin";
    string adminPassword = "admin123";
    int choice;

    do {
        cout << "\nE-Commerce Application\n";
        cout << "1. Admin Login\n2. User Login\n3. Create User Account\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            std::string uname, pwd;
            std::cout << "Enter admin username: ";
            std::cin >> uname;
            std::cout << "Enter admin password: ";
            std::cin >> pwd;

            if (uname == adminUsername && pwd == adminPassword) {
                appManager.adminMenu();
            } else {
                std::cout << "Invalid admin credentials!\n";
            }
            break;
        }
        case 2: {
            User* user = appManager.loginUser();
            if (user) {
                appManager.userMenu(*user);
            }
            break;
        }
        case 3:
            appManager.createUserAccount();
            break;
        case 4:
            std::cout << "Exiting application...\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
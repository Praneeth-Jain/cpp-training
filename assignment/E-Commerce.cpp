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
    Product(int id,string& name,double price,int qty){
        productId=id;
        productName=name;
        productPrice=price;
        quantity=qty;
    }

    
    int getProd_Id(){
        return productId;
    }

    int getQuantity(){
        return quantity;
    }

    double getPrice(){
        return productPrice;
    }

    string getProdName(){
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

    void displayProducts(){
        cout<<"\n\n___________________ Product Menu _________________________";
        cout<<"\n ID   |  Name    | Price   |  Quantity  |";
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


};
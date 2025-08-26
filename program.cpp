#include <iostream>
using namespace std;

struct Vegetable {
    int itemID;
    double pricePerKg;
};

void displayVegetableInfo(int count, Vegetable veg[]) {
    for (int i = 0; i < count; i++)
    {
        cout << "Item ID: " << veg[i].itemID << ", Item Price: " << veg[i].pricePerKg << endl;
    }
}

void addVegetable(Vegetable veg[], int& count, int id, double price) {
    if (count < 10) {
        veg[count].itemID = id;
        veg[count].pricePerKg = price;
        count++;
    } else {
        cout << "Vegetable list is full!" << endl;
    }
}

void updateVegetablePrice(Vegetable veg[], int count, int id, double newPrice) {
    for (int i = 0; i < count; i++) {
        if (veg[i].itemID == id) {
            veg[i].pricePerKg = newPrice;
            cout << "Updated Item ID: " << id << ", New Price per Kg: " << newPrice << endl;
            return;
        }
    }
    cout << "Item ID: " << id << " not found." << endl;
}

void deleteVegetable(Vegetable veg[], int& count, int id) {
    for (int i = 0; i < count; i++) {
        if (veg[i].itemID == id) {
            for (int j = i; j < count - 1; j++) {
                veg[j] = veg[j + 1];
            }
            count--;
            cout << "Deleted Item ID: " << id << endl;
            return;
        }
    }
    cout << "Item ID: " << id << " not found." << endl;
}

void itemsAbove500(int count, Vegetable veg[]) {
    int num =0;
    
    for(int i=0;i<count;i++){
        if(veg[i].pricePerKg>500){
            num++;
        }
    }

    cout << "Total items above 500: " << num << endl;
    cout << "Items are: " << endl;
    for(int i=0;i<count;i++){
        if(veg[i].pricePerKg>500){
            cout << "Item ID: " << veg[i].itemID << ", ";
        }
    }
}

void billCalculation(int count, Vegetable veg[]) {

    struct billInfo {
        int id;
        double quantity;
        double price;
    };

    billInfo billing[10];
    int num=0;
    double totalBill=0;

    int flag = 1;
    while(flag){
        int id;
        double quantity;

        cout << "Enter Item ID to purchase: ";
        cin >> id;
        cout << "Enter quantity (in Kg): ";
        cin >> quantity;
        
        billing[num].id = id;
        billing[num].quantity = quantity;
        for (int i = 0; i < count; i++)
        {
            if (veg[i].itemID == id) {
                billing[num].price = veg[i].pricePerKg * quantity;
                break;
            }   
        }
        
        num++;

        int choice;
        cout << "Do you want to continue? (1/0): ";
        cin >> choice;
        if (choice != 1) {
            flag = 0;
        }
    }

    cout<<"Item ID\tQuantity\tPrice"<<endl;
    for (int i = 0; i < num; i++) {
        cout << billing[i].id << "\t" << billing[i].quantity << "\t" << billing[i].price << endl;
    }

    cout << "Total Bill Amount: ";
    for (int i = 0; i < num; i++) {
        totalBill += billing[i].price;
    }
    cout << totalBill << endl;

    double discount = 0;
    double totalNetAmount = 0;

    for (int i = 0; i < num; i++)
    {
        if (billing[i].id == 1005 && billing[i].quantity > 5)
        {
            discount += billing[i].price * 0.2;
        }
        if (billing[i].id == 1007 && billing[i].quantity > 2.5)
        {
            discount += billing[i].price * 0.05;
        }
    }

    cout<<"Discount price is "<<discount<<endl;
    totalNetAmount = totalBill - discount;
    cout<<"Total net amount is "<<totalNetAmount<<endl;

    if (totalNetAmount > 5000)
    {
        cout << "Congratulations! You are eligible for a special discount." << endl;
        cout << "Your new bill is: " << totalNetAmount * 0.5 << endl;  
    }
    
}

int main() {

    Vegetable vegetables[10] = {
        {1005, 650.00},
        {1007, 758.00},
        {1009, 105.00},
        {1004, 400.00},
        {1006, 410.00}
    };

    int count = 5;

    displayVegetableInfo(count, vegetables);
    addVegetable(vegetables, count, 1010, 300.00);
    updateVegetablePrice(vegetables, count, 1007, 800.00);
    deleteVegetable(vegetables, count, 1004);
    itemsAbove500(count, vegetables);

    return 0;
}
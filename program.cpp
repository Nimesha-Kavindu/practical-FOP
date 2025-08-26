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
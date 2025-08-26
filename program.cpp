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

    return 0;
}
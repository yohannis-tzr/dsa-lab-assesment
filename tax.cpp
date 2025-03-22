#include <iostream>
#include <string>

using namespace std;

#define TAX_RATE_PREPROCESSOR 0.06
const float TAX_RATE = 0.06;

int main() {
    cout << "this program will calculate the tax and the total sales" << endl;
    cout << "always remember that c++ is a compiled language" << endl;

    string productName;
    int productCategory;
    int initialInventoryQuantity;
    float productPricePerUnit;
    int numberOfItemsSold;
    int newInventory;
    float totalSales = 0.0;
    string inventoryStatus;
    string directInitProductName = "potato";
    int assignedProductCategory = 0;
    int listInitInitialInventory{50};
    auto totalSalesCopy = totalSales;
    decltype(initialInventoryQuantity) helperInventory = 0;

    cout << "enter the product: ";
    cin >> productName;
    cout << "enter the product category: ";
    cin >> productCategory;
    cout << "initial inventory quantity: ";
    cin >> initialInventoryQuantity;
    cout << "product price: ";
    cin >> productPricePerUnit;
    cout << "number of items sold: ";
    cin >> numberOfItemsSold;

    newInventory = initialInventoryQuantity - numberOfItemsSold;
    totalSales = numberOfItemsSold * productPricePerUnit;

    if (newInventory < 10) {
        inventoryStatus = "low quantity";
    } else {
        inventoryStatus = "sufficient quantity";
    }

    if (productCategory < 1 || productCategory > 5) {
        cout << "invalid product category!" << endl;
    } else {
        switch (productCategory) {
            case 1: cout << "cat 1 electronics" << endl; break;
            case 2: cout << "cat 2 groceries" << endl; break;
            case 3: cout << "cat 3 clothing" << endl; break;
            case 4: cout << "cat 4 stationery" << endl; break;
            case 5: cout << "cat 5 miscellaneous" << endl; break;
        }
    }

    if (numberOfItemsSold > 0) {
        for (int i = 1; i <= numberOfItemsSold; ++i) {
            cout << "sold item " << i << productPricePerUnit << endl;
        }
    }

    cout << "tax rate preprocessor: " << TAX_RATE_PREPROCESSOR << endl;
    cout << "tax rate const variable: " << TAX_RATE << endl;
    cout << "name of the product: " << productName << endl;
    cout << "product category: " << productCategory << endl;
    cout << "initial quantity: " << initialInventoryQuantity << endl;
    cout << "product price: $" << productPricePerUnit << endl;
    cout << "items sold: " << numberOfItemsSold << endl;
    cout << "new quantity: " << newInventory << endl;
    cout << "total sales: $" << totalSales << endl;
    cout << "inventory status: " << inventoryStatus << endl;
    cout << "helper variable (total sales copy): " << totalSalesCopy << endl;
    cout << "helper variable: " << helperInventory << endl;

    return 0;
}

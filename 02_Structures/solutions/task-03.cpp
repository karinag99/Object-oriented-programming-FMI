#include <iostream>
#include <cstring>

using namespace std;

const int NAME_MAX_SIZE = 256;

struct Product {
	unsigned int sellCount;
	double price;

	char name[NAME_MAX_SIZE];
};

struct Shop {
	Product products[100];
	int productCount;
	int totalSellCount;
	double totalSold;
};


void enterProduct(Product& product) {
    cin.ignore();
    cout << "Enter product name: ";
    cin.getline(product.name, NAME_MAX_SIZE - 1);
    cout << "Enter product price: ";
    cin >> product.price;
    product.sellCount = 0;
}

void enterShop(Shop& shop) {
    cout << "Enter the count of products in the shop: ";
    cin >> shop.productCount;
    shop.totalSellCount = 0;
    shop.totalSold = 0;
    for (int i = 0; i < shop.productCount; ++i) {
        enterProduct(shop.products[i]);
    }    
}

void printProduct(const Product& product) {
	cout << "Product name: " << product.name << '\n';
	cout << "Single price: " << product.price << '\n';
	cout << "Sell count: " << product.sellCount << '\n';
}


void printShop(const Shop& shop) {
    cout << "Shop product count: " << shop.totalSellCount << '\n';
	cout << "Shop profit: " << shop.totalSold << '\n';
	
	for (int i = 0; i < shop.productCount; ++i) {
        cout << "\nProduct " << i << '\n';
		printProduct(shop.products[i]);
	}

}


void buyProduct(Shop* shop, const char * productName) {
	for (int i = 0; i < shop->productCount; i++)
	{
		if (strcmp(productName, shop->products[i].name) == 0) {
			Product& p = shop->products[i];
			p.sellCount++;
			shop->totalSellCount++;
			shop->totalSold += p.price;
			return;
		}
	}
}

int main() {
    Shop shop;
    enterShop(shop);
    buyProduct(&shop, "Bread");
    buyProduct(&shop, "Bread");
    buyProduct(&shop, "Tomato");
    printShop(shop);

    return 0;
}
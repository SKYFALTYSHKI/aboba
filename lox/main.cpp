#include <iostream>
#include "product.h"

int main() {
    setlocale(LC_ALL, "RU");
    std::string filename = "catalog.txt";
    std::vector<Product> products = readFromFile(filename);

    if (products.empty()) {
        std::cerr << "Нет данных для обработки!\n";
        return 1;
    }

    filterByCategory(products, "Промтовары");
    filterByPrice(products, 100.0);

    selectionSort(products);
    std::cout << "\nСортировка по убыванию количества товара:\n";
    for (const auto& product : products) {
        std::cout << product.name << " - " << product.quantity << "\n";
    }

    mergeSort(products, 0, products.size() - 1);
    std::cout << "\nСортировка по возрастанию категории, затем по убыванию стоимости:\n";
    for (const auto& product : products) {
        std::cout << product.name << " - " << product.category << " - " << product.price << "\n";
    }

    return 0;
}

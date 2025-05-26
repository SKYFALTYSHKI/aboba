#include <iostream>
#include "product.h"

int main() {
    setlocale(LC_ALL, "RU");
    std::string filename = "catalog.txt";
    std::vector<Product> products = readFromFile(filename);

    if (products.empty()) {
        std::cerr << "��� ������ ��� ���������!\n";
        return 1;
    }

    filterByCategory(products, "����������");
    filterByPrice(products, 100.0);

    selectionSort(products);
    std::cout << "\n���������� �� �������� ���������� ������:\n";
    for (const auto& product : products) {
        std::cout << product.name << " - " << product.quantity << "\n";
    }

    mergeSort(products, 0, products.size() - 1);
    std::cout << "\n���������� �� ����������� ���������, ����� �� �������� ���������:\n";
    for (const auto& product : products) {
        std::cout << product.name << " - " << product.category << " - " << product.price << "\n";
    }

    return 0;
}

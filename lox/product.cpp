#include "product.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

std::vector<Product> readFromFile(const std::string& filename) {
    std::vector<Product> products;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Ошибка открытия файла!\n";
        return products;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Product product;
        ss >> std::quoted(product.name) >> product.category >> product.price >> product.quantity;
        products.push_back(product);
    }

    file.close();
    return products;
}

void selectionSort(std::vector<Product>& products) {
    for (size_t i = 0; i < products.size() - 1; ++i) {
        size_t maxIdx = i;
        for (size_t j = i + 1; j < products.size(); ++j) {
            if (products[j].quantity > products[maxIdx].quantity) {
                maxIdx = j;
            }
        }
        std::swap(products[i], products[maxIdx]);
    }
}

void merge(std::vector<Product>& products, int left, int mid, int right) {
    std::vector<Product> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (products[i].category < products[j].category ||
            (products[i].category == products[j].category && products[i].price > products[j].price)) {
            temp.push_back(products[i++]);
        }
        else {
            temp.push_back(products[j++]);
        }
    }

    while (i <= mid) temp.push_back(products[i++]);
    while (j <= right) temp.push_back(products[j++]);

    for (int k = left; k <= right; ++k) {
        products[k] = temp[k - left];
    }
}

void mergeSort(std::vector<Product>& products, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(products, left, mid);
    mergeSort(products, mid + 1, right);
    merge(products, left, mid, right);
}

void filterByCategory(const std::vector<Product>& products, const std::string& category) {
    std::cout << "\nТовары в категории " << category << ":\n";
    for (const auto& product : products) {
        if (product.category == category) {
            std::cout << product.name << " - " << product.price << " - " << product.quantity << "\n";
        }
    }
}

void filterByPrice(const std::vector<Product>& products, double minPrice) {
    std::cout << "\nТовары стоимостью выше " << minPrice << " рублей:\n";
    for (const auto& product : products) {
        if (product.price > minPrice) {
            std::cout << product.name << " - " << product.price << " - " << product.quantity << "\n";
        }
    }
}

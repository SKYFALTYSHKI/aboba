#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

struct Product {
    std::string name;
    std::string category;
    double price;
    int quantity;
};

std::vector<Product> readFromFile(const std::string& filename);
void selectionSort(std::vector<Product>& products);
void mergeSort(std::vector<Product>& products, int left, int right);
void filterByCategory(const std::vector<Product>& products, const std::string& category);
void filterByPrice(const std::vector<Product>& products, double minPrice);

#endif // PRODUCT_H

#include<fstream>
#include "pch.h"
#include "CppUnitTest.h"
#include "../lox/product.h" // путь к твоему файлу с определением функций
#include "../lox/main.cpp"
#include "../lox/product.cpp"
#include<vector>
#include<sstream>
#include <iomanip>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	TEST_CLASS(unittestproject)
	{
	public:

		TEST_METHOD(ReadFromFileTest)
		{
			std::ofstream testfile("test_catalog.txt");
			testfile << "\"Товар1\" Промтовары 120.5 10\n";
			testfile << "\"Товар2\" Промтовары 80.0 5\n";
			testfile << "\"Товар3\" Продукты 200.0 15\n";
			testfile << "\"Товар4\" Одежда 150.0 8\n";
			testfile.close();

			auto products = readFromFile("test_catalog.txt");

			Assert::AreEqual((size_t)4, products.size());
			Assert::AreEqual(std::string("Товар1"), products[0].name);
			Assert::AreEqual(std::string("Продукты"), products[2].category);
		}

		TEST_METHOD(FilterByCategoryTest)
		{
			std::vector<Product> products = {
				{"Товар1", "Промтовары", 100.0, 10},
				{"Товар2", "Продукты", 200.0, 5},
				{"Товар3", "Промтовары", 120.0, 7}
			};

			int count = 0;
			for (const auto& p : products)
				if (p.category == "Промтовары") count++;

			Assert::AreEqual(2, count);
		}

		TEST_METHOD(FilterByPriceTest)
		{
			std::vector<Product> products = {
				{"A", "X", 50.0, 2},
				{"B", "Y", 120.0, 5},
				{"C", "Z", 200.0, 1}
			};

			int count = 0;
			for (const auto& p : products)
				if (p.price > 100.0) count++;

			Assert::AreEqual(2, count);
		}

		TEST_METHOD(SelectionSortTest)
		{
			std::vector<Product> products = {
				{"A", "X", 100.0, 3},
				{"B", "Y", 200.0, 7},
				{"C", "Z", 150.0, 5}
			};

			selectionSort(products);

			Assert::AreEqual(7, products[0].quantity);
			Assert::AreEqual(5, products[1].quantity);
			Assert::AreEqual(3, products[2].quantity);
		}

		TEST_METHOD(MergeSortTest)
		{
			std::vector<Product> products = {
				{"A", "Б", 150.0, 1},
				{"B", "А", 120.0, 2},
				{"C", "Б", 200.0, 3}
			};

			mergeSort(products, 0, products.size() - 1);

			// Сортировка по категории (по возрастанию), затем по убыванию цены
			Assert::AreEqual(std::string("B"), products[0].name); // "А"
			Assert::AreEqual(std::string("C"), products[1].name); // "Б" и цена 200
			Assert::AreEqual(std::string("A"), products[2].name); // "Б" и цена 150
		}
	};
}

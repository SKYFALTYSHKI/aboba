#include<fstream>
#include "pch.h"
#include "CppUnitTest.h"
#include "../lox/product.h" // ���� � ������ ����� � ������������ �������
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
			testfile << "\"�����1\" ���������� 120.5 10\n";
			testfile << "\"�����2\" ���������� 80.0 5\n";
			testfile << "\"�����3\" �������� 200.0 15\n";
			testfile << "\"�����4\" ������ 150.0 8\n";
			testfile.close();

			auto products = readFromFile("test_catalog.txt");

			Assert::AreEqual((size_t)4, products.size());
			Assert::AreEqual(std::string("�����1"), products[0].name);
			Assert::AreEqual(std::string("��������"), products[2].category);
		}

		TEST_METHOD(FilterByCategoryTest)
		{
			std::vector<Product> products = {
				{"�����1", "����������", 100.0, 10},
				{"�����2", "��������", 200.0, 5},
				{"�����3", "����������", 120.0, 7}
			};

			int count = 0;
			for (const auto& p : products)
				if (p.category == "����������") count++;

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
				{"A", "�", 150.0, 1},
				{"B", "�", 120.0, 2},
				{"C", "�", 200.0, 3}
			};

			mergeSort(products, 0, products.size() - 1);

			// ���������� �� ��������� (�� �����������), ����� �� �������� ����
			Assert::AreEqual(std::string("B"), products[0].name); // "�"
			Assert::AreEqual(std::string("C"), products[1].name); // "�" � ���� 200
			Assert::AreEqual(std::string("A"), products[2].name); // "�" � ���� 150
		}
	};
}

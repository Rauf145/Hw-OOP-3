#include "MyString.h"

void main()
{
	string str;
	char *temp = new char[20];
	std::getline(std::cin, str);
	MyString test(str);
	//cout << test.size() << "\t";
	std::getline(std::cin, str);
	MyString test1(str);
	//test.swap(test1);
//	cout << test.find(test1) << endl;;
	test.replace(1, 4, test1);
	test.Print();
	//test.erase(1, 2);
	//cout << test.c_str1();
	//cout << test.size() << "\t";
	test.Print();
	test1.Print();
//	test.Clear();
	//test1.Clear();
	test.Print();
	test1.Print();
	//cout << test.size() << "\t";
	//cout << test.empty() << "\t";
	//test.Clear();
	//cout << test.size() << "\t";
	//cout << test.empty() << "\t";
}
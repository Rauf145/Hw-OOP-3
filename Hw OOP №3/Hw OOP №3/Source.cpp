#include "MyString.h"

void main()
{
	string str;
	char *temp = new char[20];
	cin >> str;
	MyString test(str);
	//cout << test.size() << "\t";
	cin >> str;
	MyString test1(str);
	test.swap(test1);
	//cout << test.c_str1();
	//cout << test.size() << "\t";
	test.Print();
	test1.Print();
	//cout << test.size() << "\t";
	//cout << test.empty() << "\t";
	//test.Clear();
	//cout << test.size() << "\t";
	//cout << test.empty() << "\t";
}
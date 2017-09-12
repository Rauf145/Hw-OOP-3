#include "MyString.h"

MyString operator+(const MyString &str1, const MyString &str2)
{
	int size = str1.length + str2.length;
	char *temp = new char[size];
	for (int i = 0; i <= size; i++)
	{	
		if (i < str1.length)
			temp[i] = str1.symbol[i];
		if (i >= str1.length)
			temp[i] = str2.symbol[i - str1.length];
	}
	return MyString(temp);
}

MyString operator+(const MyString &str1, const char *&str2)
{
	int index = 0;
	int size;
	while (str2[index++] != '\0') {}
	size = str1.length + index - 1;
	char *temp = new char[size];
	for (int i = 0; i <= size; i++)
	{
		if (i < str1.length)
			temp[i] = str1.symbol[i];
		if (i >= str1.length)
			temp[i] = str2[i - str1.length];
	}
	temp[str1.length + index - 1] = '\0';
	return MyString(temp);
}

void main()
{
	string str;
	char *temp = new char[20];
	std::getline(std::cin, str);
	MyString test(str);
	//cout << test.size() << "\t";
	std::getline(std::cin, str);
	cin >> temp;
	MyString test1(str);
	MyString test2;
	test2 = test + temp;
	//test.swap(test1);
//	cout << test.find(test1) << endl;;
	//test.replace(1, 5, test1);
	//test.Print();
	//test.erase(1, 2);
	//cout << test.c_str1();
	//cout << test.size() << "\t";
	//test.Print();
	test2.Print();
	//test.Clear();
	//test1.Clear();
	//test.Print();
	//test1.Print();
	//cout << test.size() << "\t";
	//cout << test.empty() << "\t";
	//test.Clear();
	//cout << test.size() << "\t";
	//cout << test.empty() << "\t";
}
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

MyString operator+(const MyString &str1, const char *str2)
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


MyString operator+(const char *str1, const MyString &str2)
{
	int index = 0, size = 0;
	while (str1[index++] != '\0') {}
	size = str2.length + index - 1;
	char *temp = new char[size];
	for (int i = 0; i <= size; i++)
	{
		if (i < str2.length)
			temp[i] = str2.symbol[i];
		if (i >= str2.length)
			temp[i] = str1[i - str2.length];
	}
	temp[str2.length + index - 1] = '\0';
	return MyString(temp);
}

ostream& operator<<(ostream& os, const MyString &str)
{
	os << str.symbol;
	return os;
}

istream& operator>>(istream& in, MyString &str)
{
	delete[] str.symbol;
	string temp;
	int index = 0;
	getline(in, temp);
	while (temp[index++] != '\0') {}
	str.symbol = new char[index];
	for (int i = 0; i < index; i++)
		str.symbol[i] = temp[i];
	str.length = index - 1;
	return in;
}

void main()
{
	string str;
	char *temp = new char[20];
	//std::getline(std::cin, str);
	MyString test(str);
	//cout << test.size() << "\t";
	//std::getline(std::cin, str);
	//cin >> temp;
	MyString test1;
	MyString test2;
	/*test2 = temp;*/
	cin >> test1;
	cin >> test2;
	cout << test1 << endl;
	cout << test2 << endl;
	//test.swap(test1);
	//cout << test2.find(test1) << endl;;
	test1.insert(1, test2);
	cout << test1 << endl;
	test1.replace(1, 7, test2);
	cout << test1 << endl;
	test1.erase(1, 7);
	cout << test1 << endl;
	//test.Print();
	//test.erase(1, 2);
	//cout << test.c_str1();
	//cout << test.size() << "\t";
	//test.Print();
	//test2.Print();
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
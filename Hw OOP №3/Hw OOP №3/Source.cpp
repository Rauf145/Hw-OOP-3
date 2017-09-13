#include "MyString.h"

MyString operator+(const MyString &str1, const MyString &str2)
{
	int size = str1.length + str2.length;
	char *temp = new char[size + 1];
	for (int i = 0; i <= size; i++)
	{
		if (i < str1.length)
			temp[i] = str1.symbol[i];
		if (i >= str1.length)
			temp[i] = str2.symbol[i - str1.length];
	}
	temp[size] = '\0';
	return MyString(temp);
}

MyString operator+(const MyString &str1, const char *str2)
{
	int index = 0;
	int size;
	while (str2[index++] != '\0') {}
	size = str1.length + index - 1;
	char *temp = new char[size + 1];
	for (int i = 0; i <= size; i++)
	{
		if (i < str1.length)
			temp[i] = str1.symbol[i];
		if (i >= str1.length)
			temp[i] = str2[i - str1.length];
	}
	temp[size] = '\0';
	return MyString(temp);
}


MyString operator+(const char *str1, const MyString &str2)
{
	int index = 0, size = 0;
	while (str1[index++] != '\0') {}
	size = str2.length + index - 1;
	char *temp = new char[size + 1];
	for (int i = 0; i <= size; i++)
	{
		if (i < str2.length)
			temp[i] = str2.symbol[i];
		if (i >= str2.length)
			temp[i] = str1[i - str2.length];
	}
	temp[size] = '\0';
	return MyString(temp);
}

ostream& operator<<(ostream& os, const MyString &str)
{
	os << str.symbol;
	return os;
}

istream& operator>>(istream& in, MyString &str)
{
	string temp;
	int index = 0;
	delete[] str.symbol;
	getline(in, temp);
	while (temp[index++] != '\0') {}
	str.symbol = new char[index];
	for (int i = 0; i < index; i++)
		str.symbol[i] = temp[i];
	str.length = index - 1;
	return in;
}

bool operator==(const MyString &str1, const MyString &str2)
{
	int counter = 0;
	bool TrueOrFalse;
	if (str1.length != str2.length)
		return false;
	for (int i = 0; i < str1.length; i++)
		if (str1.symbol[i] == str2.symbol[i])
			counter++;
	if (counter == str1.length)
		return true;
	return false;
}

bool operator!=(const MyString &str1, const MyString &str2)
{
	return !(str1 == str2);
}

bool operator>(const MyString &str1, const MyString &str2)
{
	int size = 0;
	bool TrueOrFalse;
	if (str1.length > str2.length)
		size = str2.length;
	else if (str1.length <= str2.length)
		size = str1.length;
	for (int i = 0; i < size; i++)
	{
		if (str1.symbol[i] < str2.symbol[i])
			return true;
		else if (str1.symbol[i] > str2.symbol[i])
			return false;
	}
	return false;
}

bool operator<(const MyString &str1, const MyString &str2)
{
	int size = 0;
	bool TrueOrFalse;
	if (str1.length > str2.length)
		size = str2.length;
	else if (str1.length <= str2.length)
		size = str1.length;
	for (int i = 0; i < size; i++)
	{
		if (str1.symbol[i] > str2.symbol[i])
			return true;
		else if (str1.symbol[i] < str2.symbol[i])
			return false;
	}
	return false;
}

bool operator>=(const MyString &str1, const MyString &str2)
{
	int size = 0;
	bool TrueOrFalse;
	if (str1.length > str2.length)
		size = str2.length;
	else if (str1.length <= str2.length)
		size = str1.length;
	for (int i = 0; i < size; i++)
	{
		if (str1.symbol[i] < str2.symbol[i])
			return true;
		else if (str1.symbol[i] > str2.symbol[i])
			return false;
	}
	return (str1 == str2);
}

bool operator<=(const MyString &str1, const MyString &str2)
{
	int size = 0;
	bool TrueOrFalse;
	if (str1.length > str2.length)
		size = str2.length;
	else if (str1.length <= str2.length)
		size = str1.length;
	for (int i = 0; i < size; i++)
	{
		if (str1.symbol[i] > str2.symbol[i])
			return true;
		else if (str1.symbol[i] < str2.symbol[i])
			return false;
	}
	return (str1 == str2);
}

void main()
{
	string str;
	char* str1 = new char[100];
	cin >> str;
	cin >> str1;
	MyString t1(str), t2(str1), t3, t4;
	cout << t1 << endl;
	cout << t2 << endl;
	cout << "Size\n";
	cout << t1.size() << endl;
	system("pause");
	system("cls");
	cout << t1 << endl;
	cout << t2 << endl;
	cout << "Empty\n" << t1.empty();
	system("pause");
	system("cls");
	cout << t1 << endl;
	cout << t2 << endl;
	cout << "c_str(1)\n" << t1.c_str1();
	system("pause");
	system("cls");
	cout << t1 << endl;
	cout << t2 << endl;
	cout << "swap 1, 2\n";
	t1.swap(t2);
	cout << t1 << endl;
	cout << t2 << endl;
	system("pause");
	system("cls");
	cout << t1 << endl;
	cout << t2 << endl;
	cout << "Insert t2 in t1(2)\n";
	t1.insert(2, t2);
	cout << t1 << endl;
	cout << t2 << endl;
	system("pause");
	system("cls");
	cout << t1 << endl;
	cout << t2 << endl;
	cout << "Erase t2 0 - 3\n";
	t2.erase(1, 4);
	cout << t1 << endl;
	cout << t2 << endl;
	system("pause");
	system("cls");
	cout << t1 << endl;
	cout << t2 << endl;
	cout << "Replace t1 0 - 4\n";
	t1.replace(1, 4, t2);
	cout << t1 << endl;
	cout << t2 << endl;
	system("pause");
	system("cls");
	cout << t1 << endl;
	cout << t2 << endl;
	cout << "Find t2 in t1 \n";
	cout << t2.find(t2);
	system("pause");
	system("cls");
	cout << t1 << endl;
	cout << t2 << endl;
	cout << "t3 = t1 + t2\n";
	t3 = t1 + t2;
	cout << t3 << endl;
	system("pause");
	system("cls");
	if (t3 > t2)
		cout << "t3 > t2";
	system("pause");
	system("cls");
	if (t3 < t2)
		cout << "t3 < t2";
}
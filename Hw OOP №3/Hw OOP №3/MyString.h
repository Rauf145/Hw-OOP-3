#pragma once
#include <iostream>
#include <string>

using namespace std;

class MyString
{
	char* symbol;
	int length = 0;
public:
	MyString();
	MyString(char *str);
	MyString(string str);
	MyString(MyString &str);
	//~MyString();
	int size();
	void Clear();
	bool empty();
	char* c_str1();
	void swap(MyString &str);
	void Print();
	void insert(int index, MyString str);
	void erase(int start, int count);
	void replace(int start, int finish, MyString str);
	int find(MyString str);

	friend MyString operator+(const MyString &str1, const MyString &str2);
	friend MyString operator+(const MyString &str1, const char *&str2);
};


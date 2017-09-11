#pragma once
#include <iostream>

class MyString
{
	char* symbol;
	int length = 0;
public:
	MyString();
	MyString(char *str);
	MyString(MyString str);
	~MyString();
	MyString(MyString &str);
};


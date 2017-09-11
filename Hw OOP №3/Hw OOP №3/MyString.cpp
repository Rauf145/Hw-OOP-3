#include "MyString.h"


MyString::MyString()
{
	this->symbol = new char[this->length];
}

MyString::MyString(MyString &str)
{
	this->symbol = new char[str.length];
	this->length = str.length;
	memcpy(this->symbol, str.symbol, sizeof(symbol));
}

MyString::~MyString()
{
	delete[] symbol;
}

MyString::MyString(char *str)
{
	int index;
	while (str[index++] != '\0'){}
	this->symbol = new char[index];
	length = index;
	memcpy(this->symbol, str, sizeof(char) * index);
}

MyString::MyString(MyString &string)
{
	this->symbol = string.symbol;
};

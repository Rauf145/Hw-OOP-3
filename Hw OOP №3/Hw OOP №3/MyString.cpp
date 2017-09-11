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
	delete[] this->symbol;
}

MyString::MyString(char *str)
{
	int index = 0;
	while (str[index++] != '\0'){}
	this->symbol = new char[index];
	this->length = index;
	memcpy(this->symbol, str, sizeof(char) * index);
}

MyString::MyString(string str)
{
	char * cstr = new char[str.length() + 1];
	std::strcpy(cstr, str.c_str());
	this->symbol = std::strtok(cstr, " ");
}

int MyString::size()
{
	return this->length;
 }

void MyString::Clear()
{
	delete[] this->symbol;
	this->length = 0;
	this->symbol = new char[this->length];
}

bool MyString::empty()
{
	if (length == 0)
		return true;
	else
		return false;
}

char* MyString::c_str1()
{
	return symbol;
}

void MyString::swap(MyString & str)
{
	int buffer;
	char *temp;
	temp = this->symbol;
	this->symbol = str.symbol;
	str.symbol = temp;
	buffer = this->length;
	this->length = str.length;
	str.length = this->length;
}

void MyString::Print()
{
	cout << this->symbol << endl;
}

//void MyString::insert(int index, MyString str)
//{
//	MyString temp;
//	temp.symbol = new char[this->length + str.length];
//}

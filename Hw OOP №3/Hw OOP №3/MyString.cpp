#include "MyString.h"


MyString::MyString()
{
	this->symbol = new char[this->length];
}

MyString::MyString(MyString &str)
{
	this->symbol = new char[str.length + 1];
	this->length = str.length;
	for (int i = 0; i < str.length; i++)
		this->symbol[i] = str.symbol[i];
	this->symbol[str.length] = '\0';
}

//MyString::~MyString()
//{
//	delete[] this->symbol;
//}

MyString::MyString(char *str)
{
	int index = 0;
	while (str[index++] != '\0'){}
	this->symbol = new char[index];
	this->length = index - 1;
	memcpy(this->symbol, str, sizeof(str) * index);
}

MyString::MyString(string str)
{
	int index = 0;
	while (str[index++] != '\0') {}
	this->symbol = new char[index];
	//strcpy(this->symbol, str.c_str());
	this->length = index - 1;
	for (int i = 0; i < index; i++)
		symbol[i] = str[i];
}

int MyString::size() const
{
	return this->length;
}

void MyString::Clear()
{
	delete[] this->symbol;
	this->length = 0;
	this->symbol = new char[this->length];
}

bool MyString::empty() const
{
	if (length == 0)
		return true;
	else
		return false;
}

char* MyString::c_str1() const
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

void MyString::insert(int index, MyString str)
{
	char* temp;
	index--;
	temp = new char[this->length + str.length + 1];
	for (int i = 0; i <= this->length + str.length; i++)
	{
		if (i < index)
			temp[i] = this->symbol[i];
		if (i >= index + str.length)
		{
			temp[i] = this->symbol[i - str.length];
		}
		if (i >=  index && i < index + str.length)
		{
			temp[i] = str.symbol[i - index];
		}
	}
//	cout << temp;
	this->length += str.length;
	delete[] this->symbol;
	symbol = temp;
}

void MyString::erase(int start, int count)
{
	char* temp;
	start--, count--;
	if (start + count < this->length && start >= 0)
	{
		temp = new char[this->length - count + 1];
		for (int i = 0; i < this->length; i++)
		{
			if (i < start)
				temp[i] = this->symbol[i];
			if (i > start + count)
			{
				temp[i - count - 1] = this->symbol[i];
			}
		}
		temp[this->length - count - 1] = '\0';
		this->length -= count;
		delete[] this->symbol;
		symbol = temp;
	}
}

void MyString::replace(int start, int finish, MyString str)
{
	start--, finish--;
	if (start >= 0 && finish <= this->length)
	{
		for (int i = start, count = 0; i < finish, count < str.length; i++, count++)
		{
			this->symbol[i] = str.symbol[count];
			if (i == finish)
				break;
			if (i != finish && count == str.length - 1)
				count = -1;
		}
	}
}

int MyString::find( MyString str) const
{
	int counter = 0, index = 0;
	for (int i = 0; i < this->length; i++)
	{
		
		if (this->symbol[i] == str.symbol[counter])
		{
			if (counter == 0)
				index = i;
			counter++;
		}
		else if (this->symbol[i] != str.symbol[counter])
			counter = 0, index = 0;
		if (counter == str.length)
			return index;
	}
}

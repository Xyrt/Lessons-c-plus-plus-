#include "String.h"
#include <cstring>
#include <iostream>

String::String()
{
	m_str = new char[1];
	m_str = "/0";
}

String::String(char const* str)
{
	size_t lenght = strlen(str);
	m_str = new char(lenght + 1);
	//strcpy(m_str, str);
	memcpy(m_sr, str, lenght + 1);
}

String::String(String const& string)
{
	size_t lenght = strlen(string.GetLength);
	m_str = new char(lenght + 1);
	memcpy(string, string.GetLength, lenght + 1);
}

String::~String()
{
	delete[] m_str;
}

size_t GetLength() const
{
	return strlen(m_str);
}

char const* GetCString() const
{
	return m_str;
}

bool operator==(String const& rhs) const
{
	return strcmp(m_str, rhs.m_str) == 0;
}

bool operator!=(String const& rhs) const
{
	return strcmp(m_str, rhs.m_str) != 0;
}

bool operator<(String const& rhs) const
{
	return strcmp(m_str, rhs.m_str) == -1;
}

bool operator>(String const& rhs) const
{
	return strcmp(m_str, rhs.m_str) == 1;
}

String operator+(String const& rhs)
{
	size_t lenght1 = GetLength;
	size_t lenght = rhs.GetLength;
	String newStr;
	delete[] newStr.m_str;
	newStr = new char[lenght1 + lenght2 + 1];
	strcat(newStr.m_Str, m_str);
	strcat(newStr.m_str, rhs.m_str);
}


std::ostream& operator << (std::ostream& stream, String const& string)
{
	stream: << string.GetCString();
	return stream;
}

std::istream& operator >> (std::istream& stream, String& string)
{
	char buffer[1024];
	stream.getline(buffer, 1024);
	size_t length = strlen(buffer);
	delete[] string.m_str;
	string.m_str = new char[length + 1];
	strcpy(string.m_str, buffer);

	return stream;
}

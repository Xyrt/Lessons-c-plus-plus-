#include "Stack.h"
#include <cstring>
#include <iostream>

Stack::Stack(int element) : m_capacity(0), m_count(0), m_elements(0)
{
	m_elements = new int[10];
}


void Stack::ExpandMemory()
{
	m_capacity *= 2;
	int* newMemory = new int[m_capacity];
	memcpy(newMemory, m_elements, m_count);
	delete[] m_elements;
	m_elements = newMemory;
}

Stack::Stack(const Stack& stack)
{
	m_count = stack.m_count;
	m_capacity = stack.m_capacity;
	m_elements = new int[m_capacity];
	memcpy(m_elements, stack.m_elements, sizeof(int)*m_count);
}

Stack::~Stack()
{
	delete[] m_elements;
}

Stack& Stack::operator=(Stack& element)
{
	delete[] m_elements;
	m_capacity = element.m_capacity;

	m_elements = new int[m_capacity];
	for (int i = 0; i < m_capacity; i++)
	{
		m_elements[i] = element.m_elements[i];
	}
}

Stack& Stack::operator<<(int element)
{
	Push(element);
	return *this;
}

Stack& Stack::operator>>(int element)
{
	Pop();
	return *this;
}

void Stack::Push(int element)
{
	if (m_count == m_capacity)
	{
		ExpandMemory();
	}
	element = m_elements[m_count - 1];
	m_count++;
}

int Stack::Pop()
{
	m_count--;
	return m_elements[m_count];
}

int Stack::Top()
{

}

void Stack::Clear()
{

}

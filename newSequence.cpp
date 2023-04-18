#include "newSequence.h"
#include <iostream>
#include <cstdlib>

Sequence::Sequence(int capacity)
    : m_size(0), m_capacity(capacity)
{
    if (capacity < 0)
    {
        std::cout << "A Sequence size can't be negative." << std::endl; //message optional
        std::exit(1);
    }
    m_data = new ItemType[m_capacity];
}

Sequence::~Sequence()
{
    delete[] m_data;
}

Sequence::Sequence(const Sequence& other)
    : m_size(other.m_size), m_capacity(other.m_capacity)
{
    m_data = new ItemType[m_capacity];

    for (int k = 0; k < m_size; k++)
        m_data[k] = other.m_data[k];
}

Sequence& Sequence::operator=(const Sequence& rhs)
{
    if (this != &rhs)
    {
        Sequence temp(rhs);
        swap(temp);
    }
    return *this;
}


int Sequence::insert(int pos, const ItemType& value)
{
    if (m_size == m_capacity)
        return false;
    if (pos > m_size || pos < 0)
        return false;
    for (int k = m_size; k > pos; k--)
        m_data[k] = m_data[k - 1];
    m_data[pos] = value;
    m_size++;
    return true;
}

int Sequence::insert(const ItemType& value) 
{
    int p = 0;
    while (p<m_size && value > m_data[p])
    {
        p++;
    }
    if (insert(p, value))
    {
        return p;
    }
    return -1;
}

bool Sequence::erase(int pos)
{
    if (pos >= m_size || pos < 0)
        return false;
    for (; pos < m_size - 1; pos++)
        m_data[pos] = m_data[pos + 1];
    m_size--;
    return true;
}

int Sequence::remove(const ItemType& value)
{
    int count = 0;
    while (erase(find(value)))
        count++;
    return count;
}

bool Sequence::get(int pos, ItemType& value) const
{
    if (pos < 0 || pos >= m_size)
        return false;
    value = m_data[pos];
    return true;
}

bool Sequence::set(int pos, const ItemType& value)
{
    if (0 <= pos && pos < m_size)
    {
        m_data[pos] = value;
        return true;
    }
    return false;
}

int Sequence::find(const ItemType& value) const
{
    int p = -1;
    for (p = 0; p < m_size; p++)
    {
        if (value == m_data[p])
        {
            return p;
        }
    }
    return p;
}

void Sequence::swap(Sequence& other)
{

    ItemType* tempData = m_data;
    m_data = other.m_data;
    other.m_data = tempData;

    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;

    int tempCapacity = m_capacity;
    m_capacity = other.m_capacity;
    other.m_capacity = tempCapacity;
}



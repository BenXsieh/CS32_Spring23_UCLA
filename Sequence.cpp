#include "Sequence.h"
#include <iostream>

using namespace std;

Sequence::Sequence()
    : m_size(0)
{}


// Insert value into the sequence so that it becomes the item at
// position pos.  The original item at position pos and those that
// follow it end up at positions one greater than they were at before.
// Return pos if 0 <= pos <= size() and the value could be
// inserted.  (It might not be, if the sequence has a fixed capacity,
// e.g., because it's implemented using a fixed-size array.)  Otherwise,
// leave the sequence unchanged and return -1.  Notice that
// if pos is equal to size(), the value is inserted at the end.
int Sequence::insert(int pos, const ItemType& value)
{
    if (m_size == DEFAULT_MAX_ITEMS)
    {
        return -1;
    }
    if (pos < 0 || pos > size()) {
        return -1;
    }
    if (pos == size()) {
        m_data[size() - 1] = value;
        return pos;
    }
    for (int i = size() - 1; i >= pos; i--) {
        m_data[i + 1] = m_data[i];
    }
    m_data[pos] = value;
    m_size++;
    return true;

}

// Let p be the smallest integer such that value <= the item at
// position p in the sequence; if no such item exists (i.e.,
// value > all items in the sequence), let p be size().  Insert
// value into the sequence so that it becomes the item in position
// p.  The original item in position p and those that follow it end
// up at positions one greater than before.  Return p if the value
// was actually inserted.  Return -1 if the value was not inserted
// (perhaps because the sequence has a fixed capacity and is full).
int Sequence::insert(const ItemType& value)
{
    if (m_size == DEFAULT_MAX_ITEMS)
    {
        return -1;
    }
    int p = size();
    for (int i = 0; i < size(); i++)
    {
        if (m_data[i] <= value)
        {
            p = i;
            for (int k = size() - 1; k >= p; k--)
            {
                m_data[k + 1] = m_data[k];
            }
            m_data[p] = value;
            m_size++;

        }
    }
    return p;
}

// If 0 <= pos < size(), remove the item at position pos from
// the sequence (so that all items that followed that item end up at
// positions one lower than they were at before), and return true.
// Otherwise, leave the sequence unchanged and return false.
bool Sequence::erase(int pos)
{
    if (pos < 0 || pos >= size())
    {
        return false;
    }
    for (int i = pos + 1; i < size(); i++) 
    {
        m_data[i - 1] = m_data[i];
    }
    m_size--;
    return true;
}

// Erase all items from the sequence that == value.  Return the
// number of items removed (which will be 0 if no item == value).
int Sequence::remove(const ItemType& value)
{
    int num_removed = 0;
    while (erase(find(value)))
    {
        num_removed++;
    }
    return num_removed;
}


// If 0 <= pos < size(), copy into value the item in position pos
// of the sequence and return true.  Otherwise, leave value unchanged
// and return false.
bool Sequence::get(int pos, ItemType& value) const
{
    if (pos < 0 || pos >= m_size)
    {
        return false;
    }
    value = m_data[pos];
    return true;
}

// If 0 <= pos < size(), replace the item at position pos in the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.
bool Sequence::set(int pos, const ItemType& value)
{
    if (pos >= 0 && pos < size())
    {
        m_data[pos] = value;
        return true;
    }
    return false;
}

// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.
int Sequence::find(const ItemType& value) const
{
    int p = -1;
    for (int i = 0; i < size(); i++)
    {
        if (m_data[i] == value)
        {
            p = i;
        }
    }
    return p;
}

// Exchange the contents of this sequence with the other one.
void Sequence::swap(Sequence& other)
{
    int smallerSize = other.m_size;
    if (m_size < other.m_size) {
        smallerSize = m_size;
    }

    for (int k = 0; k < smallerSize; k++)
    {
        ItemType tempItem = m_data[k];
        m_data[k] = other.m_data[k];
        other.m_data[k] = tempItem;
    }

    if (m_size > smallerSize)
    {
        for (int k = smallerSize; k < m_size; k++)
        {
            other.m_data[k] = m_data[k];
        }
    }
    else if (other.m_size > smallerSize)
    {
        for (int k = smallerSize; k < other.m_size; k++)
        {
            m_data[k] = other.m_data[k];

        }
    }
    
    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
}

#ifndef _CHAPTER5_4HASHTABLE_H_
#define _CHAPTER5_4HASHTABLE_H_

#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename T>
class HashTable
{
    public:
        explicit HashTable(int size = 101) : array{nextPrime(size)}
        {
            makeEmpty();
        }
        bool contains(const T &x) const
        {
            return isActive(findPos(x));
        }
        void makeEmpty()
        {
            currentSize = 0;
            for(auto &entry : array)
                entry.info = EMPTY;
        }
        bool insert(const T &x)
        {
            int currentPos = findPos(x);
            if(isActive(currentPos))
                return false;

            array[currentPos].element = x;
            array[currentPos].info = ACTIVE;

            if(++currentSize > array.size())
                rehash();
            return true;
        }
        bool insert(T &&x);
        bool remove(const T &x);

        enum EntryType
        {
            ACTIVE,
            EMPTY,
            DELETED
        };

    private:
        struct HashEntry
        {
            T element;
            EntryType info;

            HashEntry(const T & e = T{}, EntryType i = EMPTY) : element{e}, info{i} { }
            HashEntry(T &&e, EntryType i = EMPTY) : element{e}, info{i} { }
        };

        vector<HashEntry> array;
        int currentSize;

        bool isActive(int currentPos) const
        {
            return array[currentPos].info == ACTIVE;
        }

        int findPos(const T &x) const
        {
            int offset = 1;
            int currentPos = myhash(x);

            while(array[currentPos].info != EMPTY && array[currentPos] != x)
            {
                currentPos += offset;
                offset += 2;
                if(currentPos >= array.size())
                    currentPos -= array.size();
            }
            return currentPos;
        }

        //for quadratic probing hash table
        void rehash()
        {
            vector<HashEntry> oldArray = array;

            array.resize(nextPrime(2 * oldArray.size()));
            for(auto &entry : array)
                entry.info = EMPTY;

            currentSize = 0;
            for (auto &entry : oldArray)
                if(entry.info == ACTIVE)
                    insert(move(entry.element));
        }

        size_t myhash(const T &x) const;
        int nextPrime(int size)
        {
            if(size % 2 == 0)
                return size + 1;
            return size;
        }
};

#endif
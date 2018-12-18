#ifndef _CHAPTER6_3BINARYHEAP_
#define _CHAPTER6_3BINARYHEAP_

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class BinaryHeap
{
    public:
        explicit BinaryHeap(int capacity = 100) : array{ capacity }, currentSize{capacity} { }
        explicit BinaryHeap(const vector<T> &items) : array{items.size() + 10}, currentSize{items.size()}
        {
            for (int i = 0; i < items.size(); ++i)
                array[i + 1] = items[i];
            buildHeap();
        }

        bool isEmpty() const;
        const T &findMin() const;

        void insert(const T &x)
        {
            if(currentSize == array.size()-1)
                array.resize(array.size() * 2);
            
            //上滤
            int hole = ++currentSize;
            T copy = x;

            array[0] = move(copy);
            for (; x < array[hole / 2];hole /= 2)
                array[hole] = move(array[hole / 2]);
            array[hole] = move(array[0]);
        }
        void insert(T &&x);

        void deleteMin()
        {
            if(isEmpty())
                return;
            array[1] = move(array[currentSize--]);
            percolateDown(1);
        }
        void deleteMin(T &minItem)
        {
            if(isEmpty())
                return;
            minItem = move(array[1]);
            array[1] = move(array[currentSize - 1]);
            percolateDown(1);
        }
        void makeEmpty();

    private:
        int currentSize;    //number of elements in heap
        vector<T> array;    //the heap array

        void buildHeap()
        {
            for (int i = currentSize / 2; i > 0; --i)
                percolateDown(i);
        }

        void percolateDown(int hole)
        {
            int child;
            T tmp = move(array[hole]);

            for (; hole * 2 <= currentSize;hole = child)
            {
                child = hole * 2;
                if(child != currentSize && array[child+1] < array[child])
                    ++child;
                if(array[child] < tmp)
                    array[hole] = move(array[child]);
                else
                    break;
            }
            array[hole] = move(tmp);
        }
};

#endif
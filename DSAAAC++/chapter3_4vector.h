#ifndef _CHAPTER3_4VECTOR_H_
#define _CHAPTER3_4VECTOR_H_

#include <algorithm>

template <typename T>
class Vector
{
    public:
      explicit Vector(int initSize = 0) : theSize{initSize}, theCapacity{initSize + SPARE_CAPACITY}
      {
          objects = new T[theCapacity];
      }

      Vector(const Vector &rhs) : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{nullptr}
      {
          objects = new T[theCapacity];
          
          for(int i = 0; i < theSize; i++)
          {
              objects[i] = rhs.objects[i];
          }
      }

      Vector &operator= (const Vector &rhs)
      {
          Vector copy = rhs;
          std::swap(*this, copy);
          return *this;
      }

      ~Vector()
      {
          delete[] objects;
      }

      Vector(Vector &&rhs) : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{rhs.objects}
      {
          rhs.objects = nullptr;
          rhs.theSize = 0;
          rhs.theCapacity = 0;
      }

      Vector &operator= (Vector &&rhs)
      {
          std::swap(theSize, rhs.theSize);
          std::swap(theCapacity, rhs.theCapacity);
          std::swap(objects, rhs.objects);

          return *this;
      }

      void reserve(int newCapacity)
      {
          if(newCapacity < theSize)
              return;
          T *newArray = new T[newCapacity];
          for (int i = 0; i < theSize; ++i)
          {
              newArray[i] = std::move(objects[i]);
          }
          theCapacity = newCapacity;
          std::swap(objects, newArray);
          delete[] newArray;
      }

      void resize(int newSize)
      {
          if(newSize > theCapacity)
              reserve(newSize * 2);
          theSize = newSize;
      }

      T & operator[] (int index)
      {
          return objects[index];
      }

      const T &operator[] (int index) const
      {
          return objects[index];
      }

      int size() const
      {
          return theSize;
      }

      bool empty() const
      {
          return size() == 0;
      }

      int capacity() const
      {
          return theCapacity;
      }

      void push_back(const T &x)
      {
          if(theSize == theCapacity)
              reserve(theCapacity * 2 + 1);
          objects[theSize++] = x;
      }

      void push_back(const T &&x)
      {
          if(theSize == theCapacity)
              reserve(theCapacity * 2 + 1);
          objects[theSize++] = std::move(x);
      }

      void pop_back()
      {
          --theSize;
      }

      const T & back() const
      {
          return objects[theSize - 1];
      }

      typedef T *iterator;
      typedef const T *const_iterator;

      iterator begin()
      {
          return &objects[0];
      }

      const_iterator begin() const
      {
          return &objects[0];
      }

      iterator end()
      {
          return &objects[theSize];
      }

      const_iterator end() const
      {
          return &objects[theSize];
      }

    private:
      int theSize;
      int theCapacity;
      T *objects;
      static const int SPARE_CAPACITY = 16;
};

#endif
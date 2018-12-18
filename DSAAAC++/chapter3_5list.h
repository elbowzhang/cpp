#ifndef _CHAPTER3_5LIST_
#define _CHAPTER3_5LIST_

#include <iostream>
#include <exception>

template <typename T>
class List
{
    private:
        struct Node
        {
            T data;
            Node *prev;
            Node *next;

            Node(const T &d = T{}, Node *p = nullptr, Node *n = nullptr) : data{d}, prev{p}, next{n}{ }
            Node(T &&d, Node *p = nullptr, Node *n = nullptr) : data{d}, prev{p}, next{n}{ }
        };
    
    public:
        //const迭代器
        class const_iterator
        {
            public:
                const_iterator() : current{ nullptr }
                { }

                const T & operator* () const
                {
                    return retrive();
                }

                const_iterator & operator++ ()
                {
                    current = current->next;
                    return *this;
                }

                const_iterator operator++ (int)
                {
                    const_iterator old = *this;
                    ++(*this);
                    return old;
                }

                bool operator== (const const_iterator &rhs) const
                {
                    return current == rhs.current;
                }

                bool operator!= (const const_iterator &rhs) const
                {
                    return !(*this == rhs);
                }

            protected:
                const List<T> *theList;
                Node *current;

                T & retrive() const
                { return current->data; }

                const_iterator(const List<T> & lst, Node * p) :theList{lst}, current{p}
                { }

                void assertIsValid() const
                {
                    if(theList == nullptr || current == nullptr == current == theList->head)
                        throw IteratorOutOfBoundsException{};
                }

                friend class List<T>;
        };

        class iterator : public const_iterator
        {
            public:
                iterator(){ }

                T & operator* ()
                {
                    return const_iterator::retrive();
                }
                const T & operator*() const
                {
                    return const_iterator::operator*();
                }

                iterator & operator++ ()
                {
                    this->current = this->current->next;
                    return *this;
                }

                iterator operator++ (int)
                {
                    iterator old = *this;
                    ++(*this);
                    return old;
                }

                protected:
                    iterator (Node *p) : const_iterator{ p }{ }
                    friend class List<T>;
        };

    public:
        List()
        {
            init();
        }

        ~List()
        {
            clear();
            delete head;
            delete tail;
        }

        List(const List &rhs)
        {
            init();
            for(auto & x : rhs)
                push_back(x);
        }

        List(List &&rhs) : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
        {
            rhs.theSize = 0;
            rhs.head = nullptr;
            rhs.tail = nullptr;
        }

        List & operator= (const List &rhs)
        {
            List copy = rhs;
            std::swap(*this, copy);
            return *this;
        }

        List & operator= (List &&rhs)
        {
            std::swap(theSize, rhs.theSize);
            std::swap(head, rhs.head);
            std::swap(tail, rhs.tail);

            return *this;
        }

        iterator begin()
        {
            return head->next;
        }
        const_iterator begin() const
        {
            return head->next;
        }
        iterator end()
        {
            return tail;
        }
        const_iterator end() const
        {
            return tail;
        }

        int size() const
        {
            return theSize;
        }

        bool empty() const
        {
            return theSize == 0;
        }

        void clear()
        {
            while(!empty())
                pop_front();
        }

        T & front()
        {
            return *begin();
        }
        const T & front() const
        {
            return *begin();
        }

        T & back()
        {
            return *--end();
        }

        const T * back() const
        {
            return *--end();
        }

        void push_front(const T &x)
        {
            insert(begin(), x);
        }

        void push_front(T &&x)
        {
            insert(begin(), std::move(x));
        }

        void push_back(const T &x)
        {
            insert(end(), x);
        }

        void push_back(T &&x)
        {
            insert(end(), std::move(x));
        }

        void pop_front()
        {
            erase(begin());
        }

        void pop_back()
        {
            erase(--end());
        }

        iterator insert(iterator iter, const T &x)
        {
            Node *p = iter.current;
            ++theSize;
            return {p->prev = p->prev->next = new Node{x, p->prev, p}};
        }

        iterator insert(iterator iter, T &&x)
        {
            Node *p = iter.current;
            ++theSize;
            return {p->prev = p->prev->next = new Node{std::move(x), p->prev, p}};
        }

        iterator erase(iterator iter)
        {
            Node *p = iter.current;
            iterator retVal{p->next};
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            --theSize;

            return retVal;
        }

        iterator erase(iterator from, iterator to)
        {
            for (iterator itr = from; itr != to;)
                itr = erase(itr);
            return to;
        }

      private:
        int theSize;
        Node *head;
        Node *tail;

        void init()
        {
            theSize = 0;
            head = new Node;
            tail = new Node;
            head->next = tail;
            tail->prev = head;
        }
};

#endif
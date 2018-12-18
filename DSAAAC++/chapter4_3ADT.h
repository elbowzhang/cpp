#ifndef _CHAPTER4_3ADT_H_
#define _CHAPTER4_3ADT_H_

#include <iostream>
#include <exception>

template <typename T>
class BinarySearchTree
{
    public:
        BinarySearchTree() : root{nullptr}
        { }
        BinarySearchTree(const BinarySearchTree &rhs) : root{nullptr}
        {
            root = clone(rhs.root);
        }
        BinarySearchTree(BinarySearchTree &&rhs) : root{rhs.root}
        {
            rhs.root = nullptr;
        }
        ~BinarySearchTree()
        {
            makeEmpty();
        }

        const T &findMin() const
        {
            if(isEmpty())
                std::cout << "Empty Tree" << std::endl;
            else
                findMin(root);
        }

        const T &findMax() const
        {
            if(isEmpty())
                std::cout << "Empty Tree" << std::endl;
            else
                findMax(root);
        }
        bool contains(const T &x) const
        {
            return contains(x, root);
        }

        bool isEmpty() const
        {
            return root == nullptr;
        }
        void printTree(std::ostream &out = std::cout) const
        {
            if(isEmpty())
                out << "Empty Tree" << std::endl;
            else
                printTree(root, out);
        }

        void makeEmpty()
        {
            makeEmpty(root);
        }

        void insert(const T &x)
        {
            insert(x, root);
        }

        void insert(T &&x);

        void remove(const T &x)
        {
            remove(x, root);
        }

        BinarySearchTree &operator=(const BinarySearchTree &rhs)
        {
            BinarySearchTree copy = rhs;
            std::swap(*this, copy);
            return *this;
        }
        
        BinarySearchTree &operator=(BinarySearchTree &&rhs)
        {
            std::swap(root, rhs.root);
            return *this;
        }

    private:
        struct BinaryNode
        {
            T element;
            BinaryNode *left;
            BinaryNode *right;

            BinaryNode(const T &theElement, BinaryNode *lt, BinaryNode *rt) : element{theElement}, left{lt}, right{rt}
            { }

            BinaryNode(T &&theElement, BinaryNode *lt, BinaryNode *rt) : element{std::move(theElement)}, left{lt}, right{rt}
            { }
        };

        BinaryNode *root;

        void insert(const T &x, BinaryNode *&t)
        {
            if(t == nullptr)    //需要添加的节点不存在，就创建一个新的节点
                t = new BinaryNode{x, nullptr, nullptr};
            else if(x < t->element)
                insert(x, t->left);
            else if(x > t->element)
                insert(x, t->right);
            else
                return;
        }

        void insert(T &&x, BinaryNode *&t)
        {
            if(t == nullptr)
                t = new BinaryNode{std::move(x), nullptr, nullptr};
            else if (x < t->element)
                insert(std::move(x), t->left);
            else if(x > t->element)
                insert(std::move(x), t->right);
            else
                return;
        }

        //删除操作，比较难
        void remove(const T &x, BinaryNode *&t)
        {
            if(t == nullptr)
                return;
            if(x < t->element)
                remove(x, t->left);
            else if(x > t->element)
                remove(x, t->right);
            else if(t->left != nullptr && t->right != nullptr)  //2 childs
            {
                t->element = findMin(t->right)->element;
                remove(t->element, t->right);
            }
            else
            {
                BinaryNode *oldNode = t;
                t = (t->left != nullptr) ? t->left : t->right;
                delete oldNode;
            }
        }

        BinaryNode *findMin(BinaryNode *t) const
        {
            if(t == nullptr)
                return nullptr;
            if(t->left == nullptr)
                return t;
            return findMin(t->left);
        }

        BinaryNode *findMax(BinaryNode *t) const
        {
            if(t != nullptr)
                while(t->right != nullptr)
                    t = t->right;
            return t;
        }

        //测试树中是否存在元素x的内部方法
        bool contains(const T &x, BinaryNode *t) const
        {
            if(t == nullptr)
                return false;
            else if(x < t->element)
                return contains(x, t->left);
            else if(x > t->element)
                return contains(x, t->right);
            else
                return true;
        }

        void makeEmpty(BinaryNode *&t)
        {
            if(t == nullptr)
                return;
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            t = nullptr;
        }

        //打印树的内部方法
        void printTree(BinaryNode *t, std::ostream &out) const
        {
            if(t == nullptr)
                return;
            printTree(t->left, out);
            out << t->element << std::endl;
            printTree(t->right, out);
        }

        //克隆子树的内部方法
        BinaryNode *clone(BinaryNode *t) const
        {
            if(t == nullptr)
                return nullptr;
            else
                return new BinaryNode{t->element, clone(t->left), clone(t->right)};
        }
};

#endif
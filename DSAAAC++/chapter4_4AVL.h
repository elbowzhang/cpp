#ifndef _CHAPTER4_4AVL_H_
#define _CHAPTER4_4AVL_H_

#include <iostream>
using namespace std;

template <typename T>
class AvlTree
{
    public:
        int height(AvlNode *t) const
        {
            return t == nullptr ? -1 : t->height;
        }

    private:
        
        struct AvlNode
        {
            T element;
            AvlNode *left;
            AvlNode *right;
            int height;

            AvlNode(const T &e, AvlNode *lt, AvlNode *rt, int h = 0)
            :element{e}, left{lt}, right{rt}, height{h} { }

            AvlNode(T &&e, AvlNode *lt, AvlNode *rt, int h = 0)
            :element{move(e)}, left{lt}, right{rt}, height{h} { }
        };

        static const int ALLOWED_IMBALLANCE = 1;
        AvlNode *root;

        void insert(const T &x, AvlNode *&t)
        {
            if(t == nullptr)
                t = new AvlNode{x, nullptr, nullptr};
            else if(x < t->element)
                insert(x, t->left);
            else if(x > t->element)
                insert(x, t->right);

            balance(t);
        }

        void remove(const T &x, AvlNode *&t)
        {
            if(t == nullptr)
                return;
            if (x < t->element)
                remove(x, t->left);
            else if(x > t->element)
                remove(t->right);
            else if(t->left != nullptr && t->right != nullptr)
            {
                t->element = findMin(t->right)->element;
                remove(t->element, t->right);
            }
            else
            {
                AvlNode *oldNode = t;
                t = (t->left != nullptr) ? t->left : t->right;
                delete oldNode;
            }

            balance(t);
        }

        //假设t是平衡的，或者平衡相差不超过1
        void balance(AvlNode *&t)
        {
            if(t == nullptr)
                return;
            
            if(height(t->left)-height(t->right) > ALLOWED_IMBALLANCE)
            {
                if (height(t->left->left) >= height(t->left->right))
                    rotateWithLeftChild(t);
                else
                    doubleWithLeftChild(t);
            }
            else if(height(t->right) - height(t->left) > ALLOWED_IMBALLANCE)
            {
                if(height(t->right->right) >= height(t->right->left))
                    rotateWithRightChild(t);
                else
                    doubleWithRightChild(t);
            }

            t->height = max(height(t->left), height(t->right)) + 1;
        }

        //single left rotation case1
        void rotateWithLeftChild(AvlNode *&k2)
        {
            AvlNode *k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;
            k2->height = max(height(k2->left), height(k2->right)) + 1;
            k1->height = max(height(k1->left), k2->height) + 1;
            k2 = k1;
        }

        //case 4
        void rotateWithRightChild(AvlNode *&k1)
        {
            AvlNode *k2 = k1->right;
            k1->right = k2->left;
            k2->left = k1;
            k1->height = max(height(k1->left), height(k1->right)) + 1;
            k2->height = max(height(k2->right), k1->height) + 1;
            k1 = k2;
        }

        //double ratation case 2
        void doubleWithLeftChild(AvlNode *&k3)
        {
            rotateWithRightChild(k3->left);
            rotateWithLeftChild(k3);
        }

        //case 3
        void doubleWithRightChild(AvlNode *&k1)
        {
            rotateWithLeftChild(k1->right);
            rotateWithRightChild(k1);
        }
        
};

#endif
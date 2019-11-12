#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    int height;
};

class AVL{
    public:
    node* root;
    AVL(){root==nullptr;}
    void makeEmpty(node* t);
    node* insert(int x){
        node* t = root;
        if(t== nullptr){
            node*p=new node;
            p->data = x;
            p->left = nullptr;
            p->right = nullptr;
            p->height=1;
            return p;
        }
        int height = 0;
        while(t != nullptr){
            height++;
            if (x < t->data){
                if (t->left == nullptr){
                    node*p=new node;
                    p->data = x;
                    p->left = nullptr;
                    p->right = nullptr;
                    p->height=height;
                    t->left = p;
                    return p;
                }
                t = t->left;
            }else if(x > t->data){
                if(x> t->data){
                    node*p=new node;
                    p->data = x;
                    p->left = nullptr;
                    p->right = nullptr;
                    p->height=height;
                    t->right = p;
                    return p;
                }
                t = t->right;
            }else{
                return t;
            }
        }
    }

    node* singleRightRotate(node* &t);
    node* singleLeftRotate(node* &t);
    node* doubleLeftRotate(node* &t);
    node* doubleRightRotate(node* &t);
    node* findMin(node* t){
        while(t->left != nullptr){
            findMin(t->left);
        }
        return t;
    };
    node* findMax(node* t){
        while(t->right != nullptr){
            findMin(t->right);
        }
        return t;
    };
    //comment comment
    node* remove(int x, node* t);
    int height(node* t){
        int l,r;
        if(t==NULL)
            return 0;
        l=height(t->left);
        r=height(t->right);
        return l>r?l+1:r+1;
    }
    int getBalance(node* t){
        if(t== nullptr)
            return 0;
        return height(t->left)-height(t->right);
    }
    void inorder(node* t){
        if(t==NULL)
            return;
        else {
            inorder(t->left);
            cout << t->data << endl;
            inorder(t->right);
        }
    }
    void display();
};

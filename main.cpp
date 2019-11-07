

struct node{
    int data;
    node* left;
    node* right;
    int height;
};

class AVL{
    public:
    void makeEmpty(node* t);
    node* insert(int x, node* t);
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
    node* remove(int x, node* t);
    int height(node* t);
    int  getBalance(node* t);
    void inorder(node* t);
    void display();
};

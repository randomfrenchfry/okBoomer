

struct node{
    int data;
    node* left;
    node* right;
    int height;
}

class AVL{
    public:
    void makeEmpty(node* t);
    node* insert(int x, node* t);
    node* singleRightRotate(node* &t);
    node* singleLeftRotate(node* &t);
    node* doubleLeftRotate(node* &t);
    node* doubleRightRotate(node* &t);
    node* findMin(node* t){
        
    };
    node* findMax(node* t);
    node* remove(int x, node* t);
    int height(node* t);
    int  getBalance(node* t);
    void inorder(node* t);
    void display();
}

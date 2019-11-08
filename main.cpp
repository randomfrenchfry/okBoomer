

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
    node* insert(int x, node* t){
        if(t== nullptr){
            node*p=new node;
            p->data = x;
            p->left = nullptr;
            p->right = nullptr;
            p->height=1;
            return p;
        }
        if(x < t->data){ //if the new data is less than previous node data
            t->left = insert(x,t->left);
        }
        else if(x > t->data){ //if the new data is more than previous node data
            t->right = insert(x,t->right);
        }
        else
            return t;
        //Need to finish this
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
        if(t== nullptr)
            return 0;
        return t->height;
    }
    int getBalance(node* t){
        if(t== nullptr)
            return 0;
        return height(t->left)-height(t->right);
    }
    void inorder(node* t);
    void display();
};

#include <iostream>
using namespace std;

struct node{
    int data = 0;
    node* parent = nullptr;
    node* left = nullptr;
    node* right = nullptr;
    int height = 0;
};

class AVL{
    public:
    node* root;
    AVL(){root=nullptr;}
    void makeEmpty(node* t){
        if(t->left == nullptr && t->right == nullptr){
            delete t;
        }else{
            if(t->left != nullptr){
                makeEmpty(t->left);
            }
            if(t->right != nullptr){
                makeEmpty(t->right);
            }
        }
        root = nullptr;
    };
    node* insert(int x){
        cout << "Starting insert" << endl;
        node* t = root;
        node* last = nullptr;
        node* retur = nullptr;
        if(t == nullptr){
            cout << "tree is empty, setting root.." << endl;
            node*p=new node;
            p->data = x;
            p->left = nullptr;
            p->right = nullptr;
            p->parent = nullptr;
            //p->height=1;
            root = p;
            return p;
        }
        //int height = 0;
        while(t != nullptr){
            //height++;
            if (x < t->data){
                if (t->left == nullptr){
                    node*p=new node;
                    p->data = x;
                    p->parent = t;
                    p->left = nullptr;
                    p->right = nullptr;
                    //p->height=1;
                    t->left = p;
                    last = p;
                    retur = p;
                    break;
                }else{
                    t = t->left;
                }
            }else if(x > t->data){
                if (t->right == nullptr){
                    node*p=new node;
                    p->data = x;
                    p->parent = t;
                    p->left = nullptr;
                    p->right = nullptr;
                    //p->height=1;
                    t->right = p;
                    last = p;
                    retur = p;
                    break;
                }else{
                    t = t->right;
                }
            }else{
                return t;
            }
        }
        //gotta determine the type of rotation
        //trace back up and if balence of node is more than 1 then we gotta rotate

        //at this point t is the parent node of the node we just inserted
        //last is the node we inserted;
        cout << "checking balence" << endl;
        while(t->parent != nullptr){
            if(abs(getBalance(t)) <= 1){//good enough balence go up a level
                cout << "balence at " << t->data << " is " << getBalance(t) << endl;
                last = t;
                t = t->parent;
            }else{// unbalenced, find out which rotate to perform
                cout << "unbalenced at: " << t->data << " is " << getBalance(t)<< endl;
                if(getBalance(t) < 0){//right heavy
                    if(getBalance(last) < 0){//right heavy
                        cout << "S Left Rotate" << endl;
                        singleLeftRotate(t);
                    }else if(getBalance(t) > 0){//left heavy
                        cout << "D Left rotate" << endl;
                        doubleLeftRotate(t);
                    }
                }else if(getBalance(t) > 0){//left heavy
                    if(getBalance(last) < 0){//right heavy
                        cout << "D right rotate" << endl;
                        doubleRightRotate(t);
                    }else if(getBalance(t) > 0){//left heavy
                        cout << "s right rotate" << endl;
                        singleRightRotate(t);
                    }
                }

            }
        }
        return retur;
    }

    node* singleRightRotate(node* pivot){
        //make parent point at t
        //make pivot point at right child of t
        //make right child of ts parent pivot
        //make pivot right child of t
        //make t parent of pivot
        //make parent ts parent
        cout << "starting right rotate" << endl;
        node* t = pivot->left;
        node* parent = pivot->parent;
        if(pivot->parent->left == pivot){
            pivot->parent->left = t;
        }else{
            pivot->parent->right = t;
        }
        cout<< "step1" <<endl;
        pivot->left = t->right;
        cout<< "step2" <<endl;
        if(t->right != nullptr){
            t->right->parent = pivot;
        }
        cout<< "step3" <<endl;
        t->right = pivot;
        cout<< "step4" <<endl;
        pivot->parent = t;
        cout<< "step5" <<endl;
        t->parent = parent;
        cout<< "step6" <<endl;
        //if pivot == root set root to t
        if(root == pivot){
            root = t;
        }
    };
    node* singleLeftRotate(node* pivot){
        //make parent point at t
        //make pivot point at left child of t
        //make left child of ts parent pivot
        //make pivot left child of t
        //make t parent of pivot
        //make parent ts parent
        node* t = pivot->right;
        node* parent = pivot->parent;
        if(pivot->parent->left == pivot){
            pivot->parent->left = t;
        }else{
            pivot->parent->right = t;
        }

        pivot->right = t->left;

        if(t->left != nullptr){
            t->left->parent = pivot;
        }

        t->left = pivot;

        pivot->parent = t;

        t->parent = parent;

        //if pivot == root set root to t
        if(root == pivot){
            root = t;
        }
    };
    node* doubleLeftRotate(node* pivot){
        singleRightRotate(pivot->right);
        singleLeftRotate(pivot);
    };
    node* doubleRightRotate(node* pivot){
        singleLeftRotate(pivot->left);
        singleRightRotate(pivot);
    };
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
    node* remove(int x){
        node* t = root;
        while(t != nullptr){
            if (t->data == x){
                break;
            }else if(x < t->data){
                t = t->left;
            }else{
                t = t->right;
            }
        }
        //if we didint find it
        if(t==nullptr){
            return nullptr;
        }
        //if t has no children
        if(t->left == nullptr && t->right == nullptr){
            if(t->parent->left == t){
                t->parent->left = nullptr;
                
            }else{
                t->parent->right = nullptr;
                
            }
            return t;
        }
        //if t has no left child node
        if(t->left == nullptr && t->right != nullptr){
            if(t->parent->left == t){
                t->parent->left = t->right;
                
            }else{
                t->parent->right = t->right;
                
            }
            return t;
        }

        //if t has left children
        node* del = t;
        t = t->left;
        while(t->right != nullptr){
            t = t->right;
        }
        del->data = t->data;
        if(t->parent->left == t){
            t->parent->left = t->right;
            
        }else{
            t->parent->right = t->right;
            
        }
        return t;
    };
    int height(node* t){
        int l,r = 0;
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
        if(t==nullptr)
            return;
        else {
            inorder(t->left);
            cout << t->data << "       height: " << height(t) << endl;
            inorder(t->right);
        }
    }
    void display(){
        inorder(root);
    };
};

int main(){
    AVL l;
    //cout << l.root->data << "--" << endl;
    //l.display();
    l.insert(1000000);
    //cout << l.root->data  << "--" << endl;
    //l.display();
    l.insert(15);
    //l.display();
    //cout << l.root->data  << "--" << endl;
    l.insert(5);

    l.insert(20);

    l.insert(4);

    l.insert(3);

    l.display();

    l.insert(6);

    l.display();
    //cout << l.root->data  << "--" << endl;
}

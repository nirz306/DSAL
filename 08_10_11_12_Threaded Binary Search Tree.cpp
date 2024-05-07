#include <iostream>
using namespace std;
class node
{
    int data;
    node *left;
    node *right;
    bool lthread; //lthread points to the inorder predecessor 
    bool rthread; //rthread points to the inorder successor 
    public:
    node()
    {
        data=0;
        left=NULL;
        right=NULL;
        lthread=1;
        rthread=1;
    }
    friend class tbt;
};

class tbt
{
    node *root;
    node *head;
    public:
    tbt()
    {
        root=NULL;
        head=new node;   //this is the header node
    }
    void insert(int x);
    void inorder(node *c);
    node *inordersucc(node *c);
    node* get_root();
    node* preorder(node *c);
    void remove(int x);
};

//tbt functions

void tbt::insert(int x)
{
    node *new1=new node;
    new1->data=x;
    node *c=root; //child
    node *p=root; //parent
    int flag=0;

    //inserting the first node 
    if(root==NULL)
    {
        root=new1;
        head->right=root;
        new1->left=head;
        new1->right=head;
    }
    else
    {
        while(flag!=1)
    {
        if(c->data==x)
        {
            return;
        }
        if(c->data<x)//go right
        {
            
            if(c->rthread==1)           //rthread == 1 mnjhe ki right pointer head la point kartoy , or ki rthread exists kartoy (the dotted )
            {
                new1->right=c->right;
                new1->left=c;
                c->right=new1;
                c->rthread=0;           
                flag=1;
            }
            p=c;
            c=c->right;
        }
        else if(c->data>x) //go left
        {
            
            if(c->lthread==1)
            {
                new1->left=c->left;
                new1->right=c;
                c->left=new1;
                c->lthread=0;
                flag=1;
            }
            p=c;
            c=c->left;
        }
    }
    }
    
    
}

void tbt::inorder(node *c)
{
    //to reach at the smallest 
    while(c->left != head){
        c = c->left;
    }
    //atta head var ahe
    while(c->right != head){
        cout<<c->data<<" ";
        c = inordersucc(c);
    }
    cout<<c->data<<" ";
    
}

node *tbt::inordersucc(node *c)
{
    if(c->rthread==1)                //jar leaf asel tar
    {
        return c->right;
    }
    else                            //jar leaf nasel tar ekda right ja ani salag left jaat raha 
    {
        c=c->right;
        while(c->lthread!=1)
        {
            c=c->left;
        }
        return c;

    }
}

node* tbt::preorder(node *c) //root->left->right
{
    while(c->left!=head)
    {
        cout<<c->data<<" ";
        c=c->left;
    }
    cout<<c->data<<" ";
    while(c->right!=head)
    {
        if(c->rthread==1)
        {
            c=c->right;
        }
        else
        {
            c=c->right;
            while(c->lthread!=1)
            {
                cout<<c->data<<" ";
                c=c->left;
            }
            cout<<c->data<<" ";
        }
    }
}

void tbt::remove(int x)
{
    node *c=root;
    node *p=root;
    int flag=0;
    while(flag!=1)            //assign parent and child to the desired node
    {
        if(c->data==x)
        {
            flag=1;
        }
        if(c->data<x)
        {
            p=c;
            c=c->right;
        }
        else if(c->data>x)
        {
            p=c;
            c=c->left;
        }
    }
    if(c->lthread==1 && c->rthread==1)  //node to be deleted is a left node
    {
        if(p->left==c)                    //node to deleted is left child of its parent
        {
            p->left=c->left;
            p->lthread=1;
            delete(c);
        }
        else if(p->right==c)            //node to deleted is right child of its parent
        {
            p->right=c->right;
            p->rthread=1;
            delete(c);
        }
    }
    else if(c->lthread==1 || c->rthread==1)       
    {
        if(p->right==c)                 //node to deleted is right child of its parent
        {
            if(c->lthread==1)            //right subtree exists
            {
                c->right->left=p;
                p->right=c->right;
                delete(c); 
            }
            else if(c->rthread==1)            //left subtree exists
            {
                c->left->right=c->right;
                p->right=c->left;
                delete(c);
            }
        }
        else if(p->left==c)            //node to deleted is left child of its parent
        {
            if(c->lthread==1)            //right subtree exists
            {
                c->right->left=c->left;
                p->left=c->right;
                delete(c); 
            }
            else if(c->rthread==1)         //left subtree exists
            {
                c->left->right=p;
                p->left=c->left;
                delete(c);
            }
        }
    }
    else if(c->lthread!=1 && c->rthread!=1)
        {
            node *p=c;
            node* q=inordersucc(c);
            c=c->right;
            while(c->left!=q && c!=q)
            {
                c=c->left;
            }
            int temp=p->data;
            p->data=q->data;
            q->data=temp;
            if(c->left==q)
            {
                if(q->rthread!=1)
                {
                    // c->left=q->right;
                    node *r=q;
                    q=q->right;
                    while(q->lthread!=1)
                    {
                        q=q->left;
                    }
                    q->left=r->left;
                    c->left=r->right;
                    delete(r);
                }
                else if(q->rthread==1)
                {
                    c->left=q->left;
                    c->lthread=1;
                    delete(q);
                }
                
            }
            else if(c==q)
            {
                if(q->rthread==1)
                {
                    p->right=q->right;
                    p->rthread=1;
                    delete(q);
                }
                else if(q->rthread!=1)
                {
                    p->right=q->right;
                    q->right->left=q->left;
                    delete(q);
                }
                
            }
        }
}
node* tbt::get_root()
{
    return root;
}
int main()
{
    tbt t;
    int c=1;
    while(c>0)
    {
        cout<<"MENU"<<endl;
        cout<<"1.Insert"<<endl;
        cout<<"2.Inorder"<<endl;
        cout<<"3.Preorder"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"Enter Choice"<<endl;
        cin>>c;
        if(c==1)
        {
            int key;
            cout<<"Enter data:";
            cin>>key;
            t.insert(key);
        }
        else if(c==2)
        {
            t.inorder(t.get_root());
            cout<<endl;
        }
        else if(c==3)
        {
            t.preorder(t.get_root());
            cout<<endl;
        }
        else if(c==4)
        {
            int x;
            cout<<"Enter key to delete"<<endl;
            cin>>x;
            t.remove(x);
        }
    }
    return 0;
}

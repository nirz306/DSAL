#include<bits/stdc++.h>
using namespace std;

class node{
    private:
        int data;
        node* left;
        node* right;
    public:
        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

   friend class Tree;
};

class Tree {
public:
    void buildTree(node* &root);
    void displayTree(node* root);
    void mirrorTree(node* root);
    int heightTree(node* root);
    void inorder_rec(node* root);      //left,node,right
    void postorder_rec(node* root);    // left,right,node
    void preorder_rec(node* root);     //node, left,right
    void inorder_iter(node* root);
    void preorder_iter(node* root);
    void postorder_iter(node* root);
    int leaves(node* root);
    int internal_nodes(node* root);
    };

void Tree::buildTree(node* &root){
    queue <node*> q;
    cout<<"Enter the data for root: "; 
    int data; 
    cin>>data;  
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the left node of "<<temp->data<<": "; int leftData; cin>>leftData;
        cout<<"Enter the right node of "<<temp->data<<": "; int rightData; cin>>rightData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void Tree::displayTree(node* root){
     queue <node*> q;
     q.push(root);
     q.push(NULL);

     while(!q.empty()){
        node* temp = q.front();
        q.pop();

        //if NULL is present means add a seperator 
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){     //queue is not empty
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
             
        }

     }
}

void Tree::mirrorTree(node* root){
    //base case 
    if(root== NULL){
        return;
    }
    swap(root->left,root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}

int Tree::heightTree(node *root){
    //base case 
    if(root == NULL){
        return 0;
    }
    int ldepth = heightTree(root->left);
    int rdepth = heightTree(root->right);
    int ans = max(ldepth,rdepth)+1;
    return ans;
}

void Tree::inorder_rec(node *root){
    //base case 
    if(root == NULL){
        return;
    }
    inorder_rec(root->left);
    cout<<root->data<<" ";
    inorder_rec(root->right);
}

void Tree::preorder_rec(node *root){
    //base case 
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder_rec(root->left);
    preorder_rec(root->right);
}

void Tree::postorder_rec(node *root){
    //base case 
    if(root == NULL){
        return;
    }
    postorder_rec(root->left);
    postorder_rec(root->right);
    cout<<root->data<<" ";
}

void Tree::inorder_iter(node* root){
    stack<node*> s;
    node* curr = root;
 
    while (curr != NULL || s.empty() == false) {
         
        // Reach the left most Node of the
        // curr Node
        while (curr != NULL) {
             
            // Place pointer to a tree node on
            // the stack before traversing
            // the node's left subtree
            s.push(curr);
            curr = curr->left;
        }
 
        // Current must be NULL at this point
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
 
        // we have visited the node and its
        // left subtree.  Now, it's right
        // subtree's turn
        curr = curr->right;
 
    }
}

void Tree::postorder_iter(node* root){
    if (root == NULL) 
        return; 
  
    // Create two stacks 
    stack<node *> s1, s2; 
  
    // push root to first stack 
    s1.push(root); 
    node* node; 
  
    // Run while first stack is not empty 
    while (!s1.empty()) { 
        // Pop an item from s1 and push it to s2 
        node = s1.top(); 
        s1.pop(); 
        s2.push(node); 
  
        // Push left and right children 
        // of removed item to s1 
        if (node->left) 
            s1.push(node->left); 
        if (node->right) 
            s1.push(node->right); 
    } 
  
    // Print all elements of second stack 
    while (!s2.empty()) { 
        node = s2.top(); 
        s2.pop(); 
        cout << node->data << " "; 
    } 
}

void Tree::preorder_iter(node* root){
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty stack and push root to it
    stack<node*> nodeStack;
    nodeStack.push(root);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) {
        // Pop the top item from stack and print it
        struct node* node = nodeStack.top();
        printf("%d ", node->data);
        nodeStack.pop();
 
        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}

int Tree:: leaves(node* root)  {
      if(root == NULL)
      {
            return 0;
      }
      
      if(root->left == NULL && root->right == NULL)
      {
            return 1;
      }
      int left=0,right=0;
      if(root->left)
      left=leaves(root->left);
      if(root->right)
      right=leaves(root->right);
 
      return left+right;
}

static int int_nodes = 0;
int Tree::internal_nodes(node* root){
 
    if (root == NULL) {
        return 0;
    }


    if (root->left != NULL || root->right != NULL) {
        int_nodes++;  
    }

    
    internal_nodes(root->left);
    internal_nodes(root->right);

    return int_nodes;
}


 int main(){
    Tree t1;
    node* root = NULL;
    t1.buildTree(root);
    t1.displayTree(root);
   
    int height = t1.heightTree(root);
    cout<<"The height of the tree is: "<<height<<endl;

    cout<<"The inorder traversal of the tree using recurssion is: ";
    t1.inorder_rec(root);   cout<<endl;
    cout<<"The inorder traversal of the tree using iterative is: ";
    t1.inorder_iter(root);  cout<<endl;
    cout<<"The preorder traversal of the tree using recurssion is: ";
    t1.preorder_rec(root);  cout<<endl;
    cout<<"The preorder traversal of the tree using iterative is: ";
    t1.preorder_iter(root);  cout<<endl;
    cout<<"The postorder traversal of the tree using recurssion is: ";
    t1.postorder_rec(root);  cout<<endl;
    cout<<"The postorder traversal of the tree using iterative is: ";
    t1.postorder_iter(root);  cout<<endl;

    int leaves = t1.leaves(root);
    cout<<"No of leaves in the tree is: "<<leaves<<endl;
    int int_nodes = t1.internal_nodes(root);
    cout<<"No of internal nodes in the tree is: "<<int_nodes<<endl;

     t1.mirrorTree(root);
     cout<<"Displaying the mirror tree: "<<endl;
    t1.displayTree(root);
}

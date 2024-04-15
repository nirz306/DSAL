/*Beginning with an empty binary tree, Construct binary tree by inserting 
the values in the order given. After constructing a binary tree perform 
following operations on it-
1) Perform in order / pre order and post order traversal
2) Change a tree so that the roles of the left and right pointers are 
swapped at every node 
3) Find the height of tree
4)Copy this tree to another [operator=] 
5)Count number of leaves, number of internal nodes. 
6)Erase all nodes in a binary tree. 
7)implement both recursive and non-recursive methods)*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

        node()  // partameterised constructor
        {
            // node *newNode;
            this->data = 0;
            this->left = NULL;
            this->right = NULL;
        }

        node(int value)  // partameterised constructor
        {
            // node *newNode;
            this->data = value;
            this->left = NULL;
            this->right = NULL;
        }
};

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
   
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }


void levelOrderTraversal(node *root) //prints the tree
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();
        //
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                //queue still has some nodes then
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)         //jar available asel tar
            {
                q.push(temp->left);
                 
            }
            if(temp->right)         //jar available asel tar
            {
                 q.push(temp->right);
            }
        }
    }
}

void mirror(node *&root)
{
    //base case
    if(root==NULL)
    {
        return;
    }

    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
}

int depth(node *root)
{
    //base case
    if(root == NULL)
    {
        return 0;
    }
    int left = depth(root->left);
    int right = depth(root->right);
    int ans = max(left,right)+1;
    return ans;
}

class Stack
{
    public:
        node* stack[10];
        int j=-1;
        void push(node* value)
        {
             j++;
            stack[j] = value;
        }
        node* poped;
        node* pop()
        {
            poped = stack[j];
            j--;
            return poped;
        }
        node* top()
        {
            return stack[j];
        }
        bool empty()
        {
            if(j == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

void inorder(node *root)
{
    //base case
    if(root == NULL)
    {
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node *root)
{
    //base case
    if(root == NULL)
    {
        return ;
    }
   
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    //base case
    if(root == NULL)
    {
        return ;
    }
   
   
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder2(node *root) //using iteration
{
    //if empty tree
    if(root == NULL)
    {
        return ;
    }
    else
    {
        Stack s1;
       
        node* curr = root;
       
        while(curr!=NULL || !s1.empty())
        {
            while(curr!=NULL)
            {
                s1.push(curr);
                curr = curr->left;
            }
           
            curr = s1.top();
            s1.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
        }
       
    }
}

void preorder2(node* root)
{
    if (root == NULL)
        return;
 
    stack<node*> st;
 
    // start from root node (set current node to root node)
    node* curr = root;
 
    // run till stack is not empty or current is
    // not NULL
    while (!st.empty() || curr != NULL) 
	{
        // Print left children while exist
        // and keep pushing right into the
        // stack.
        while (curr != NULL) 
		{
            cout << curr->data << " ";
 
            if (curr->right)
                st.push(curr->right);
 
            curr = curr->left;
        }
 
        // We reach when curr is NULL, so We
        // take out a right child from stack
        if (st.empty() == false) {
            curr = st.top();
            st.pop();
        }
    }
}

void postorder2(node* root)
{
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

static int int_nodes = 0;


int leaves(node* root)  //error!!
{
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

//need to solve this error
int internal_nodes(node* root) { 
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


node* clone(node *root)
{
    //base case
    if(root == NULL)
    {
        return NULL;
    }
   
    node* root_copy = new node(root->data);
 
    // clone the left and right subtree
    root_copy->left = clone(root->left);
    root_copy->right = clone(root->right);
 
    // return cloned root node
    return root_copy;
}

void delete_tree(node *root)
{
    if(root == NULL)
    {
        return;
    }
 
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

int main()
{
    node* root = NULL;
 
     //creating a tree
    buildFromLevelOrder(root);

    cout<<"\n---------------Level order traversal of the tree is--------------"<<endl;
    levelOrderTraversal(root);
   
     cout<<"\n---------------The height of the tree is-------------------------"<<endl;
     cout<<depth(root);
   
    cout<<"\n---------------The number of leaves in BST are--------------"<<endl;
    cout<<leaves(root);
   
    // cout<<"\n---------------The number of internal nodes in BST are--------------"<<endl;
    // cout<<internal_nodes(root);

    cout<<"\n----------------The inorder traversal of tree is -----------------"<<endl;
    inorder2(root);
   
     cout<<"\n----------------The preorder traversal of tree is -----------------"<<endl;
     preorder2(root);

    cout<<"\n----------------The postorder traversal of tree is -----------------"<<endl;
    postorder2(root);

    node* cloned_tree = clone(root);
    cout<<"\n---------------Level order traversal of the cloned tree is--------------"<<endl;
    levelOrderTraversal(cloned_tree);

    mirror(root);
    cout<<"\n---------------Level order traversal of the tree after mirroring is--------------"<<endl;
    levelOrderTraversal(root);

    delete_tree(root);
    cout<<root;
 
    //10 5 7 3 4 5 -1 -1 -1 - 1 -1 -1 -1

}

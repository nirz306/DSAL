/*Beginning with an empty binary search tree. Construct the binary 
search tree by inserting the values in given order. After constructing 
binary search tree perform following operations 
1) Insert a new node 
2) Find numbers of node in longest path                                                      
3) Minimum and maximum data value found in tree                                               
4) Change a tree so that the roles of the left and right pointers are swapped at every node
5)Search an element*/                                                                         
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;
        node(int value)  //constructor
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

void levelOrderTraversal(node *root)
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
            stack[j] = poped;
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
            else{
                return false;
            }
        }
};

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
        // stack<node*> s2;
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
            cout<<curr->data;
            curr=curr->right;
        }
       
    }
}

node* search(node* root, int key){
    if (root == NULL || root->data == key)
        return root;
 
    // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

void longestPathNodes(node* root){
    if(!root)
        cout<<"The tree is empty!"<<endl;
    else{
        
        int lDepth = depth(root);
        int rDepth = depth(root);

        if(lDepth>rDepth){
            cout<<"\n The number of nodes on Longest Path= "<<lDepth+1;
        }
        else{
            cout<<"\n The number of nodes on Longest Path= "<<rDepth+1;
        }
    }
}

void minValue(node* temp, int *min){
    if(temp != NULL){
        minValue(temp->left,min);
        if(temp->data < *min)
            *min = temp->data;
        minValue(temp->right,min);
    }
}
void findMinValue(node* root){
    int min = root->data;
    minValue(root,&min);
    cout<<"\n The minimum value node within a tree is "<<min;
}

void maxValue(node* temp, int *max){
    if(temp != NULL){
        maxValue(temp->left,max);
        if(temp->data > *max)
            *max = temp->data;
        maxValue(temp->right,max);
    }
}
void findMaxValue(node* root){
    int max = root->data;
    maxValue(root,&max);
    cout<<"\n The maximum value node within a tree is "<<max;
}


int main()
{
    node* root =NULL;
     //creating a tree
    buildFromLevelOrder(root);

    cout<<"\n---------------Level order traversal of the tree is--------------"<<endl;
    levelOrderTraversal(root);
   
    cout<<"\n---------------The height of the tree is-------------------------"<<endl;
    int height = depth(root);
    cout<<"Height: "<<height;

    // cout<<"\n----------------The inorder traversal of tree is -----------------"<<endl;
    // inorder2(root);
   
    mirror(root);
    cout<<"\n---------------Level order traversal of the tree after mirroring is--------------"<<endl;
    levelOrderTraversal(root);

    cout<<"\n------------------The nodes in the longest path of the tree is-------------------"<<endl;
    longestPathNodes(root);

    findMinValue(root);
    findMaxValue(root);

    cout<<"\nEnter the data you want to search in the tree: "; int data; cin>>data; 
    node* temp = search(root,data);
    if(!temp)
        cout<<"Data found "<<endl;
    else
        cout<<"Data not found "<<endl;


}

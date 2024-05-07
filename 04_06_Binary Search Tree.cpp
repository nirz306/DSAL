// Insert,delete,search,ascending,descending,min and max value  
#include <bits/stdc++.h>
using namespace std;

class Node{
    private:
        int data;
        Node* left;
        Node* right;
      

    public:
        Node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
    friend class BST;
};

class BST{

    private:
        int maxi = INT16_MIN;
        int mini = INT16_MAX;
        Node* root ;

    public:
         BST(){
            root= NULL;
        }
        
        private:

        Node* Insert(Node*root,int value)
        {
            if (!root) {
                return new Node(value);
            }
        
            if (value > root->data) 
                root->right = Insert(root->right, value);
           
            else if (value < root->data) 
                root->left = Insert(root->left, value);

            return root;
        }

        void displayTree(Node* &root){
             if (root == NULL) {
                cout << "Tree is empty!" << endl;
                return;
            }
            queue <Node*> q;
            q.push(root);
            q.push(NULL);

            while(!q.empty()){
                Node* temp = q.front();
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
                    maxi = max(maxi,temp->data);
                    mini = min(mini,temp->data);
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                    
                }

            }
        }

        void search(Node* &root, int val){
            if(root->data == val)
                {cout<<"Found"<<endl;
                return;}

            if(val<root->data)
                search(root->left,val);
            
            else if(val>root->data)
                search(root->right,val);
            
            else{
                cout<<"Not Found"<<endl;
            }
        }
    

        void displayDescending(Node* root){
            stack <Node*> s;

            Node* current = root;
            while(current!=NULL || !s.empty()){
                while(current !=NULL ){
                        s.push(current);
                        current = current->right;
                }
                current = s.top();
                s.pop();
                cout<<current->data<<" ";
                current = current->left;
            }
          cout<<endl;
        }

        void displayAscending(Node* root){
            stack <Node*> s;
            Node* current = root;
            while(current!=NULL || !s.empty()){
                while(current !=NULL ){
                        s.push(current);
                        current = current->left;
                }
                current = s.top();
                s.pop();
                cout<<current->data<<" ";
                current = current->right;
            }
           cout<<endl;
        }

        Node* deleteNode(Node* root, int k)
        {
            // Base case
            if (root == NULL)
                return root;

            // If the key to be deleted is smaller than the root's key,
            // then it lies in the left subtree
            if (k < root->data) {
                root->left = deleteNode(root->left, k);
                return root;
            }
            // If the key to be deleted is greater than the root's key,
            // then it lies in the right subtree
            else if (k > root->data) {
                root->right = deleteNode(root->right, k);
                return root;
            }

            // If key is same as root's key, then this is the node to be deleted
            // Node with only one child or no child
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest
            // in the right subtree)
            Node* succParent = root;
            Node* succ = root->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }

            // Copy the inorder successor's content to this node
            root->data= succ->data;

            // Delete the inorder successor
            if (succParent->left == succ)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;
            
            delete succ;
            return root;
        }
    
    public: 

       

        void Insertt(int data){
            root = Insert(root,data);           //updating the root 
        }

        void display(){
            displayTree(root);
        }
        
        void search(int val){
            search(root,val);
        }

        void descending(){
            displayDescending(root);
        }

        void ascending(){
            displayAscending(root);
        }

        void maximum_val(){
            cout<<maxi;
        }

        void minimum_val(){
            cout<<mini;
        }

        void delete_tree(int val){
            deleteNode(root,val);
        }

       
};


int main(){
    BST t;
    t.Insertt(50);
    t.Insertt(30);
    t.Insertt(70);
    t.Insertt(20);
    t.Insertt(40);
    t.Insertt(60);
    t.Insertt(80);
   
    t.display();
   
    t.ascending();
    t.descending();
    t.search(40);
    t.delete_tree(70);
    t.display();
    t.maximum_val();
    t.minimum_val();
}
 

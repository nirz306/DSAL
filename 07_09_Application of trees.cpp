//  A dictionary stores keywords and its meanings. Provide facility for adding new 
// keywords, updating values of any entry, delete any entry. Provide facility to display 
// whole data sorted in ascending/ Descending order. Also find how many maximum 
// comparisons may require for finding any keyword. Use Binary Search Tree for 
// implementation
#include <iostream>
using namespace std;
#include <string.h>

class Node
{
    string word;
    string meaning;
    Node* left;
    Node* right;

    public:
        Node(){
            word = " ";
            meaning = " ";
            left = NULL;
            right = NULL;
        }

        Node(string w, string m){
            word = w;
            meaning = m;
            left = NULL;
            right = NULL;
        }
    friend class BST;
};

class BST
{
    public:
        Node* root;
    BST(){
        root = NULL;

    }

    //---binary search tree operations

    void insert(string word , string meaning);
    void display_ascending(Node* root1);
    void display_descending(Node* root1);
    Node* search(string word);
    void update(string old_word, string new_meaning);
    Node* delete_word(Node* root ,string word);
    void insert();
    void search();
    void delete_word();
    void update();
    void display_ascending(){display_ascending(root);};
    void display_descending(){display_descending(root);};

    string getMeaning(Node * temp){
        return temp->meaning;
    }
};

void BST::delete_word(){
     cout<<"Enter the word to be deleted: "; string word; cin>>word;
        delete_word(root,word);
}

void BST::search(){
    cout<<"Enter the word to be searched: "; string word; cin>>word;
    search(word);
}

void BST::update(){
    cout<<"Enter the word to be updated: "; string word; cin>>word;
    cout<<"Enter its new meaning: "; string mean; cin>>mean;
    update(word,mean);
}

void BST::insert(){
    cout<<"Enter the word: "; string word; cin>>word;
    cout<<"Enter the meaning: "; string meaning; cin>>meaning;

    insert(word,meaning);
}

Node* BST :: search(string word){
    Node* curr = root;
    while(curr->word != word){
        if(curr != NULL){
            if(word < curr->word)// go to left tree
                curr = curr->left;
            else//go to right tree
                curr = curr->right;
        }
        if(curr == NULL){
            // data not found
            cout<<"\n Data not found \n";
            return NULL;
        }
    }
    cout<<"\n Data found \n";
    return curr;
}

void BST :: insert(string word , string meaning){
    Node* newnode = new Node(word,meaning);
    if(root == NULL){
        root = newnode;
    }
    else{
        Node* curr= root;
        Node* parent = NULL;   // parent will point to parent node
        while(1){
            parent = curr;
            if(word < parent->word){
                // go to left of tree
                curr = curr->left;
                // insert ot left child 
                 if(curr == NULL){
                    parent->left = newnode;
                    return;
                 }
            }
            else{
                // go to the right of tree
                curr = curr->right;
                if(curr == NULL){
                    parent->right = newnode;
                    return;
                }
            }
        }
    }
}

void BST :: display_ascending(Node* root1){
    // cout<<"\n\n----Displaying in ascending order----\n\n";
    if(root1 == NULL){
        return;
    }
    else{
      display_ascending(root1->left);
      cout<<"\n Word : "<<root1->word<<", Meaning : "<<root1->meaning<<endl; 
      display_ascending(root1->right);
    }
}

void BST :: display_descending(Node* root1)
{
    // cout<<"\n\n----Displaying in descending order----\n\n";
    if(root1 == NULL){
        return;
    }
    else{
      display_descending(root1->right);
      cout<<"\n Word : "<<root1->word<<", Meaning : "<<root1->meaning<<endl; 
      display_descending(root1->left);
    }
}

void BST ::update(string old_word, string new_meaning){
    Node* curr = root;
    while(curr->word != old_word){
        if(curr != NULL){
            if(old_word < curr->word){
                // move to left
                curr = curr->left;
            }
            else{
                // move to right
                curr = curr->right;
            }
        }
        if(curr == NULL){
            cout<<"\n Old word not found \n\n";
            return;
        }
    }
    curr->meaning = new_meaning;
    return;
}

Node* BST :: delete_word(Node* root,string word){
    if(root == NULL){
        cout<<"\nNode not found \n";
        return NULL;
    }
    else{
        if(word < root->word){
            root->left = delete_word(root->left,word);
        }
        else if(word > root->word){
            root->right = delete_word(root->right,word);
        }
        else{
            if(root->left == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else{
                Node* temp = root->right;
                while(temp->left != NULL){
                    temp= temp->left;
                }

                root->word= temp->word;
                root->meaning = temp->meaning;
                root->right = delete_word(root->right,temp->word);
            }
        }
        return root;
    }


}

int main()
{
    BST t1;
    string word,meaning;
    t1.insert();
    t1.insert();
    t1.insert();
    t1.insert();
    t1.search();
    t1.delete_word();
    t1.update();
    t1.display_ascending();
    t1.display_descending();
    return 0;
}

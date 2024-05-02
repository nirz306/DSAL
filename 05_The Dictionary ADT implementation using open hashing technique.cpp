 /*s:Implement all the functions of a dictionary (ADT) using open
hashing technique: separate chaining using linked list Data: Set of
(key, value) pairs, Keys are mapped to values, Keys must be
comparable, and Keys must be unique. Standard Operations: Insert
(key, value), Find(key), Delete(key)*/

#include <iostream>
using namespace std;
class node {
    private:
     string value;
     string key;
     node* next;
    public:
     node(string key, string value) {
         this -> key = key;
         this -> value = value;
         this -> next = NULL;
     }
    friend class DLL;
};

class DLL {
    public:
    node* arr[10];

    DLL() {
        for(int i = 0; i < 10; i++) {
            arr[i] = NULL;
        }
    }
    void insert();
    void display();
    void search();
    void deletion();
};

void DLL :: search() {
    string key;
    cout << "Enter the key to search: ";
    cin >> key;
    int index = key[0] % 10;
    node* temp = arr[index];
    while(temp) {
        if(temp -> key == key) {
            cout << "key found!" << endl;
            cout << "Meaning of word is: " << temp -> value << endl;;
            return;
        }
        temp = temp -> next;
    }
    cout << "key not found!" << endl;;

}
void DLL :: insert() {
    cout << "Enter the key character: ";
    string key;
    cin >> key;
    cout << "Enter the value: ";
    string value;
    cin >> value;
    int index = key[0] % 10;
    node* temp = arr[index];
    if(temp == NULL) {                     //jar first element null asel titech insert kar
        arr[index] = new node(key, value);
        return;
    }
    while(temp -> next != NULL) {     //else go ahead until you find non null element
        temp = temp -> next;
    }

    temp -> next = new node(key, value);
}

void DLL :: display() {
    cout << "------------------------------------------------" << endl;
    for(int i = 0; i < 10; i++) {
        node* temp = arr[i];
        if(temp == NULL) {
            cout << " -> NULL:NULL" << endl;
            continue;
        }
        while(temp) {
            cout <<  " -> " << temp -> key << ":" << temp -> value;
            temp = temp -> next;
        }
        cout << endl;
    }
    cout << "------------------------------------------------" << endl;

}

void DLL :: deletion()
{
    cout << "Enter the key character: ";
    string key;
    cin>>key;
    int index = key[0]%10;
    node *temp = arr[index]; 
    if(temp->key==key)
    {
        arr[index]=temp->next;
        delete temp;
        return;
    }
    else
    {
        node *parent=temp;
        while(temp -> key != key) 
        {
            parent = temp; 
            temp = temp -> next;
        }
        parent->next = temp->next;
        delete temp;
        return;
    }
}

int main() {
    DLL d;
    while(1) {
        cout << "1.insert" << endl;
        cout << "2.search" << endl;
        cout << "3.display" << endl;
        cout << "4.delete" << endl;
        int choice;
        cout << "Enter the choice: ";
        cin >> choice;
        if(choice == 1) {
            d.insert();
        }
        else if(choice == 2) {
            d.search();
        }
        else if(choice == 3){
            d.display();
        }
        else if(choice==4){
            d.deletion();
        }
        else {
            break;
        }
    }
    return 0;


}


//output format
// -> NULL:NULL
// -> NULL:NULL
// -> NULL:NULL
// -> NULL:NULL
// -> NULL:NULL
// -> NULL:NULL
// -> NULL:NULL
// -> apple:fruit -> aquaman:waterman
// -> ball:cricket -> bat:virat
// -> NULL:NULL
  

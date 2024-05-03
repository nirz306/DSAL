/*Consider telephone book database of N clients. Make use of a hash
table implementation to quickly look up client’s telephone number.
Make use of two collision handling techniques and compare them using
number of comparisons required to find a set of telephone numbers
(Note: Use linear probing with replacement and without replacement)*/

#include <iostream>
using namespace std;

class record {
    public:
        int tele;
        string name;

    record() {
        tele = 0000;
        name = "-";
    }
};

class hashtable {
    public:
    record arr[10];
    void initialize();
    void insertwithoutreplacement();
    void insertwithreplacement();
    void search();
};

void hashtable :: initialize() {
    for(int i = 0; i < 10; i++) {
        record r;
        arr[i] = r;
    }
}
void hashtable :: insertwithoutreplacement() {
    int t;
    cout << "Enter the telephone number: ";
    cin >> t;
    int index = (t%10);
    if(arr[index].name == "-") {
        cout << "Enter the name: ";
        cin >> arr[index].name;
        arr[index].tele = t;
    }
    else {
        int i = (index + 1)%10;
        while(i != index) {
            if(arr[i].name == "-") {
                cout << "Enter the name: ";
                cin >> arr[i].name;
                arr[i].tele = t;
                break;
            }
            i = (i+1)%10;
        }
        if(i == index) {
            cout << "Hashtable is full!" << endl;
        }
    }
    
}

void hashtable :: search() {
    int num;
    cout << "Enter the telephone number: ";
    cin >> num;
    int index = num%10;
    if(arr[index].tele == num) {
        cout << "Key found at location " << index << endl;
        cout << "The name of person is: " << arr[index].name << endl;
    }
    else {
        int i;
        for(i = index + 1; i != index; i = (i+1)%10) {
            if(arr[i].tele == num) {
                cout << "Key found at location " << i << endl;
                cout << "The name of person is: " << arr[i].name << endl;
                break;
            }
        }
        if(i == index) {
            cout << "Key not found!" << endl;
        }
    }
}

void hashtable :: insertwithreplacement() {
    int t;
    cout << "Enter the telephone number: ";
    cin >> t;
    int index = (t%10);
    if(arr[index].name == "-") {
        cout << "Enter the name: ";
        cin >> arr[index].name;
        arr[index].tele = t;
    }
    else {
        int i = index;
        int count = 0;
        while(count <= 10) {
            if(arr[i].name == "-") {
                cout << "Enter the name: ";
                cin >> arr[i].name;
                arr[i].tele = t;
                return;
            }
            else if((arr[i].tele)%10 != i && count == 0){
                int temptele = arr[i].tele; //juna no store kartoy
                string tempname = arr[i].name; //juna name store kartoy 
                cout << "Enter the name of person: ";
                cin >> arr[i].name;
                arr[i].tele = t;
                int j;
                for(j = (i+1)%10; j != i; j = (j+1)%10) {  //old values takayla jaga shodh 
                    if(arr[j].name == "-" ) {
                        arr[j].name = tempname;
                        arr[j].tele = temptele;
                        return;
                    }
                }
                cout << "hashmap is full!" << endl;
                return;
            }
            count++;
            i = (i+1)%10;
        }
        if(i == index) {
            cout << "Hashtable is full!" << endl;
        }    
    }

}

int main() {
    hashtable h;
    h.initialize();
    while(1) {
        cout << "1.insert without replacement" << endl;
        cout << "2.search" << endl;
        cout << "3.insert with replacement" << endl;
        cout << "Enter the choice: ";
        int c;
        cin >> c;
        if(c == 1) {
            h.insertwithoutreplacement();
        }
        else if(c == 2) {
            h.search();
        }
        else if(c == 3) {
            h.insertwithreplacement();
        }
        else {
            break;
        }
        cout << "----------------------------------------" << endl;
        for(int i = 0; i < 10; i++) {
            cout << h.arr[i].name << "  " << h.arr[i].tele << endl;
        }
        cout << "----------------------------------------" << endl;
    }
}

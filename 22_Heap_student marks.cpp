/*Read the marks obtained by students of second year in an online examination of particular 
subject. Find out minimum marks obtained in that subject. Use heap data structure. 
Analyze the algorithm. */
#include <iostream>
using namespace std;

class Student{
    private: 
        int marks;
        string name;
    public:
        friend class Heap;
};

class Heap{
    private:
         Student a[30];
         int n; //no of elements in the heap
    public:

        void create_heap(){
            cout<<"enter no of elements of array\n";
            cin>>n;
            for (int i = 1; i <= n; i++) {
                cout<<"Enter name: ";   
                cin>>a[i].name;
                cout<<"enter marks: ";
                cin>>a[i].marks;
            }
          build_minheap(a, n);  
        } 
        
        void display_heap(){
            cout<<"-----------------------------------------"<<endl;
            for (int i = 1; i <= n; i++) {
                cout<<a[i].name<<"-"<<a[i].marks<<endl;
            } 
             cout<<"-----------------------------------------"<<endl;
        }

    private:
        void min_heap(Student *a, int m, int n){
            int j, t;
            t= a[m].marks;
            j = 2 * m;
            while (j <= n) {
                if (j < n && a[j+1].marks < a[j].marks)
                    j = j + 1;
                if (t < a[j].marks)
                    break;
                else if (t >= a[j].marks) {
                    a[j/2] = a[j];
                    j = 2 * j;
                }
            }
            a[j/2].marks = t;
            return;
        }

        void build_minheap(Student *a, int n) {
            int k;
            for(k = n/2; k >= 1; k--) {
                min_heap(a,k,n);
            }
        }


};

 
int main() {
    Heap h1;
    h1.create_heap();
    h1.display_heap();
}

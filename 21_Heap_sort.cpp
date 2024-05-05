#include<iostream>
using namespace std;

class Heap{
    private:
         int arr[100];
         int size;
    public:
        Heap(){
            arr[0] = -1;
            size = 0;
        }
         void display(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
        }
        void insert(){
            cout<<"Enter number: "; int no; cin>>no; insert(no);
        }

       void heapsort() {
        int heapSize = size;
            while (heapSize > 1) {
                swap(arr[heapSize], arr[1]);
                heapSize--;

                heapify(arr, heapSize, 1);
        }
}

        

    private:
        void insert(int val){
            size = size+1;
            int index = size;
            arr[index] = val;

            while(index>1){
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else    
                    return;
            }
        }

        
        void heapify(int arr[], int n,int i){
            int largest = i;
            int left = 2*i;
            int right = ( 2*i)+1;

            if(left<=n && arr[largest]<arr[left]){
                largest = left;
            }
            if(right<=n && arr[largest]<arr[right]){
                largest = right;
            }
            if(largest!=i){
                swap(arr[largest],arr[i]);
                heapify(arr,n,largest);
            }
        }
};

int main(){
    Heap h1;
    h1.insert();
    h1.insert();
    h1.insert();
    h1.display();
    h1.heapsort();
    cout<<"\nThe sorted order is"<<endl;
    h1.display();
}

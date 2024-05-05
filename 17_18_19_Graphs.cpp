#include <iostream>
#include<queue>
using namespace std;

class Node
{
	int data;
	Node* next;
	Node* down;
	
	public:
		Node(int val)
		{
			this->data = val;
			this->next = NULL;
			this->down = NULL;
		}	 
    friend class Graph;
};

class Graph{
    int vertices;
    int edge;
    Node* root = NULL;
    Node* temp1 = root;			//to insert new vertices

    public:
        
        void insert(){
            cout<<"Enter no of vertices: "; cin>>vertices; 
            for(int i=0;i<vertices;i++){
                int val; 
                cout<<"\nEnter the starting node: "; cin>>val;
                Node* newNode = new Node(val);
                if(root == NULL){ 		//to insert the first element
                    root = newNode;
                    temp1 = root;
                }
                else{
                    temp1->down = newNode;
                    temp1 = temp1->down;
                }
                Node* temp = temp1;;	//to traverse or insert neighbours horizontally
                cout<<"How many edges are connected with "<<val<<": "; cin>>edge;
                 for(int j=0;j<edge;j++){
                    cout<<"Enter the ending node of <<"<<val<<": "; cin>>val;
                    Node* newNode = new Node(val);
                    temp->next = newNode;
                    temp = temp->next;
                 }
            }
        }

    private: 

        Node* findNode(int val){
            Node* temp = root;
            while(temp->data!=val){
                temp = temp->down;
            }
            return temp;
        }

        void dfs_main(int node,bool vis[],vector<int> &ls){
                
                vis[node] = true;
                ls.push_back(node);

                Node* point = findNode(node);
                point = point->next;		//point will point to its first neighbour

                while(point){
                    if(!vis[point->data]){
                        dfs_main(point->data,vis,ls);}
                        point = point->next;
                }
        }


    public:

        void display() {
            temp1 = root;
            cout<<"--------------------------------------"<<endl;
            for (int i = 0; i < vertices; i++) {
                Node* temp = temp1;
                cout << temp1->data << ": ";
                temp = temp->next;
                while (temp) {
                    cout << "->" << temp->data;
                    temp = temp->next;
                }
                temp1 = temp1->down;
                cout << endl; // Move to the next line after each row
            }
            cout<<"--------------------------------------";

        }

        void degree(){
            cout<<"\nEnter the number to find degree: "; int val; cin>>val;
            Node* point = findNode(val);
            point = point->next;
            int degree = 1;

            while(point){
                point = point->next;
                degree+=1;
            }

            cout<<"The degree of "<<val<<" is "<<degree<<endl;
        }

        void bfs() {
            queue<Node*> q;
            bool visited[vertices] = {false};
            cout << "\nEnter the vertex from which bfs is required: ";
            int v;
            cin >> v;
            visited[v] = true;
            Node* temp2 = findNode(v);
            q.push(temp2);
            vector<int> bfs;

            while (!q.empty()) {
                Node* front = q.front();
                q.pop();
                bfs.push_back(front->data);

                Node* pointer = front->next; // Start from the first neighbor of the current node

                while (pointer) { // Iterate through neighbors
                    if (!visited[pointer->data]) {
                        q.push(findNode(pointer->data)); // Push the neighbor into the queue
                        visited[pointer->data] = true; // Mark the neighbor as visited
                    }
                    pointer = pointer->next; // Move to the next neighbor
                }
            }

            // Print the BFS traversal
            cout << "BFS Traversal: ";
            for (int node : bfs) {
                cout << node << " ";
            }
            cout << endl;
        }

        void dfs(){
            cout<<"Enter the starting value to start dfs: "; int val; cin>>val;
            bool visited[vertices] = {false};
            vector<int> dfs;
            dfs_main(val,visited,dfs);
 
            cout << "\nDFS Traversal: ";
            for (int node : dfs) {
                cout << node << " ";
            }
            cout << endl;
        }

};

int main(){
    Graph g1;
    g1.insert();
    g1.display();
    // g1.bfs();
    // g1.bfs();
    g1.dfs();
}

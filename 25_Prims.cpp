#include<iostream>
#include<vector>
using namespace std;
#define MAX 20
#define I 9999     //infinity

class Graph{
	int vertices;
	int G[MAX][MAX];

	public:
        Graph()
        {
            vertices = 0;
        }
        
        void readGraph(){
            cout<<"\nEnter no. of vertices : "; cin>>vertices;
            int ans,weight;

            for(int i = 0; i < vertices ; i++)
            {
                for(int j = i; j < vertices ; j++)
                {
                    if(i==j)
                    {
                        G[i][j]=I;
                        
                    }
                    else
                {
                    
                    cout<<"\nIs there an edge between "<<i<<" and "<<j<<" ? (1/0) : ";
                    cin>>ans;
                    
                    if(ans == 1)
                    {
                        cout<<"\nEnter weight : ";
                        cin>>weight;
                        
                        G[i][j] = G[j][i] = weight;
                        
                    }
                    else
                    {
                        G[i][j] = G[j][i] = I;   // I = infinity
                    }
                }
                }
            }
        }
        
    private:
        int find_min(int key[], bool mst[]){
            int minn = I; // Initialize minn to infinity
            int i; int ans;
            for(i = 0; i < vertices; i++){
                if(!mst[i] && key[i] < minn){ // Check if the vertex is not in MST and key is less than current minn
                    minn = key[i];
                    ans = i;
                }
            }
            return ans;
        }

        vector <int> get_neighbour(int index){
            vector<int> adj;
            for(int i=0;i<vertices;i++){
                if(G[i][index]!=I)
                    adj.push_back(i);
            }
            return adj;
        }
    
    public:

        void printGraph(){
            for(int i = 0; i < vertices; i++)
            {
                for(int j = 0; j < vertices ; j++)
                {
                    if(G[i][j] == I)
                    {
                        cout<<" I";
                    }
                    else
                    {
                        cout<<" "<<G[i][j];
                    }
                }
            cout<<endl;
            }   
        }

        int prims(){
            bool mst[vertices];
            int key[vertices];      //initially infinity
            int parent[vertices];  //parent
            
            for(int i = 1; i < vertices; i++){
                    key[i] = I;     // Initialize all other keys to infinity
                    mst[i] = false;
                    parent[i] = -1;
            }

        //start with the algo
        key[0] = 0;
       

        for(int i = 0 ; i<vertices ; i++){
            int index = find_min(key,mst);
            
            mst[index] = true;
            vector <int> neighbours= get_neighbour(index);

            for(int j=0;j<neighbours.size();j++){
                int neigh = neighbours[j];
                if(!mst[neigh]){
                    int weight = G[index][neigh];
                    if(weight<key[neigh])
                        key[neigh]=weight;
                }
                parent[neigh] = index;
            }
        }

        //display
        for(int k=1;k<vertices;k++){
            cout<<parent[k]<<"->"<<k<<" :"<<key[k]<<endl;
        }
    }
};

 int main()
{
	Graph g;
	g.readGraph();
	 
	cout<<"\nOriginal graph : \n";
	g.printGraph();
	
	cout<<"\nMST : \n";
	 g.prims();
	
	 
}
 


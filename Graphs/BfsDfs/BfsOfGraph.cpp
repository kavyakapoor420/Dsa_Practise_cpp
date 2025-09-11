#include<iostream>
#include<vector>
#include<queue>
#include<list> 

using namespace std ;

class Graph{
    
    int V ;
    list<int> * l ;

public: 
    Graph(int V){
        this->V=V ;
        l=new list<int> [V] ;
        //arr=new int[V] ; 
    }

    void addEdge(int u ,int v){
        l[u].push_back(v) ;
        l[v].push_back(u) ; 
    }


    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<" " ;
            for(int neigh:l[i]){
                cout<<neigh<<" " ; 
            }
            cout<<endl  ;
        }
    }
};


vector<int> BfsOfGraph(int V ){

    vector<int> bfs ; 
    queue<int> q ;
    vector<int> vis(V,false) ;

    int startNode=0  ;
 
    q.push(startNode) ;
    vis[startNode]=true ; 

    while(q.size()>0){
        int u=q.front() ;
        q.pop() ;

        cout<<u<<" " ;

        for(int v :l[u]){ //immediate neighbor 
            if(!vis[v]){
                vis[v]=true ; 
                q.push(v)  ;
            }
        }
    }
    cout<<endl ; 

    return bfs ; 
}

int main() {


    Graph g(5) ;

    g.addEdge(0,1) ;
    g.addEdge(1,2) ;

}
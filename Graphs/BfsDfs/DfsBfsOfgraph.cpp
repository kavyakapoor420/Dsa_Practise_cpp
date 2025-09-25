#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std ;


class Graph{
     
    private: 
    unordered_map<int,vector<int>> adj ;
    int V ;

    public:

    Graph(int vertices){
        V=vertices;
    }

    void addEdge(int u, int v,bool directed=false){
        adj[u].push_back(v) ;

        if(!directed){
            adj[v].push_back(u) ;// for undirected graph 
        }
    }

    void printAdjList(){
        cout<<"adjacency list of given graph is"; 

        for(auto& pair:adj){
            cout<<pair.first<<"->" ; 
            for(int nbr:pair.second){
                cout<<nbr<<" " ;
            }
            cout<<endl ; 
        }
    }

    // utility function for DFS
    void dfsUtil(int node,vector<bool>& vis, vector<int>& dfsTraversal){
        vis[node]=true ; 
        cout<<node<<" " ;
       ; 
        dfsTraversal.push_back(node) ;

        for(int nbr:adj[node]){
            if(!vis[nbr]){
                dfsUtil(nbr,vis,dfsTraversal) ; 
            }
        }
    }
    // dfs traversal
    vector<int> dfs(int srcNode){
        vector<bool> visited(V+1,false) ; 
        vector<int> dfsTraversal(V+1) ; 

        cout<<"dfs tarversal starting from "<<srcNode<<" ";
        dfsUtil(srcNode,visited,dfsTraversal) ;  
        cout<<endl ;

        return dfsTraversal ; 
    }

    // bfs traversal 

    void bfs(int srcNode){
        vector<bool> visited(V+1,false) ;
        queue<int> q; 

        visited[srcNode]=true ;
        q.push(srcNode) ;

        while(!q.empty()){
            int frontNode=q.front() ;
            q.pop() ;

            for(int nbr:adj[frontNode]){
               if(!visited[frontNode]){
                 visited[frontNode]=true ;
                 q.push(frontNode) ; 
               }
            }
        }
        cout<<endl ; 
    }
};


int main(){
    
    Graph g(6) ;

     // Add edges
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);

    g.printAdjList();

    g.dfs(1);
    g.bfs(1);

}


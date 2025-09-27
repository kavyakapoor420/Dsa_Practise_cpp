#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std ; 


vector<int> shortestPath(vector<vector<int>>&edges,int n,int m,int src, int dest){
  
    // create adj list 
    unordered_map<int,vector<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0] ;
        int v=edges[i][1] ;

        adj[u].push_back(v) ;
        adj[v].push_back(u) ; 
    }

    // do bfs 
    unordered_map<int,bool> vis ;
    unordered_map<int,int> parent ;
    vis[src]=true ;
    queue<int> q;
    q.push(src); 
    parent[src]=-1;

    while(!q.empty()){
        int front=q.front() ;
        q.pop() ;

        for(auto nbr:adj[front]){
            if(!vis[nbr]){
                vis[nbr]=true ;
                parent[nbr]=front ;
                q.push(nbr); 
            }
        }
    }
    // prepare shortest path 
    vector<int> ans ;
    int currNode=dest ;
    ans.push_back(currNode);
    while(currNode!=src){
        currNode=parent[currNode];
        ans.push_back(currNode) ; 
    }

    reverse(ans.begin(),ans.end()) ; 
    return ans ; 

}

int main(){

}


class Graph{

    private: 
    int V ;
    unordered_map<int,vector<pair<int,int>>> adj ; // node,weight

    public: 

    Graph(int vertices){
        V=vertices; 
    }

    void addEdge(int u,int v,int wt){
        adj[u].push_back({v,wt}) ;
        adj[v].push_back({u,wt}) ; // undirected
    }

    // find shorted path from src to dest using bfs 
    void shortestPath(int src,int dest){
         vector<bool> vis(V+1,false) ;
         vector<int> parent(V+1,-1) ;
         vector<int> dist(V+1,-1) ; // distance from src to node

         queue<int>q ;
         vis[src]=true ;
         dist[src]=0;
         q.push(src) ;

         while(!q.empty()){
            int node=q.front() ;
            q.pop() ;

            for(auto nbr:adj[node]){
                if(!vis[nbr.first]){
                    vis[nbr.first]=true ;
                    parent[nbr.first]=node;
                    dist[nbr.second]=dist[node]+1;
                    q.push(nbr.first);

                    if(nbr.first=dest){
                        break ; 
                    }
                }
            }
            if(!vis[dest]){
                cout<<'no path exists';
                return ; 
            }

            // reconstruct paht from dest to src 
            vector<int> ans ;
            for(int v=dest;v!=-1;v=parent[v]){
                ans.push_back(v) ;
            }
            reverse(ans.begin(),ans.end()) ; 

            
         }
    }
};

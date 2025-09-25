#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

class Graph{


    private:
    unordered_map<int,vector<int>> adj; 
    int V ;

    public:
    Graph(int vertices){
        V=vertices; 
    }

    void addEdge(int u,int v){
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    // utility dfs function for cycle detection
    bool dfsUndirCycleUtil(int node,int parent,vector<bool>& vis){
        vis[node]=true ;

        for(int nbr:adj[node]){
            if(!vis[node]){
                if(dfsUndirCycleUtil(nbr,node,vis)){
                    return true ; 
                }
            }else if(nbr!=parent){
                return true ; // back edge found ;
            }
        }
        return false ; 
    }
    
    // dfs cycle detection
    bool hasCycleDfs(){
        vector<bool> vis(V+1,false) ;

        for(int i=1;i<=V;i++){
            if(!vis[i]){
                if(dfsUndirCycleUtil(i,-1,vis)){
                    return true ; 
                }
            }
        }
        return false ; 
    }

    // bfs cycle detection 

    bool hasCycleUndirBfs(){
        vector<bool> vis(V+1,false) ;

        for(int startNode=1;startNode<=V;startNode++){
            if(!vis[startNode]){
                queue<pair<int,int>> q; // (node,parent)
                q.push({startNode,-1}) ;
                vis[startNode]=true ; 

                while(!q.empty()){
                    int node=q.front().first ;
                    int parent=q.front().second ;
                    q.pop() ;

                    for(int nbr:adj[node]){
                        if(!vis[nbr]){
                            vis[nbr]=true ;
                            q.push({nbr,node}) ; 
                        }else if(nbr!=parent){
                            return true ; // cycle found 
                        }
                    }
                }
            }
        }
        return false ; 
    }
};


int main(){


}
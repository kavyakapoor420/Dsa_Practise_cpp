#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<limits>

using namespace std ;

class Graph{
    private:
    int V ;
    unordered_map<int,vector<pair<int,int>>> adj ; // node-> [(nbr,weight)]

    public:
    Graph(int vertices){
        V=vertices ;
    }

    void addEdge(int u,int v,int wt){
        adj[u].push_back({v,wt}) ; 
    }

    void topoSortUtil(int node,vector<bool>& visited,stack<int>& st){
        visited[node]=true ;

        for(auto& edge:adj[node]){
            int nbr=edge.first ;
            if(!visited[nbr]){
                topoSortUtil(nbr,visited,st) ; 
            }
        }
        st.push(node) ; 
    }

    // shortest path from src in DAG 
    void shortestPathDAG(int src){
        vector<bool> visited(V+1,false) ; 
        stack<int> st; 


        // topological sort 
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                topoSortUtil(i,visited,st) ; 
            }
        }
        // initialize distances to all vertices as infinite and distance to source as 0
        vector<int> dist(V+1,INT_MAX) ;
        dist[src]=0 ;

        // process vertices in topological order 
        while(!st.empty()){
            int node=st.top() ;
            st.pop() ;

            if(dist[node]!=INT_MAX){
                for(auto& edge:adj[node]){
                    int nbr=edge.first ;
                    int wt=edge.second ;

                    if(dist[node]+wt<dist[nbr]){
                        dist[nbr]=dist[node]+wt ; 
                    }
                }
            }
        }

        //print distances 
        cout<<'shortest distances from '<<src<<'\n' ;

        for(int i=1;i<=V;i++){
            if(dist[i]==INT_MAX){
                cout<<'Distance to node '<<i<<' is infinity\n' ;
            }else{
                cout<<'Distance to node '<<i<<' is '<<dist[i]<<'\n' ;
            }
        }
    }
};

int main(){

}
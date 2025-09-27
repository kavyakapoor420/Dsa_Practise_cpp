#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std ;

class Graph{
    
    private :  
    int V;
    unordered_map<int,vector<int>> adj ;

    public : 
    Graph(int vertices){
        V=vertices;
    }
    
    // add edge (directed graph)
    void addEdge(int u,int v){
        adj[u].push_back(v) ;
    }

    // dfs topo sort
    void dfsUtil(int node,vector<bool>& vis,stack<int>& st ){
        vis[node]=true ;

        for(int nbr:adj[node]){
            if(!vis[node]){
                dfsUtil(nbr,vis,st) ; 
            }
        }

        st.push(node) ; // push after visiting all neigbors before backtracing push node into stack 
    }
    
    void topoSortDfs(){
        vector<bool> vis(V+1,false) ;
        stack<int> st ;

        for(int i=1;i<=V;i++){
            if(!vis[i]){
                dfsUtil(i,vis,st); 
            }
        }

        cout<<"topological sort dfs()" ;

        while(!st.empty()){
            cout<<st.top()<<" " ;
            st.pop() ;
        }
        cout<<endl ;
    }

    // bfs topo sort kahns algo 
    void topoSortBfs(){
        vector<int> indegree(V+1,0) ;

        //compute indegree

        for(auto &p:adj){
            for(int nbr:p.second){
                indegree[nbr]++ ;
            }
        }

        queue<int> q; 
        for(int i=1;i<=V;i++){
            if(indegree[i]==0){
                q.push(i) ; 
            }
        }

        cout<<" topological sort bfs(kahn)" ; 

        while(!q.empty()){
            int node=q.front() ;
            q.pop() ;

            cout<<node<<" " ;

            for(int nbr:adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr) ; 
                }
            }
        }
        cout<<endl ; 
    }
};

int main(){

}
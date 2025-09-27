#include<vector>
#include<queue>
#include<iostream>

using namespace std; 

class Graph{

    private:
    int V ;
    unordered_map<int,vector<int>> adj ;

    public:
    Graph(int vertices){
        V=vertices;
    }

    // add directed edge
    void addEdge(int u,int v){
        adj[u].push_back(v) ; 
    }

    // dfs cycle detection 
    bool dfsCycleDirectedUtil(int node,vector<bool>& vis,vector<bool>& recStack){
        vis[node]=true ;
        recStack[node]=true ;

        for(int nbr:adj[node]){
            if(!vis[nbr]){
                if(dfsCycleDirectedUtil(nbr,vis,recStack)){
                    return true ; 
                }
            }else if(recStack[nbr]){ // vis[nbr]==true and recStack[nbr]=true 
                return true ; // back edge found 
            }
        }

        recStack[node]=false ; // backtrack ; 
        return false ; 
    }

    bool hasCycleDfs(){
        vector<bool> vis(V+1,false) ;
        vector<bool> recStack(V+1,false) ;

        for(int i=1;i<=V;i++){
            if(!vis[i]){
                if(dfsCycleDirectedUtil(i,vis,recStack)){
                    return true ; 
                }
            }
        }

        return false ; 
    }

    // bfs cycle detection Kahns algo
    bool hasCycleDirectedBFS(){
        vector<int> indegree(V+1,0);


        // compute indegree
        for(auto& p:adj){
            for(int nbr:p.second){
                indegree[nbr]++; 
            }
        }

        queue<int>q ;
        for(int i=1;i<=V;i++){
            if(indegree[i]==0){
                q.push(i) ;
            }
        }

        int cnt=0; // number of nodes processed 
        while(!q.empty()){
            int node=q.front() ;
            q.pop() ;
            cnt++ ;

            for(int nbr:adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr) ; 
                }
            }
        }

        // if processed node < total node , so cycle exists 
        return (cnt!=V) ;
    }
};

int main() {


}
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




class Graph{
   private :
   unordered_map<int,vector<int>> adj ;
   int v;

   public:
   Graph(int vertices){
    v=vertices ; 
   }
    
   void addEdge(int u,int v){
    adj[u].push_back(v) ; 
   }

   void shortestPath(int src,int dest){
    vector<bool> visited(v+1,false) ;
    vector<int> parent(v+1,-1) ;
    vector<int> dist(v+1,-1) ; 

    queue<int> q;
    visited[src]=true ;
    dist[src]=0;
    q.push(src) ;

    while(!q.empty()){
        int front=q.front() ;
        q.pop() ;

        for(int nbr:adj[front]){
            if(!visited[nbr]){
                visited[nbr]=true ;
                parent[nbr]=front ;
                dist[nbr]=dist[front]+1 ; 
                q.push(nbr) ; 

                if(nbr==dest) break ; 
            }
        }
    }
    if(!visited[dest]){
        cout<<'no path exists from '<<src<<'to'<<dest ;
        return ; 
    }

    vector<int> path ;
    for(int v=dest;v!=-1;v=parent[v]){
        path.push_back(v) ; 
    }
    reverse(path.begin(),path.end()) ;
    return  ; 
   }

   bool dfsUtilCycleDetectDirGraph(int node,vector<bool>& visited,vector<int>& recStack){
     visited[node]=true ;
     recStack[node]=1 ; 

     for(int nbr:adj[node]){
        if(!visited[nbr]){
            if(dfsUtilCycleDetectDirGraph(nbr,visited,recStack)){
                return true ; 
            }
        }else if(recStack[nbr]) return true ; 
     }
     recStack[node]=false ;
     return false ; 
   }

   bool hasCycleDirectedDFS(){
    vector<bool> visited(v+1,false) ;
    vector<int> recStack(v+1,false) ;

    for(int i=1;i<=v;i++){
        if(!visited[i]){
            if(dfsUtilCycleDetectDirGraph(i,visited,recStack)){
                return true ; 
            }
        }
    }
    return false; 
   }

   bool hasCycleBFS(){
    vector<int> indegree(v+1,0) ;

    for(auto& p:adj){
        for(int nbr:p.second){
            indegree[nbr]++ ; 
        }
    }
    queue<int> q;

    for(int i=1;i<=v;i++){
        if(indegree[i]==0){
            q.push(i) ; 
        }
    }

    int cnt=0; // number of nodes processes 

    while(!q.empty()){
        int front=q.front() ;
        q.pop() ;
        cnt++ ;

        for(int nbr:adj[front]){
            indegree[nbr]-- ; 
            if(indegree[nbr]==0){
                q.push(nbr) ; 
            }
        }
    }

    return cnt!=v  ; // if processed node < total nodes then no cycle 
   }

   // toposort using bfs and dfs

   void addEdge(int u,int v){
    adj[u].push_back(v) ; 
   }

   void dfsUtil(int node,vector<bool>& visited,stack<int>& st){
    visited[node]=true ;

    for(int nbr:adj[node]){
        if(!visited[nbr]){
            dfsUtil(nbr,visited,st) ; 
        }
    }
    st.push(node) ; // push after all neigbrs are procssed after visiting all neigbirs befire bactracking pusin nodes into stck 
   }

   void topoSortDfs(){
    vector<bool> visited(v+1,false) ;
    stack<int> st; 

    for(int i=1;i<=v;i++){
        if(!visited[i]){
            dfsUtil(i,visited,st) ; 
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" " ;
        st.pop() ; 
    }
   }

   // bfs toposort kahn algo 
   void topoSortBfs(){
    
   }

   void dijsktras(int src){
    vector<int> dist(v+1,INT_MAX) ;
    dist[src]=0;

    // min heao priority queue(distance node)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  pq;
    pq.push({0,src}) ;

    while(!pq.empty()){
        int d=pq.top().first ;
        int node=pq.top().second ;
        pq.pop() ;

        // skip if this distance is not current best 
        if(d>dist[node]) continue ; 

        for(auto& edge:adj[node]){
            int nbr=edge.first ;
            int wt=edge.second ;

            if(dist[node]+wt<dist[nbr]){
                dist[nbr]=dist[node]+wt ;
                pq.push({dist[nbr],nbr}) ; 
            }
        }
    }
   }
}; 








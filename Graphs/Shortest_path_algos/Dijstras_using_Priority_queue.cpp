#include<vector>
#include<iostream>
#include<set>
#include<queue>
#include<climits> 

using namespace std ;

vector<int> dijkstras(int V, int src, vector<vector<int>> adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;


    vector<int> result(V,INT_MAX) ;
    result[src]=0;
    pq.push({0,src}) ;

    while(!pq.empty()){
        int dist=pq.top().first ;
        int node=pq.top().second ;
        pq.pop() ;

        for(auto &vec:adj[node]){
            int adjNode=vec[0];
            int wt=vec[1];

            if(dist+wt<result[adjNode]){
                result[adjNode]=dist+wt ;
                pq.push({result[adjNode],adjNode}) ;
            }
        }
    }

    return result ; 
}

int main(){
    int V=5;

    // sample graph eges : u--wt-> v ;
    vector<vector<int>> adj[V] ;
    adj[0].push_back({1,2}) ;
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[4].push_back({2, 2});
    adj[2].push_back({3, 6});
    adj[4].push_back({3, 4});

    vector<int> dist=dijkstras(V,0,adj) ;

    cout<<"shortest distancd from source" ;

    for(int i=0;i<V;i++){
        cout<<"Node"<<i<<':'<<dist[i]<<'\n' ;
    }

}


/*
-----------------------------------------
DIJKSTRA'S ALGORITHM (SHORTEST PATH)
-----------------------------------------
1. Initialize a distance array with INT_MAX (∞).
2. Set distance of source node = 0.
3. Use a min-heap priority queue storing {distance, node}.
4. While PQ is not empty:
    a) Extract node with smallest distance.
    b) Traverse all its adjacent nodes.
    c) If (currentDistance + edgeWeight < distance[adjNode]),
       update distance[adjNode] and push into PQ.
5. At the end, 'result' contains the shortest distance
   from source to every other node in the graph.
-----------------------------------------
Time Complexity: O((V + E) * logV)
Space Complexity: O(V)
-----------------------------------------
Graph Representation:
adj[i] contains list of {adjNode, weight} for node i.
-----------------------------------------
*/

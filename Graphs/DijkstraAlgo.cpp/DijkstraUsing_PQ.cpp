#include<iostream>
#include<vector>
#include<queue>
using namespace std; 


vector<int> shortesTpath(int n,vector<vector<int>>& adj[],int src){

    // declare min heap (dist,node)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq ;

    vector<int> dist ;

    dist[src]=0;
    for(int x:dist){
        dist[x]=1e9 ; 
    }
    pq.push({0,src}) ;

    while(!pq.empty()){
        int dist =pq.top().first ;
        int node=pq.top().second ;
        pq.pop() ;

        for(auto it:adj[node]){
            int edgeWeight=it[1];
            int adjNode=it[0];
            
            if(dist+edgeWeight<dist[adjNode]){
                dist[adjNode]=dist+edgeWeight ; 
                pq.push({dist[adjNode],adjNode}) ; 
            }
        }
    }

    return dist;
}
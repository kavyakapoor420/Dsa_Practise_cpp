#include<iostream>
#include<vector>
#include<set>
#include<climits>

using namespace std ;

vector<int> dijsktars(int V, int src, vector<vector<int>> adj[]){
    set<pair<int,int>> st ;
    vector<int> result(V,INT_MAX) ;
    result[src]=0 ;
    st.insert({0,src}) ;

    while(!st.empty()){
        auto itr=*st.begin() ;
        int d=itr.first ;
        int node=itr.second ;

        st.erase(itr) ;

        for(auto &vec:adj[node]){
            int adjNode=vec[0];
            int dist=vec[1];

            if(d+dist<result[adjNode]){
                //remove old pair if it exists 
                if(result[adjNode]!=INT_MAX){
                    st.erase({result[adjNode],adjNode}) ;
                }
                result[adjNode]=d+dist ;
                st.insert({result[adjNode],adjNode}) ; 
            }
        }
    }
    return result ; 
}

int main(){
    int V=5;
    vector<vector<int>> adj[V] ;

    adj[0].push_back({1,2}) ;
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[4].push_back({2, 2});
    adj[2].push_back({3, 6});
    adj[4].push_back({3, 4});

    vector<int> dist=dijsktars(V,0,adj) ; 

    cout<<"shortest distances from source 0:\n" ;

    for(int i=0;i<V;i++){
        cout<<"node"<<i<<":"<<dist[i]<<'\n' ; 
    }
}


/*
-----------------------------------------
DIJKSTRA'S ALGORITHM (USING SET)
-----------------------------------------
1. Use a set to store {distance, node} (acts like a min-priority queue).
2. Initialize all distances as INT_MAX except source = 0.
3. Insert {0, src} into set.
4. While set is not empty:
   a) Take the element with smallest distance (st.begin()).
   b) Remove it from set.
   c) For each adjacent node:
      - If currentDistance + edgeWeight < result[adjNode],
        update distance and:
        * erase old {dist, adjNode} from set (if it exists)
        * insert new {newDist, adjNode}.
5. Return result array containing shortest distances.
-----------------------------------------
Time Complexity: O((V + E) * logV)
Space Complexity: O(V)
-----------------------------------------
Graph Representation:
adj[i] contains list of {adjNode, weight} for node i.
-----------------------------------------
*/
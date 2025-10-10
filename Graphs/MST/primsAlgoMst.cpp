#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Graph{
   private:
   unordered_map<int,vector<pair<int,int>>> adj ; // node->[nbr,wt]
   int V ;

   public:
   Graph(int vertices){
     V=vertices; 
   }

   // add undirected edge
   void addEdge(int u,int v,int wt){
    adj[u].push_back({v,wt}) ;
    adj[v].push_back({u,wt}) ; 
   }

   void primsMST(){
    vector<int> key(V+1,INT_MAX) ; // min weight to reach node or mini weight to add this vertex
    vector<int> parent(V+1,-1) ; 
    vector<bool> inMST(V+1,false) ; // track if node is included in mst or not

    // min heap(key,vertex)
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    // sort from vertex 1
    key[1]=0;
    pq.push({0,1}) ;

    while(!pq.empty()){
        int u=pq.top().second ;
        pq.pop() ;

        if(inMST[u]) continue ; // if already included in mst skip
        inMST[u]=true ; // include vertex in mst
        // traverse all adjacent vertices
        for(auto& edge:adj[u]){
            int v=edge.first ;
            int wt=edge.second ;

            // if v is not in mst and weight of u-v is smaller than current key of v
            if(!inMST[v] && wt<key[v]){
                key[v]=wt ;
                parent[v]=u ;
                pq.push({key[v],v}) ; 
            }
        }
    }
    cout<<'edges inmst' ;
    int totalWt=0;
    for(int i=2;i<=V;i++){
        if(parent[i]!=-1){
            cout<<parent[i]<<"->"<<i<<'weight'<<key[i];
            totalWt+=key[i];
        }
    }
    cout<<'total weight of mst'<<totalWt ; 
   }



   // kruskal algo 
   class DisjoinSet{
      vector<int> parent, rank ;

      public:
      DisjoinSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0) ;

        for(int i=0;i<=n;i++){
            parent[i]=i  ; 
        }
      }

      int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]) ; // path compression
        }
        return parent[x];
      }

      bool unionn(int x,int y) {
           int parX=find(x) ;
           int parY=find(y) ;

           if(parX==parY) return false ;
           else if(rank[parX]>rank[parY]){
            parent[parY]=parX ;
           }else{
            parent[parY]=parX; 
            rank[parX]++ ; 
           }

           return true ; 
      }

      struct Edge{
        int u,v,wt; 
      };

      void KruskaMst(){
        sort(edges.begin(),edges.end(),[](Edge&a ,Edge&b )){
            return a.w<b.w ; 
        }

        DisjoinSet ds(V) ;
        int totalWt=0;

        cout<<'edges in mst' ;

        for(auto& edge:edges){
            if(ds.unionn(edge.u,edge.y)){
                cout<<edge.u<<'->'<<edge/v<<'weight'<<edge.wt ;
                totalWt+=edge.wt ; 
            }
        }
      }
   };
};

int main(){

}




export async function POST(req:Request){
  
  try{
const {messages}:{messages:UIMessage[]}=await req.json() ;

  const result=streamText({
    model:openai('gpt-4.1-mini'),
    messages:convertToModelMessages(messages), 
  })

  return result.toUIMessageStreamResponse() ;
  }catch(err){
    console.error('error streaming chat completion',err)
    return new Response('failed to stream chat completion',{status:500})
  }
  
}

'use client'

export default function RAGChattbot(){
  return (
    <>
    
    </>
  )
}
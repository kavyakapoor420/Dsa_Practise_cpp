#include<iostream>
#include<vector>
#include<list>

using namespace std ;

class Graph{
    int V;
    list<int>* l;

    Graph(int V){
       this->V=V ;
       l=new list<int>[V] ; 
    }

    void addEdge(int u,int v){
        l[u].push_back(v) ;
        l[v].push_back(u) ; 
    }

    bool isCycleUndirDfs(int src,vector<bool>& vis,int par){
        vis[src]=true ;
        list<int> nbr=l[src];

        for(int v:nbr){
            if(!vis[v]){
                if(isCycleUndirDfs(v,vis,src)){
                    return true ; 
                }
            }else if(v!=par){
                return true ; 
            }
        }

        return false ; 
    }

    bool isCycle(){
        vector<bool> vis(V,false) ; 

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycleUndirDfs(i,-1,vis)){
                    return true ; 
                }
            }
        }
        return false ; 
    }
};

int main() {

}
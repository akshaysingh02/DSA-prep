#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<int> adj[], int v, int w){
    adj[v].push_back(w);
}

bool checkCycleUtil (vector<int> adj[],vector<bool> &vis,vector<bool> &dfsvis, int s){
    vis[s] = true;
    dfsvis[s] = true;

    for(auto it: adj[s]){
        if(!vis[it]){
            if(checkCycleUtil(adj,vis,dfsvis,it)) return true;
        }
        else if(dfsvis[it]) return true;
    }
    dfsvis[s] = 0;
    return false;
}

bool checkCycle(vector<int> adj[],int v){
    vector<bool> vis(v+1,false);
    vector<bool> dfsvis(v+1,false);

    for(int i = 1; i<=v; i++){
        if(!vis[i]){
            if(checkCycleUtil(adj,vis,dfsvis,i)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int V = 9;

    vector<int> adj[V+1];
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,3,6);
    addEdge(adj,6,5);
    addEdge(adj,7,2);
    addEdge(adj,7,8);
    addEdge(adj,8,9);
    addEdge(adj,9,7); 

    if(checkCycle(adj,V))
        cout<<"Yes, cycle detected in directed graph"<<endl;
    else
        cout<<"No, no cycle detected in directed graph"<<endl;
    

    return 0;

}
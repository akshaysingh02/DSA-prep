#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<int> adj[],int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool isCycleUtil(int node,int parent, vector<bool> &vis, vector<int> adj[]){

    vis[node] = true;

    for(auto it : adj[node]){
        if(!vis[it]){
            if(isCycleUtil(it,node,vis,adj)) return true;
        }
        else if(it != parent) return true;
    }

    return false;
}

bool isCycle(vector<int> adj[], int v){
    vector<bool> vis(v,false);

    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(isCycleUtil(i,-1,vis,adj)) return true;
        }
    }
    return false;
}

int main(){

    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0,3);
    addEdge(adj, 1,2);
    // addEdge(adj, 2,3);

    if(isCycle(adj, V))
        cout<<"Cycle detected"<<endl;
    else
        cout<<"No cycle detected"<<endl;


    return 0;
}
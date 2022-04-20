#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void addEdge(vector<int> adj[],int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void dfsUtil(vector<int>adj[],vector<bool> &vis, int s){

    vis[s] = true;
    cout<<s<<" ";


    for(auto it: adj[s]){
        if(!vis[it]){
            dfsUtil(adj,vis,it);
        }
    }
    return;
}

void dfs(vector<int> adj[], int v){
    vector<bool> vis(v+1, 0);
    for(int i = 1; i<=v;i++){
        if(!vis[i]){
            dfsUtil(adj,vis,i);
        }
    }
    cout<<endl;
}


bool isBipartiteUtil(vector<int> adj[], vector<int> &color, int s){
    
    if(color[s]==-1)
        color[s] = 0;

    for(auto it: adj[s]){
        if(color[it]==-1){
            color[it] = 1 - color[s];
            if(!isBipartiteUtil(adj,color,it)){
                return false;
            }  
        }
        else if(color[it]==color[s]){
            return false;
        }
    }
    return true;
}


bool isBipartite(vector<int> adj[], int v){
    vector<int> color(v+1, -1);

    for(int i = 1; i<=v; i++){
        if(color[i] == -1){
            if(!isBipartiteUtil(adj,color,i)){
                return false;
            } 
        }
    }
    return true;
}


int main(){
    int V = 8;
    vector<int> adj[V+1];

    addEdge(adj, 1,2);
    addEdge(adj, 2,3);
    addEdge(adj, 2,6);
    addEdge(adj, 3,4);
    addEdge(adj, 4,5);
    addEdge(adj, 5,7);
    addEdge(adj, 7,8);
    addEdge(adj, 6,5);

    dfs(adj,V);

    if(isBipartite(adj,V))
        cout<<"Yes, the graph is bipartite"<<endl;
    else
        cout<<"No, the graph is not bipartite"<<endl;    





    return 0;
}
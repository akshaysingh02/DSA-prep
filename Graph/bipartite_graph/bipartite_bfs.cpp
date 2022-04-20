//This is the code for checking bipartite graph using bfs (breadth first search)
//This program is also using bfs, and its printing connected and disconnected components.
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void addEdge(vector<int> adj[],int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void bfsUtil(vector<int> adj[],vector<bool> &vis,int v,int s){
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        for(auto it: adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = true;
            }
        }
    }
}

void bfs(vector<int> adj[], int v){
    vector<bool> vis(v+1, false);

    for(int i = 1; i<=v;i++){
        if(!vis[i]){
            bfsUtil(adj,vis,v,i);
        }
    }
}


bool isBipartiteUtil(vector<int> adj[], vector<int> &color, int s){

    queue<int> q;
    color[s] = 0;
    q.push(s);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(color[it] == -1 ){
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<int> adj[],int v){
    vector<int> color(v+1, -1);

    for(int i = 1; i<= v;i++){
        if(color[i] == -1){
            if(!isBipartiteUtil(adj,color,i)) return false;
        }
    }
    return true;
}




int main(){

    int V = 8;
    vector<int> adj[V+1];
    
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,2,8);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,8,5);
    addEdge(adj,5,6);
    addEdge(adj,6,7);

    if(isBipartite(adj,V))
        cout<<"Yes, the graph is bipartite"<<endl;
    else
        cout<<"NO, the graph is not bipartite"<<endl;

    cout<<"And its bfs traversal is: ";
    bfs(adj,V);

    return 0;
}
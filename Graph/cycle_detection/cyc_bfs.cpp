#include<iostream>
#include<vector>
#include<queue>

using namespace std;


void addEdge(vector<int> adj[],int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool isCyclicConnected(vector<int> adj[],int s, int v, vector<bool> &vis){
    vector<int> parent(v,-1);

    queue<int> q;
    vis[s] = true;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v : adj[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
                parent[v] = u;
            } 
            else if (parent[u] != v){
                return true;
            }
        }
    }
    return false;
}

bool isCyclicDisonnected(vector<int> adj[],int v){
    vector<bool> vis(v,false);

    for(int i =0; i<v;i++){
        if(!vis[i] && isCyclicConnected(adj, i, v, vis)){
            return true;
        }
    }
    return false;
}


int main()
{
    int V = 9;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2,1);
    addEdge(adj, 3,4);
 
    if (isCyclicDisonnected(adj, V))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}
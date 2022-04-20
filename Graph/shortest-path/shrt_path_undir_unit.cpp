#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void addEdge(vector<int> adj[],int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void shortestPath(vector<int> adj[],int v,int src){
    vector<int> dist(v+1, INT_MAX);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(dist[node]+1 < dist[it]){
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }

    for(int i=0;i<=v;i++){
        cout<<dist[i]<<" ";
    }
}

int main(){
    int V = 7;

    vector<int> adj[V+1];
    addEdge(adj,0,1); 
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,2,6);
    addEdge(adj,2,4);
    addEdge(adj,4,7);
    addEdge(adj,4,5);

    shortestPath(adj,V,0);


    return 0;

}
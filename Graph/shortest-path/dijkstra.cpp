#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void addEdge(vector<pair<int,int>> adj[],int v, int w, int wt){
    adj[v].push_back({w,wt});
    adj[w].push_back({v,wt});
}

void shortestPath(vector<pair<int,int>> adj[],int v,int src){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(v+1, INT_MAX);

    dist[src] = 0;
    pq.push({0,src});

    while(!pq.empty()){
        int distfirst = pq.top().first;
        int prev = pq.top().second;

        pq.pop();

        for(auto it: adj[prev]){
            int nextnode = it.first;
            int nextdist = it.second;
            if(dist[prev] + nextdist < dist[nextnode]){
                dist[nextnode] = dist[prev] + nextdist;
                pq.push({nextdist,nextnode});
            }
        }

    }

    for(auto it: dist){
        cout<<it<<" ";
    }
}


int main(){
    int V = 5;

    vector<pair<int,int>> adj[V+1];

    addEdge(adj,1,2,2);
    addEdge(adj,2,5,5);
    addEdge(adj,1,4,1);
    addEdge(adj,4,3,3);
    addEdge(adj,2,3,4);
    addEdge(adj,3,5,1);
    
    shortestPath(adj,V,1);

    return 0;

}
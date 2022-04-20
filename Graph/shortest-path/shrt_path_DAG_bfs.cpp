#include<iostream>
#include<vector>
#include<stack>
#include<utility>

using namespace std;

void addEdge(vector<pair<int,int>> adj[],int v, int w, int wt){
    adj[v].push_back({w,wt});
}

void topo_sort(vector<pair<int,int>> adj[],vector<bool> &vis,stack<int> &st,int s){
    vis[s] = true;

    for(auto it: adj[s]){
        if(!vis[it.first]){
            topo_sort(adj,vis,st,it.first);
        }
    }
    st.push(s);
}

void shortestPath(vector<pair<int,int>> adj[],int v, int src){
    vector<bool> vis(v+1, false);
    stack<int> st;
    for(int i =0;i<=v;i++){
        if(!vis[i]){
            topo_sort(adj,vis,st,i);
        }
    }

    vector<int> dist(v+1,INT_MAX);

    dist[src] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(dist[node] != INT_MAX){
            for(auto it: adj[node]){
                if(dist[node]+it.second < dist[it.first]){
                    dist[it.first] = dist[node]+it.second;
                }
            }
        }
    }

    for(int i =0;i<=v;i++){
        (dist[i] == INT_MAX)? cout<<"INF " : cout<<dist[i]<<" ";
    }
}

int main(){
    int V = 5;

    vector<pair<int,int>> adj[V+1];

    addEdge(adj,0,1,2);
    addEdge(adj,0,4,1);
    addEdge(adj,1,2,3);
    addEdge(adj,2,3,6);
    addEdge(adj,4,2,2);
    addEdge(adj,4,5,4);
    addEdge(adj,5,3,1);
    
    shortestPath(adj,V,0);




    return 0;

}
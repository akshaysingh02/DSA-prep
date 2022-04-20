#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void addEdge(vector<int> adj[],int v, int w){
    adj[v].push_back(w);
}

void toposortUtil(vector<int> adj[],vector<bool> &vis, stack<int> &st, int s){
    vis[s] = true;

    for(auto it: adj[s]){
        if(!vis[it]){
            toposortUtil(adj,vis,st,it);
        }
    }
    st.push(s);
}

vector<int> toposort(vector<int> adj[],int v){
    stack<int> st;
    vector<bool> vis(v+1, false);

    for(int i =0; i<=v; i++){
        if(!vis[i]){
            toposortUtil(adj,vis,st,i);
        }
    }

    vector<int> topo;

    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

int main(){

    int V = 5;
    vector<int> adj[V+1];
    addEdge(adj,2,3);
    addEdge(adj,3,1);
    addEdge(adj,4,0);
    addEdge(adj,4,1);
    addEdge(adj,5,0);
    addEdge(adj,5,2);

    vector<int> hui;

    hui = toposort(adj,V);

    for(auto it: hui){
        cout<<it<<" ";
    }

    return 0;
}
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void addEdge(vector<int> adj[],int v, int w){
    adj[v].push_back(w);
}

vector<int> toposort(vector<int> adj[],int v){
    queue<int> q;
    vector<int> indegree(v, 0);

    //This is counting the indegree of the all the nodes
    for(int i = 0;i<=v;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    //In this step we will iterate over indegree array and push all the nodes with 0 indegree into the queue
    for(int i = 0;i<=v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> topo;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
        }
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

    vector<int> topo;
    topo = toposort(adj,V);

    cout<<"This is the topological sorting for the graph: ";
    for(auto it: topo){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}
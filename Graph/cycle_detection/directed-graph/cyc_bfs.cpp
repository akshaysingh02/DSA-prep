#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void addEdge(vector<int> adj[],int v, int w){
    adj[v].push_back(w);
}

bool isCyclic(vector<int> adj[],int v){
    queue<int> q;
    vector<int> indegree(v+1, 0);

    for(int i=0; i<=v;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    for(int i = 0; i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int count = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(count == v) return false;
    return true;
}

int main(){

    int V = 5;
    vector<int> adj[V+1];
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    // addEdge(adj,3,1);

    if(isCyclic(adj,V))
        std::cout << "Yes, This graph contains cycle" << std::endl;
    else 
        std::cout << "No cycle detected" << std::endl;




    return 0;
}
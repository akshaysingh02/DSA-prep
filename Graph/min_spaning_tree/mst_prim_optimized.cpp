//This is prim's algo which is optimized using heap data
//structure, i.e using priority queue in c++
//and time is now 'nlogn'

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<pair<int, int>> adj[], int v, int w, int wt)
{
    adj[v].push_back({w, wt});
    adj[w].push_back({v, wt});
}

void MST(vector<pair<int,int>> adj[],int s){
    s++;
    vector<int> key(s,INT_MAX);
    vector<bool> mstSet(s, false);
    int parent[s];


    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    key[0] = 0;
    parent[0] = -1; 
    pq.push({0,0});

    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
	            key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    for(int i = 1; i<s;i++){
        cout<<parent[i]<<" ";
    }
}

int main()
{
    int V = 4;
    vector<pair<int, int>> adj[V+1];

    addEdge(adj, 0, 1, 2);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 4, 7);

    MST(adj, V);

    return 0;
}
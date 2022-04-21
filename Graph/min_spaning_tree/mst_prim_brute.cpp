//This is the brute force approach for the prim's
//algorithm for finding the minimum spanning tree for a given graph
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<pair<int, int>> adj[], int v, int w, int wt)
{
    adj[v].push_back({w, wt});
    adj[w].push_back({v, wt});
}

void dfsUtil(vector<pair<int, int>> adj[], vector<bool> &vis, int s)
{
    vis[s] = true;

    cout << s << " ";

    for (auto it : adj[s])
    {
        if (!vis[it.first])
        {
            dfsUtil(adj, vis, it.first);
        }
    }
    return;
}

void DFS(vector<pair<int, int>> adj[], int V)
{
    vector<bool> vis(V + 1, false);

    for (int i = 0; i <= V; i++)
    {
        if (!vis[i])
        {
            dfsUtil(adj, vis, i);
        }
    }
}

//Time for this function is O(n^2) because we're going through N nodes N-1 times
//so this is brute force approach to get minimum spanning tree
void MST(vector<pair<int, int>> adj[], int s) // s = 4 so we're incrementing s below
{
    s++;
    int parent[s];
    int key[s];
    bool mstSet[s];

    for (int i = 0; i < s; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    key[0] = 0;
    parent[0] = -1;

    //Here we check for the minimum value in the key array and store its index in (u)
    //and we're also running outer loop with count for n-1 times because we're gonna have n-1 edges    
    for (int count = 0; count < s-1; count++)
    {
        int mini = INT_MAX, u;
        for (int i = 0; i < s; i++)
        {
            if (mstSet[i] == false && key[i] < mini)
            {
                mini = key[i];
                u = i;
            }
        }

        mstSet[u] = true;

        for(auto it : adj[u]){
            int v = it.first;
            int weight = it.second;

            if(mstSet[v] == false && weight < key[v]){
                parent[v] = u;
                key[v] = weight;
            }
        }

    }

    for(int i = 1; i<s;i++){
        cout<<parent[i]<<" - "<<i<<endl;
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
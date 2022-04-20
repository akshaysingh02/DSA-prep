//This DFS traversal is using the recursion
//and this is for dissconnected graph only.
//here we're using map 

#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph {
    public:
    map<int, bool>visited;
    map<int, list<int> > adj;

    void addEdge(int v, int w){
        adj[v].push_back(w);
    }

    void dfs(int s){
        visited[s] = true;
        cout<<s<<" ";

        list<int>::iterator i;
        for(i = adj[s].begin();i!=adj[s].end();i++){
            if(!visited[*i]){
                dfs(*i);
            }
        }
    }
};


int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(4,2);
    g.addEdge(3,2);

    g.dfs(0);

}

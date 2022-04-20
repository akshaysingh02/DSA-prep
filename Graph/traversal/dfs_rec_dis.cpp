#include <iostream>
#include <map>
#include <list>

using namespace std;

class Graph {
    void dfsUtil(int v){

        vis[v] = true;
        cout<<v<<" ";

        list<int>::iterator i;

        for(i = adj[v].begin();i!=adj[v].end();i++){
            if(!vis[*i]){
                dfsUtil(*i);
            }
        }
    }
    public:
    map<int, bool> vis;
    map<int, list<int> > adj;

    void addEdge(int v, int w){
        adj[v].push_back(w);
    }

    void dfs(){
        for(auto i: adj){
            if(vis[i.first]==false){
                dfsUtil(i.first);
                cout<<endl; 
            }
        }
    }
};

int main(){

    Graph g;
    g.addEdge(1,2);
    g.addEdge(2,5);
    g.addEdge(2,3);
    g.addEdge(3,7);
    g.addEdge(5,7);
    g.addEdge(4,6);

    g.dfs();


    return 0;
}
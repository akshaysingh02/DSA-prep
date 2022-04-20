//This is bfs from youtube i.e take u forward
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
    int v;
    list<int> *adj;
    public:
    
    Graph(int v){
        this->v = v;
        adj = new list<int>[v];
    }

    void addEdge(int v, int w){
        adj[v].push_back(w);
    }

    void BFS(int s){
        vector<bool> vis(v, false);

        list<int> q;
        q.push_back(s);

        list<int>::iterator i;

        while(!q.empty()){
            s = q.front();
            cout<<s<<" ";
            q.pop_front();

            for(i = adj[s].begin(); i!=adj[s].end();i++){
                if(!vis[*i]){
                    vis[*i] = true;
                    q.push_back(*i);
                }
            }
        }
    }

};

int main(){

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
#include<iostream>
#include<list>
#include<stack>
#include<vector>

using namespace std;

class Graph{
    int v;
    list<int> *adj;
    public:

    Graph(int vertex){
        this->v = vertex;
        adj = new list<int>[v];
    }

    void addEdge(int v, int w){
        adj[v].push_back(w);
    }
    void dfsUtil(int s, vector<bool> &vis){

        stack<int> stack;

        stack.push(s);

        while(!stack.empty()){
            s = stack.top();
            stack.pop();

            if(!vis[s]){
                cout<<s<<" ";
                vis[s]=true;

                for(auto i = adj[s].begin();i!=adj[s].end();i++){
                    if(!vis[*i]){
                        stack.push(*i);
                    }
                }
            }
        }

    }

    void dfs(){
        vector<bool> vis(v,false);

        for(int i = 0; i<v;i++){
            if(!vis[i]){
                dfsUtil(i,vis);
            }
        }
    }
};

int main(){
    Graph g(5);

    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);

    g.dfs();
}
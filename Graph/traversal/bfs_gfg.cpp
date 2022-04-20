//This is bfs from GFG
#include <iostream>
#include <list>
using namespace std;

// This representation is using the adjacency list representation
class Graph
{
    int v;          // no. of vertices.
    list<int> *adj; // pointer to an array containing the ajacency list
public:
    Graph(int v);

    // function to add edge in the graph
    void addEdge(int v, int w);

    // print BFS traversal from a given sources s.
    void BFS(int s);
};

Graph::Graph(int v)
{
     this->v = v;
    adj = new list<int>[v];
}

// This is adding w to v's list, where v is the vertice by adding w to its list we're making a edge from v to w
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    // create a queue for bfs
    list<int> queue;

    // mark the visited node as visited and enque it
    visited[s] = true;
    queue.push_back(s);

    // iterator 'i' is used to get all the adjacent node of a vertex

    list<int>::iterator i;

    while (!queue.empty())
    {

        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
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


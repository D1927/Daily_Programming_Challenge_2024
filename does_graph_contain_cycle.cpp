#include <iostream>
#include <vector>
using namespace std;

class Graph 
{
    int V;  
    vector<vector<int>> adj;  

    bool dfs(int v, int parent, vector<bool>& visited) {
        visited[v] = true;

        for (int u : adj[v]) 
        {
            if (!visited[u]) 
            {
                if (dfs(u, v, visited))
                    return true;
            }
            else if (u != parent) 
                return true;
        }
        return false;
    }

    public:
    Graph(int V) : V(V) 
    {
        adj.resize(V);
    }

    void addEdge(int u, int v) 
    {
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

    bool isCyclic() 
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) 
        {
            if (!visited[i]) 
            {
                if (dfs(i, -1, visited)) 
                    return true;
            }
        }
        return false;
    }
};

int main() 
{
    Graph g(5); 
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);  

    if (g.isCyclic()) 
        cout << "True" << endl;
    else 
        cout << "False" << endl;

    return 0;
}

// Time Complexity :- O(V + E) ----- V = number of vertices , E = number of edges
// Space Complexity :- O(V)

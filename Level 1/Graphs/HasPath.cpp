#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Edge
{

    
public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

bool hasPath(vector<Edge *> graph[], int src, int dest, bool visited[])
{
    if (src == dest)
    {
        return true;
    }
    visited[src] = true;
    for (Edge *edge : graph[src])
    {
        if (visited[edge->nbr] != true)
        {
            bool hasNbrPath = hasPath(graph, edge->nbr, dest, visited);
            if (hasNbrPath == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int vtces, edges;
    cin >> vtces >> edges;
    vector<Edge *> graph[vtces];
    for (int i = 0; i < edges; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(new Edge(v1, v2, wt));
        graph[v2].push_back(new Edge(v2, v1, wt));
    }
    int src, dest;
    cin >> src >> dest;
    bool visited[vtces]; // = {false};
    for (int i = 0; i < vtces; i++)
    {
        visited[i] = false;
    }
    bool path = hasPath(graph, src, dest, visited);
    if (path == true)
    {
        cout << "true"
             << "\n";
    }
    else
    {
        cout << "false"
             << "\n";
    }
}
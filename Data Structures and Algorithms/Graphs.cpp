#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
class Graph
{
    int vertices;
    list<int> *arr;

public:
    Graph(int v)
    {
        vertices = v;
        arr = new list<int>[v];
    }

    void addEdge(int u, int v)
    {
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    void printAdjacency()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << " : ";
            for (int neigh : arr[i])
                cout << neigh << " ";
            cout << endl;
        }
    }

    void bfs()
    {
        queue<int> q;
        vector<bool> visited = {false};
        q.push(0);
        visited[0] = true;

        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();

            cout << u << " ";
            for (int v : arr[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.printAdjacency();
    g.bfs();

    return 0;
}
// DFS TRAVERSALS
// There can be more than one DFS traversals for the same graph.

#include <bits/stdc++.h>
using namespace std;

void dfsstack(int **graph, int n, int sv, bool *visited)
{
    stack<int> s;
    s.push(sv);
    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        if (!visited[cur])
        {
            cout << cur << ' ';
            visited[cur] = true;
        }
        for (int v = 0; v < n; v++)
        {
            if (graph[cur][v] == 1 && !visited[v])
            {
                s.push(v);
            }
        }
    }
}
void dfsrecur(int **graph, int n, int sv, bool *visited)
{
    cout << sv << ' ';
    visited[sv] = true;
    for (int v = 0; v < n; v++)
    {
        if (v == sv)
        {
            continue;
        }
        if (graph[sv][v] == 1)
        {
            if (visited[v])
            {
                continue;
            }

            dfsrecur(graph, n, v, visited);
        }
    }
}

void DFSdisconnected(int **graph, int sv, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int v = 0; v < n; v++)
    {
        if (!visited[v])
        {
            dfsrecur(graph, n, v, visited);
        }
    }
}
// haspath using DFS structure.
// return true if there is a path from start to end
bool haspath(int **graph, int n, int start, int end, bool *visited)
{
    if (start == end)
    {
        return true;
    }
    visited[start] = true;
    for (int v = 0; v < n; v++)
    {
        if (graph[start][v] == 1 && !visited[v])
        {
            haspath(graph, n, v, end, visited);
        }
    }
    return false;
}
// returns vector containing the path vertices from end to start.
vector<int> *getpathdfs(int **graph, int n, int start, int end, bool *visited)
{
    if (start == end)
    {
        vector<int> *ans = new vector<int>();
        ans->push_back(start);
        return ans;
    }
    visited[start] = true;
    for (int v = 0; v < n; v++)
    {
        if (graph[start][v] == 1 && !visited[v])
        {
            vector<int> *smallans = getpathdfs(graph, n, v, end, visited);
            if (smallans != NULL)
            {
                smallans->push_back(start);
                return smallans;
            }
        }
    }
    return NULL;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **graph = new int *[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    dfsstack(graph, n, 0, visited);
    vector<int> *ans = getpathdfs(graph, n, 0, 3, visited);
    for (int i = 0; i < ans->size(); i++)
    {
        cout << ans->at(i) << ' ';
    }
}

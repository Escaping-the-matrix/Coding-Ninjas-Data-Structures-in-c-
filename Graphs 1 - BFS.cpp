// BFS TRAVERSALS
#include <bits/stdc++.h>
using namespace std;
void bfs(int **graph, int n, int sv, bool *visited)
{

    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (v == cur)
            {
                continue;
            }
            if (graph[cur][v] == 1 && !visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
void bfsdisconnected(int **graph, int sv, int n)
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
            bfs(graph, n, v, visited);
        }
    }
}

vector<int> *getpathbfs(int **graph, int n, int start, int end, bool *visited)
{
    queue<int> q;
    q.push(start);
    map<int, int> parent;
    bool done = false;
    visited[start] = true;
    while (!q.empty() && !done)
    {
        int cur = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (graph[start][v] == 1 && !visited[v])
            {
                q.push(v);
                visited[v] = true;
                parent[v] = cur;
                if (v == end)
                {
                    done = true;
                    break;
                }
            }
        }
    }
    if (!done)
    {
        cout << endl;
        return NULL;
    }
    else
    {
        vector<int> *ans = new vector<int>();
        int current = end;
        ans->push_back(current);
        while (current != start)
        {
            /* code */
            current = parent[current];
            ans->push_back(current);
        }
        return ans;
    }
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
    vector<int> *ans = getpathbfs(graph, n, 0, 3, visited);
    for (int i = 0; i < ans->size(); i++)
    {
        cout << ans->at(i) << ' ';
    }
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9; 

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > graph(n + 1); 
    for (int i = 0; i < m; ++i) 
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<int> distance(n + 1, INF); 
    distance[1] = 0; 

    queue<int> q;
    q.push(1);

    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node])
         {
            if (distance[neighbor] == INF) 
            { 
                distance[neighbor] = distance[node] + 1; 
                q.push(neighbor); 
            }
        }
    }

    if (distance[n] == INF)
    {
        cout << -1 << endl; 
    }
    else 
    {
        cout << distance[n] << endl; 
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void dijkstra(int source, const vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d != dist[u])
            continue;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n = 9; 
    vector<vector<pair<int, int>>> graph(n);

    int edges[][3] = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9},
        {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 8, 7}
    };

    int numEdges = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < numEdges; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight}); 
    }

    int source = 0; 
    vector<int> dist;

    dijkstra(source, graph, dist);

    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < n; ++i) {
        cout << i << "\t" << dist[i] << endl;
    }

    return 0;
}


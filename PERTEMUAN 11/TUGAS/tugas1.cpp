#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> iPair;

class Graph {
    int V; 
    vector<vector<iPair>> adj; 
public:
    Graph(int V); 
    void addEdge(int u, int v, int w); 
    void shortestPath(int src); 
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src) {

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    vector<int> dist(V, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }


    cout << "Vertex   Distance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    int V = 6;
    Graph g(V);

    g.addEdge(0, 1, 15);
    g.addEdge(0, 2, 11);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 4, 6);
    g.addEdge(2, 3, 9);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 0, 9);
    g.addEdge(3, 5, 9);
    g.addEdge(4, 5, 5);
    g.addEdge(5, 0, 14);
    
    g.shortestPath(0);

    return 0;
}


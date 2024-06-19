#include <iostream>
#include <vector>
using namespace std;

class UG {
private:
    int V; 
    vector<vector<int>> adjList; 

public:
    UG(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printGraph() {
        cout << "Graf Tak Berarah:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Simpul " << i << ": ";
            for (int j : adjList[i])
                cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }
};

class DG {
private:
    int V; 
    vector<vector<int>> adjList; 

public:
    DG(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void printGraph() {
        cout << "Graf Berarah:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Simpul " << i << ": ";
            for (int j : adjList[i])
                cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }
};

class WG {
private:
    int V; 
    vector<vector<pair<int, int>>> adjList; 

public:
    WG(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    void printGraph() {
        cout << "Graf Berbobot:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Simpul " << i << ": ";
            for (auto &edge : adjList[i])
                cout << "(" << edge.first << ", " << edge.second << ") ";
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    int V = 5;

    UG uG(V);
    uG.addEdge(0, 1);
    uG.addEdge(0, 4);
    uG.addEdge(1, 2);
    uG.addEdge(1, 3);
    uG.addEdge(1, 4);
    uG.addEdge(2, 3);
    uG.addEdge(3, 4);
    uG.printGraph();

    DG dG(V);
    dG.addEdge(0, 1);
    dG.addEdge(0, 4);
    dG.addEdge(1, 2);
    dG.addEdge(1, 3);
    dG.addEdge(1, 4);
    dG.addEdge(2, 3);
    dG.addEdge(3, 4);
    dG.printGraph();

    WG wG(V);
    wG.addEdge(0, 1, 10);
    wG.addEdge(0, 4, 20);
    wG.addEdge(1, 2, 30);
    wG.addEdge(1, 3, 40);
    wG.addEdge(1, 4, 50);
    wG.addEdge(2, 3, 60);
    wG.addEdge(3, 4, 70);
    wG.printGraph();

    return 0;
}

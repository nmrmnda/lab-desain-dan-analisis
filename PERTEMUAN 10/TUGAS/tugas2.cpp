#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Struktur untuk merepresentasikan node dalam linked list
struct Node {
  int data;
  Node* next;
};

// Fungsi untuk membuat node baru
Node* newNode(int data) {
  Node* node = new Node;
  node->data = data;
  node->next = nullptr;
  return node;
}

// Fungsi untuk menambahkan node ke depan linked list
void push(Node** head, int data) {
  Node* new_node = newNode(data);
  new_node->next = *head;
  *head = new_node;
}

// Fungsi untuk mencetak linked list
void printList(Node* node) {
  while (node != nullptr) {
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

// Fungsi untuk menghitung jarak terpendek antara semua pasangan node
// menggunakan algoritma Floyd-Warshall
vector<vector<int>> floydWarshall(vector<vector<int>>& graph) {
  int n = graph.size();
  vector<vector<int>> dist(n, vector<int>(n));

  // Inisialisasi matriks jarak dengan matriks graf awal
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = graph[i][j];
    }
  }

  // Iterasi melalui semua node sebagai node perantara
  for (int k = 0; k < n; k++) {
    // Iterasi melalui semua node sumber
    for (int i = 0; i < n; i++) {
      // Iterasi melalui semua node tujuan
      for (int j = 0; j < n; j++) {
        // Jika jarak dari i ke j melalui k lebih pendek
        // daripada jarak langsung dari i ke j, update jarak
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  return dist;
}

// Fungsi untuk mencetak jalur terpendek dari sumber ke tujuan
// menggunakan linked list
void printShortestPath(vector<vector<int>>& dist, int src, int dest) {
  Node* path = nullptr;
  int n = dist.size();

  // Jika jarak dari sumber ke tujuan adalah infinity, tidak ada jalur
  if (dist[src][dest] == numeric_limits<int>::max()) {
    cout << "Tidak ada jalur\n";
    return;
  }

  // Membangun linked list dari sumber ke tujuan dengan melacak
  // jalur terpendek melalui matriks jarak
  int prev = dest;
  push(&path, dest);
  for (int i = dest; i != src; i = prev) {
    for (int j = 0; j < n; j++) {
      if (dist[src][i] == dist[src][j] + dist[j][i]) {
        prev = j;
        push(&path, j);
        break;
      }
    }
  }

  // Cetak jalur terpendek
  cout << "Jalur Terpendek: ";
  printList(path);

  // Hapus linked list
  while (path != nullptr) {
    Node* temp = path;
    path = path->next;
    delete temp;
  }
}

int main() {
  // Masukkan jumlah kota
  int n;
  cout << "Masukkan Jumlah Kota: ";
  cin >> n;

  // Buat matriks graf berbobot
  vector<vector<int>> graph(n, vector<int>(n));

  // Masukkan elemen matriks graf
  cout << "Nilai Cost Matrix\n";
  for (int i = 0; i < n; i++) {
    cout << "Cost Element Baris ke- " << i + 1 << endl;
    for (int j = 0; j < n; j++) {
      cin >> graph[i][j];
    }
  }

  // Hitung jarak terpendek antara semua pasangan node
  vector<vector<int>> dist = floydWarshall(graph);

  // Cetak cost list
  cout << "Cost List:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }

  // Cetak jalur terpendek dari node 0 ke node n-1
  cout << "Jalur Terpendek: ";
  printShortestPath(dist, 0, n - 1);

  // Cetak minimum cost
  cout << "Minimum Cost: " << dist[0][n - 1] << endl;

  return 0;
}

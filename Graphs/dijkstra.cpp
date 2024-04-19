#include <iostream>
#include <limits.h>
using namespace std;
#define MAX_VERTEX 100  // Maximum number of vertices in the graph

// Structure to represent a node in the graph
struct Node {
  int vertex;
  int distance;
};

// Structure to represent the graph
class Graph {
 private:
  int V; // Number of vertices
  int** adjMatrix; // Adjacency matrix to store edge weights

 public:
  // Constructor to initialize the graph
  Graph(int vertices) {
    V = vertices;
    adjMatrix = new int*[V];
    for (int i = 0; i < V; ++i) {
      adjMatrix[i] = new int[V];
      for (int j = 0; j < V; ++j) {
        adjMatrix[i][j] = INT_MAX; // Initialize all distances as infinite
      }
    }
  }

  // Function to add an edge to the graph
  void addEdge(int src, int dest, int weight) {
    adjMatrix[src][dest] = weight; // Add weight for directed edge
    adjMatrix[dest][src] = weight; // For undirected graph
  }

  // Function to implement Dijkstra's algorithm
  void dijkstra(int start) {
    int* distance = new int[V];  // Array to store distances from source
    bool* processed = new bool[V];  // Array to mark visited vertices

    // Initialize all distances as infinite and processed as false
    for (int i = 0; i < V; ++i) {
      distance[i] = INT_MAX;
      processed[i] = false;
    }

    // Distance to source vertex is 0
    distance[start] = 0;

    // Find shortest paths for all vertices
    for (int count = 0; count < V - 1; ++count) {
      // Pick the minimum distance vertex from the unprocessed set
      int u = minDistance(distance, processed);

      // Mark the picked vertex as processed
      processed[u] = true;

      // Update distances of adjacent vertices
      for (int v = 0; v < V; ++v) {
        // Update distance if there is a neighbor, neighbor is unprocessed
        // and new distance is smaller
        if (!processed[v] && adjMatrix[u][v] != INT_MAX && distance[u] + adjMatrix[u][v] < distance[v]) {
          distance[v] = distance[u] + adjMatrix[u][v];
        }
      }
    }

    // Print calculated distances
    printSolution(distance);

    delete[] distance;
    delete[] processed;
  }

  // Function to find the vertex with minimum distance from the set of unprocessed vertices
  int minDistance(int distance[], bool processed[]) {
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; ++v) {
      if (!processed[v] && distance[v] <= min) {
        min = distance[v];
        min_index = v;
      }
    }
    return min_index;
  }

  // Function to print the shortest distances from source
  void printSolution(int distance[]) {
    cout << "Vertex \t\t Distance from Source" << endl;
    for (int i = 0; i < V; ++i) {
      cout << i << " \t\t " << distance[i] << endl;
    }
  }

  // Destructor to free memory
  ~Graph() {
    for (int i = 0; i < V; ++i) {
      delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
  }
};

int main() {
  int V = 9;
  Graph g(V);

  // Add edges with weights
  g.addEdge(0, 1, 4);
  g.addEdge(0, 7, 8);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 7, 11);
  g.addEdge(2, 8, 2);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 5, 4);
  g.addEdge(3, 4, 9);
  g.addEdge(3, 5, 14);
  g.addEdge(4, 5, 10);
  g.addEdge(5, 6, 2);
  g.addEdge(6, 7, 1);
  g.addEdge(6, 8, 6);
  g.addEdge(7, 8, 7);

  // Perform Dijkstra's algorithm starting from vertex 0
  g.dijkstra(0);

  return 0;
}

#include <iostream>

using namespace std;

// Structure to represent a node in the graph
struct Node {
    int data;
    Node* next;
};

// Structure to represent the graph
class Graph {
private:
    int V;          // Number of vertices
    Node** adjList; // Array of adjacency lists

public:
    // Constructor to initialize the graph
    Graph(int vertices) {
        V = vertices;
        adjList = new Node*[V];
        for (int i = 0; i < V; ++i)
            adjList[i] = nullptr;
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        // Add an edge from src to dest
        Node* newNode = new Node;
        newNode->data = dest;
        newNode->next = adjList[src];
        adjList[src] = newNode;

        // Since graph is undirected, add an edge from dest to src as well
        newNode = new Node;
        newNode->data = src;
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }

    // Function to perform BFS traversal of the graph
    void BFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i)
            visited[i] = false;

        // Create a queue for BFS
        int queue[V], front = 0, rear = 0;

        // Mark the current node as visited and enqueue it
        visited[start] = true;
        queue[rear++] = start;

        while (front != rear) {
            // Dequeue a vertex from queue and print it
            int current = queue[front++];
            cout << current << " ";

            // Get all adjacent vertices of the dequeued vertex current
            // If an adjacent vertex has not been visited, then mark it visited and enqueue it
            for (Node* temp = adjList[current]; temp != nullptr; temp = temp->next) {
                int neighbor = temp->data;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue[rear++] = neighbor;
                }
            }
        }

        delete[] visited;
    }
};

int main() {
    // Create a graph
    Graph graph(6);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2,5);
    // Perform BFS traversal starting from vertex 0
    cout << "BFS Traversal starting from vertex 0: ";
    graph.BFS(0);
    cout << endl;

    return 0;
}

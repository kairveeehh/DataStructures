#include <iostream>
#include <vector>

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

        // Since the graph is undirected, add an edge from dest to src as well
        newNode = new Node;
        newNode->data = src;
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }

    // DFS traversal function
   // DFS traversal function
void DFS(int node, int vis[], vector<int>& result) {
    vis[node] = 1;     // Mark the current node as visited
    result.push_back(node);  // Add the current node to the result list

    // Traverse all the adjacent nodes of the current node
    for (Node* temp = adjList[node]; temp != nullptr; temp = temp->next) {
        int neighbor = temp->data;
        if (!vis[neighbor]) {
            DFS(neighbor, vis, result);  // Recursively call DFS for unvisited neighbors
        }
    }
}


    // Wrapper function for DFS
    vector<int> dfs(int start) {
        vector<int> result;  // Vector to store the DFS traversal result
        int* visited = new int[V];
        for (int i = 0; i < V; ++i)
            visited[i] = 0;  // Initialize all vertices as unvisited

        DFS(start, visited, result);

        delete[] visited;
        return result;
    }
};

int main() {
    // Create a graph
    Graph graph(6);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 4);
    graph.addEdge(2, 0);
    graph.addEdge(2, 5);
    graph.addEdge(1 , 3);

    // Perform DFS traversal starting from vertex 0
    cout << "DFS Traversal starting from vertex 0: ";
    vector<int> dfsResult = graph.dfs(0);
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <limits.h>

#define MAX_VERTEX 100  // Maximum number of vertices in the graph

// Structure to represent a node in the graph
struct Node {
    int vertex;
    int distance;
};

// Structure to represent the min heap
class MinHeap {
private:
    Node* heapArray;
    int capacity;
    int size;

public:
    // Constructor
    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        heapArray = new Node[capacity];
    }

    // Function to heapify a subtree with the root at given index
    void heapify(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < size && heapArray[left].distance < heapArray[smallest].distance)
            smallest = left;

        if (right < size && heapArray[right].distance < heapArray[smallest].distance)
            smallest = right;

        if (smallest != idx) {
            swapNodes(&heapArray[idx], &heapArray[smallest]);
            heapify(smallest);
        }
    }

    // Function to swap two nodes in the heap
    void swapNodes(Node* a, Node* b) {
        Node temp = *a;
        *a = *b;
        *b = temp;
    }

    // Function to extract the minimum node from the heap
    Node extractMin() {
        Node minNode = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        size--;
        heapify(0);
        return minNode;
    }

    // Function to decrease the distance of a vertex in the heap
    void decreaseKey(int vertex, int newDistance) {
        int idx = -1;
        for (int i = 0; i < size; ++i) {
            if (heapArray[i].vertex == vertex) {
                idx = i;
                break;
            }
        }

        if (idx != -1 && newDistance < heapArray[idx].distance) {
            heapArray[idx].distance = newDistance;
            while (idx != 0 && heapArray[(idx - 1) / 2].distance > heapArray[idx].distance) {
                swapNodes(&heapArray[idx], &heapArray[(idx - 1) / 2]);
                idx = (idx - 1) / 2;
            }
        }
    }

    // Function to check if the heap is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to insert a new node into the heap
    void insert(Node newNode) {
        size++;
        int i = size - 1;
        heapArray[i] = newNode;

        while (i != 0 && heapArray[(i - 1) / 2].distance > heapArray[i].distance) {
            swapNodes(&heapArray[i], &heapArray[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
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
                adjMatrix[i][j] = (i == j) ? 0 : INT_MAX; // Initialize all distances as infinite, except for the diagonal (i == j)
            }
        }
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        adjMatrix[src][dest] = weight; // Add weight for directed edge
        // For undirected graph, uncomment the following line
        // adjMatrix[dest][src] = weight;
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

        MinHeap minHeap(V);
        for (int i = 0; i < V; ++i) {
            Node node;
            node.vertex = i;
            node.distance = distance[i];
            minHeap.insert(node);
        }

        while (!minHeap.isEmpty()) {
            Node minNode = minHeap.extractMin();
            int u = minNode.vertex;
            processed[u] = true;

            // Update distances of adjacent vertices
            for (int v = 0; v < V; ++v) {
                // Update distance if there is a neighbor, neighbor is unprocessed
                // and new distance is smaller
                if (!processed[v] && adjMatrix[u][v] != INT_MAX && distance[u] + adjMatrix[u][v] < distance[v]) {
                    distance[v] = distance[u] + adjMatrix[u][v];
                    minHeap.decreaseKey(v, distance[v]); // Update the distance in the min heap
                }
            }
        }

        // Print calculated distances
        printSolution(distance);

        delete[] distance;
        delete[] processed;
    }

    // Function to print the shortest distances from source
    void printSolution(int distance[]) {
        std::cout << "Vertex \t\t Distance from Source" << std::endl;
        for (int i = 0; i < V; ++i) {
            std::cout << i << " \t\t " << distance[i] << std::endl;
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
    int V = 3;
    Graph g(V);

    // Add edges with weights
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 1);
    

    // Perform Dijkstra's algorithm starting from vertex 0
    g.dijkstra(0);

    return 0;
}

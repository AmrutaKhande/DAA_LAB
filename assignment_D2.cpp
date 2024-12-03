#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph {
private:
    int V;                           // Number of vertices
    vector<vector<int>> adjList;     // Adjacency list
    map<char, int> charToIndex;      // Map from char to index
    map<int, char> indexToChar;      // Map from index to char

    // Utility function for DFS to count paths with backtracking
    void countPathsUtil(int u, int d, vector<bool>& visited, int& pathCount) {
        // Mark the current vertex as visited
        visited[u] = true;

        // If the current vertex is the destination, increment the path count
        if (u == d) {
            pathCount++;
        } else {
            // Recur for all neighbors of the current vertex
            for (int v : adjList[u]) {
                if (!visited[v]) {
                    countPathsUtil(v, d, visited, pathCount);
                }
            }
        }

        // Backtrack: Unmark the current vertex to explore other paths
        visited[u] = false;
    }

public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);

        // Map letters to indices and vice versa
        char c = 'A';
        for (int i = 0; i < V; i++, c++) {
            charToIndex[c] = i;
            indexToChar[i] = c;
        }
    }

    void addEdge(char u, char v) {
        adjList[charToIndex[u]].push_back(charToIndex[v]);
    }

    int countPaths(char start, char end) {
        vector<bool> visited(V, false); // To track visited vertices
        int pathCount = 0;             // To store the count of paths
        countPathsUtil(charToIndex[start], charToIndex[end], visited, pathCount);
        return pathCount;
    }
};

int main() {
    int V = 5; // Number of vertices (A, B, C, D, E)
    Graph g(V);

    // Predefined edges
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('B', 'E');
    g.addEdge('C', 'D');
    g.addEdge('C', 'E');
    g.addEdge('D', 'E');

    char start, end;
    cout << "Enter the start vertex (A, B, C, etc.): ";
    cin >> start;
    cout << "Enter the end vertex (A, B, C, etc.): ";
    cin >> end;

    int pathCount = g.countPaths(start, end);
    cout << "Total paths between vertex " << start << " and vertex " << end << " are: " << pathCount << endl;

    return 0;
}


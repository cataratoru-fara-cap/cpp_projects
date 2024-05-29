#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

 vector<vector<int>> readCSVToGraph(const string& filename) {
    ifstream file(filename);
    vector< vector<int>> graph;
    string line, value;

    while (getline(file, line)) {
        vector<int> row;
        stringstream ss(line);
        while (getline(ss, value, ',')) {
            row.push_back( stoi(value));
        }
        graph.push_back(row);
    }

    return graph;
}

void writeGraphToCSV(const vector<vector<int>>& graph, const  string& filename) {
    ofstream file(filename);

    for (const auto &row : graph) {
        for (int i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i != row.size() - 1) {
                file << ',';
            }
        }
        file << '\n';
    }
}

vector<vector<int>> generateAdjacencyMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int totalNodes = n * m + 2; // Adding 2 for the start and sink nodes
    vector<vector<int>> adjacencyMatrix(totalNodes, vector<int>(totalNodes, 0));

    // Connect start and sink nodes to all other nodes
    for (int i = 1; i <= n * m; ++i) { // n*m = 36
        adjacencyMatrix[0][i] = 1; // Start to others
        adjacencyMatrix[i][totalNodes - 1] = 1; // Others to sink
    }

    // Connect each node to its neighbors
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            int nodeIndex = i * n + j  + 1; // +1 to account for the start node
            int x = nodeIndex;              //mindbending indexing...
            int y = nodeIndex;
            
            if (i > 0) adjacencyMatrix[x][y - 6] = 1; // Up
            if (i < n - 1) adjacencyMatrix[x][y + 6] = 1; // Down
            if (j > 0) adjacencyMatrix[x - 1][y] = 1; // Left
            if (j < m - 1) adjacencyMatrix[x + 1][y] = 1; // Right
        }
    }

    return adjacencyMatrix;
}

int main(int argc, char const *argv[])
{
    // Read the input matrix from input.csv
    vector<vector<int>> matrix = readCSVToGraph("input.csv");

    // Generate the adjacency matrix
    vector<vector<int>> adjacencyMatrix = generateAdjacencyMatrix(matrix);

    // Write the adjacency matrix to output.csv
    writeGraphToCSV(adjacencyMatrix, "output.csv");

    return 0;
}

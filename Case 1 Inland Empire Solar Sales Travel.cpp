#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

const int NUM_CITIES = 4;
const int INF = numeric_limits<int>::max();

/* Finds the unvisited city with the smallest distance */
int findMinDistance(int distance[], bool visited[]) {
    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < NUM_CITIES; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

/* Prints the adjacency matrix with clean formatting */
void printAdjacencyMatrix(int graph[NUM_CITIES][NUM_CITIES], string cities[]) {
    cout << "\nAdjacency Matrix (Distances in miles):\n\n";

    cout << setw(15) << "";
    for (int i = 0; i < NUM_CITIES; i++) {
        cout << setw(15) << cities[i];
    }
    cout << endl;

    for (int i = 0; i < NUM_CITIES; i++) {
        cout << setw(15) << cities[i];
        for (int j = 0; j < NUM_CITIES; j++) {
            cout << setw(15) << graph[i][j];
        }
        cout << endl;
    }
}

/* Prints the adjacency list */
void printAdjacencyList(int graph[NUM_CITIES][NUM_CITIES], string cities[]) {
    cout << "\nAdjacency List:\n\n";

    for (int i = 0; i < NUM_CITIES; i++) {
        cout << cities[i] << " -> ";
        for (int j = 0; j < NUM_CITIES; j++) {
            if (graph[i][j] != 0) {
                cout << "(" << cities[j] << ", " << graph[i][j] << " mi) ";
            }
        }
        cout << endl;
    }
}

/* Prints shortest and lowest-cost paths */
void printShortestPaths(int distance[], int previous[], string cities[]) {
    cout << "\nShortest and Lowest-Cost Paths from Riverside:\n\n";

    for (int i = 1; i < NUM_CITIES; i++) {
        cout << "To " << cities[i] << ": Distance = "
             << distance[i] << " miles, Path = ";

        vector<int> path;
        int current = i;

        while (current != -1) {
            path.push_back(current);
            current = previous[current];
        }

        for (int j = path.size() - 1; j >= 0; j--) {
            cout << cities[path[j]];
            if (j != 0) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

int main() {

    /* City names */
    string cities[NUM_CITIES] = {
        "Riverside",
        "Moreno Valley",
        "Perris",
        "Hemet"
    };

    /* Corrected adjacency matrix (matches project graph) */
    int graph[NUM_CITIES][NUM_CITIES] = {
        {0, 16, 24, 33},
        {16, 0, 18, 26},
        {24, 18, 0, 30},
        {33, 26, 30, 0}
    };

    /* Display graph representations */
    printAdjacencyMatrix(graph, cities);
    printAdjacencyList(graph, cities);

    /* Dijkstra's Algorithm */
    int distance[NUM_CITIES];
    bool visited[NUM_CITIES];
    int previous[NUM_CITIES];

    for (int i = 0; i < NUM_CITIES; i++) {
        distance[i] = INF;
        visited[i] = false;
        previous[i] = -1;
    }

    /* Starting city: Riverside */
    distance[0] = 0;

    for (int count = 0; count < NUM_CITIES - 1; count++) {
        int currentCity = findMinDistance(distance, visited);

        if (currentCity == -1) {
            break;
        }

        visited[currentCity] = true;

        for (int neighbor = 0; neighbor < NUM_CITIES; neighbor++) {
            if (!visited[neighbor] &&
                graph[currentCity][neighbor] != 0 &&
                distance[currentCity] != INF &&
                distance[currentCity] + graph[currentCity][neighbor] < distance[neighbor]) {

                distance[neighbor] = distance[currentCity] + graph[currentCity][neighbor];
                previous[neighbor] = currentCity;
            }
        }
    }

    /* Display results */
    printShortestPaths(distance, previous, cities);

    return 0;
}

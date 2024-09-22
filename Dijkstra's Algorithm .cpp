#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Represent infinity

// Function to implement Dijkstra's Algorithm
void dijkstra(int start, int end, const vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INF);  // Distance from start to each node
    vector<int> parent(n, -1); // To track the shortest path
    set<pair<int, int>> pq;    // Priority queue to get the minimum distance node

    dist[start] = 0;
    pq.insert({0, start});

    while (!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());

        if (u == end) break; // Stop if we reach the destination node

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                pq.erase({dist[v], v});
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.insert({dist[v], v});
            }
        }
    }

    // Output the shortest distance and path
    if (dist[end] == INF) {
        cout << "No path exists from node " << start << " to node " << end << endl;
    } else {
        cout << "Shortest path cost: " << dist[end] << endl;
        vector<int> path;
        for (int v = end; v != -1; v = parent[v])
            path.push_back(v);

        cout << "Path: ";
        for (int i = path.size() - 1; i >= 0; --i)
            cout << path[i] << (i ? " -> " : "\n");
    }
}

int main() {
    // Sample graph: vector of adjacency lists
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> graph(n);

    // Add edges (node, weight)
    graph[0].push_back({1, 10});
    graph[0].push_back({3, 30});
    graph[0].push_back({4, 100});
    graph[1].push_back({2, 50});
    graph[2].push_back({4, 10});
    graph[3].push_back({2, 20});
    graph[3].push_back({4, 60});

    int start, end;
    cout << "Enter starting node: ";
    cin >> start;
    cout << "Enter ending node: ";
    cin >> end;

    dijkstra(start, end, graph);

    return 0;
}

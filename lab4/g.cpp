#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> values(N);
    for(int i = 0; i < N; ++i)
        cin >> values[i];

    map<int, int> value_to_index;
    vector<int> index_to_value;
    int idx = 0;
    vector<vector<int>> adj;
    vector<int> left_child, right_child;

    int root_index = -1;

    for(int i = 0; i < N; ++i) {
        int V = values[i];
        if(value_to_index.count(V))
            continue; // Skip duplicates

        value_to_index[V] = idx++;
        index_to_value.push_back(V);
        adj.push_back(vector<int>());
        left_child.push_back(-1);
        right_child.push_back(-1);

        int V_idx = value_to_index[V];
        if(root_index == -1) {
            root_index = V_idx;
            continue;
        }

        int current_idx = root_index;
        while(true) {
            int current_value = index_to_value[current_idx];
            if(V < current_value) {
                if(left_child[current_idx] == -1) {
                    left_child[current_idx] = V_idx;
                    // Add edges to adjacency list
                    adj[current_idx].push_back(V_idx);
                    adj[V_idx].push_back(current_idx);
                    break;
                } else {
                    current_idx = left_child[current_idx];
                }
            } else {
                if(right_child[current_idx] == -1) {
                    right_child[current_idx] = V_idx;
                    // Add edges to adjacency list
                    adj[current_idx].push_back(V_idx);
                    adj[V_idx].push_back(current_idx);
                    break;
                } else {
                    current_idx = right_child[current_idx];
                }
            }
        }
    }

    int num_nodes = idx;

    auto bfs = [&](int start_idx) {
        vector<bool> visited(num_nodes, false);
        vector<int> distance(num_nodes, 0);
        queue<int> q;
        q.push(start_idx);
        visited[start_idx] = true;

        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                    q.push(v);
                }
            }
        }

        int max_dist = 0;
        int farthest_node = start_idx;
        for(int i = 0; i < num_nodes; ++i) {
            if(distance[i] > max_dist) {
                max_dist = distance[i];
                farthest_node = i;
            }
        }
        return make_pair(farthest_node, max_dist);
    };

    // First BFS
    auto res1 = bfs(root_index);
    // Second BFS
    auto res2 = bfs(res1.first);

    // Output the diameter plus one to account for the number of nodes
    cout << res2.second + 1 << endl;

    return 0;
}

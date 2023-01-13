/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

*/

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int> path, int src, int dst) {
    path.push_back(src);
    if(src == dst) {
        result.push_back(path);
        return;
    }

    for(auto node : graph[src])
        dfs(graph, result, path, node, dst);
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> paths; vector<int> path;
    int nodes = graph.size();
    if(nodes == 0) return paths;
    dfs(graph, paths, path, 0, nodes - 1);
    return paths;
}

/// Bellman Ford Algorithm

#include<bits/stdc++.h>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e8);
    dist[src]=0;
    for(int i=1;i<n;i++){
        for(auto edge : edges){
            int u=edge[0], v=edge[1], w=edge[2];
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }
    for(auto edge : edges){
        int u=edge[0], v=edge[1], w=edge[2];
        if(dist[u]!=1e8 and dist[u]+w<dist[v]){
            return {-1};
         }
    }
    return dist;
}

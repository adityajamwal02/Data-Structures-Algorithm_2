/*
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.
*/

#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>& v) {
    pair<int,int> f={v[0][0],v[0][1]};
    pair<int,int> s={v[1][0],v[1][1]};
    if(f.first==s.first) return f.first;
    else if(f.first==s.second) return f.first;
    else if(f.second==s.first) return f.second;
    else return f.second;


}

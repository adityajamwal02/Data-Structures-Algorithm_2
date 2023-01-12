/*
KEYS AND ROOMS
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.
Input Format
In the function an integer vector of vectors is passed.
Output Format
Return true or false.

Constraints:
n == rooms.length
2 <= n <= 1000
0 <= rooms[i].length <= 1000
1 <= sum(rooms[i].length) <= 3000
0 <= rooms[i][j] < n
All the values of rooms[i] are unique.

Sample Input

 [[1],[2],[3],[]]


Sample Output

true
*/

/// DFS Solution

#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> &vis, vector<vector<int>> &rooms){
    vis[i]=1;
    for(int j=0;j<rooms[i].size();j++){
        if(!vis[rooms[i][j]]){
            dfs(rooms[i][j],vis,rooms);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n=rooms.size();
    vector<int> vis(n,0);
    int components=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            components++;
            dfs(i,vis,rooms);
        }
    }
    if(components<=1){
        return true;
    }
    return false;
}


/// BFS Solution

#include<bits/stdc++.h>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,bool> map;
        int n=rooms.size();
        for(int i=0;i<n;i++){
            map[i]=false;
        }
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int k=q.size();
            while(k--){
                int a=q.front();
                q.pop();
                map[a]=true;
                for(int j=0;j<rooms[a].size() && rooms[a].size()!=0;j++){
                    if(map[rooms[a][j]]==false){
                        q.push(rooms[a][j]);
                    }
                }
            }
        }
        for(auto i:map){
            if(i.second==false){
                return false;
            }
        }
        return true;
    }

/// If there is a cycle or not in undirected Graph (BFS technique)

class Solution{
public:
    bool checkCycle(int s,int v,vector<int> adj[],vector<int> &vis){
        queue<pair<int, int> q;
        vis[s]=true;
        q.push({s,-1});

        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();

            for(auto i: adj[node]){
                if(!vis[i]){
                    vis[i]=true;
                    q.push({i,node});
                }else if(par!=i){
                    return true;
                }
            }
        }
    return false;
    }

    bool isCycle(int v, vector<int> adj[]){
        vector<int> vis(v+1,0);
        for(int i=1;i<=v;i++){
            if(!vis[i]){
                if(checkCycle(i,v,adj,vis)) return true;
            }
        }
    return false;
    }
};

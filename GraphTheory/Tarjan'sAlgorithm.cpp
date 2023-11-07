

/// Tarjans Algorithm

class Solution
{
    private:
    int timer=0;
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<int> &tin, vector<int> &low, int &result, int c, int d){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it : adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){
                dfs(it,node,vis,adj,tin,low,result,c,d);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node] and ((it==c and node==d ) or (it==d and node==c))){
                    result=1;
                }
            }else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
	public:
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        int result=0;
        vector<int> vis(V,0), tin(V,0), low(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,-1,vis,adj,tin,low,result,c,d);
            }
        }
    return result;
    }
};


/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

Example 1:
Input:
Output:
3
Explanation:
We can clearly see that there are 3 Strongly
Connected Components in the Graph

Example 2:
Input:
Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).
*/


class Solution
{
	public:

	void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st){
	    vis[node]=1;
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,adj,st);
	        }
	    }
	    st.push(node);
	}

	void dfs2(int node, vector<int> &vis, vector<int> adjT[]){
	    vis[node]=1;
	    for(auto it: adjT[node]){
	        if(!vis[it]){
	            dfs2(it,vis,adjT);
	        }
	    }
	}

    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        vector<int> adjT[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }
        int count=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                count++;
                dfs2(node,vis,adjT);
            }
        }
    return count;
    }
};

/// MST : Kruskal Algorithm

/*
    Idea : Greedy Algorithm: 1) Sort all edges in increasing order of weight (ascending)
                             2) Pick Smallest edge, check for cycle with existing spanning tree, if not form, include edge, else discard
                             3) Repeat it, till (n-1) edges in Spanning tree (n -> no. of nodes)

*/

/// To check for cycle in step 2 : DSU (union find algorithm)

#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent, rank;
public:

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

    int findParent(int node){
        if(node==parent[node]) return node;
    return parent[node]=findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int uPar=findParent(u);
        int vPar=findParent(v);
        if(uPar==vPar) return;
        if(rank[uPar]<rank[vPar]){
            parent[uPar]=vPar;
        }else if(rank[uPar]>rank[vPar]){
            parent[vPar]=uPar;
        }else{
            parent[vPar]=uPar;
            rank[uPar]++;
        }
    }
};

class Graph{

    int n,m;    // n->nodes count, m->edges count
    vector<pair<int,pair<int,int>>> edges;  // {weight,{source,dest}}

public:

    Graph(int n, int m){
        this->n=n;
        this->m=m;
    }

    void addEdge(int u, int v, int w){
        edges.push_back({w,{u,v}});
    }

    int kruskal(){
        int result=0;
        sort(edges.begin(),edges.end());
        DSU ds(n);
        for(auto it : edges){
            int u=it.second.first;
            int v=it.second.second;
            int setU=ds.findParent(u);
            int setV=ds.findParent(v);
            if(setU!=setV){
                cout<<u<<" -> "<<v<<endl;
                result+=(it.first);
                ds.unionByRank(setU,setV);
            }
        }
    return result;
    }
};


int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n,m);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    cout<<endl;
    cout<<"\n Edges of MST \n";
    int result=g.kruskal();
    cout<<"\n Weight of MST "<<result;

    return 0;
}


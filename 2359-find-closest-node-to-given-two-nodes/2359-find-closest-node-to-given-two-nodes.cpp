class Solution {
public:
    vector<vector<int>> adj;
    void dfs(int d, int node, vector<int> &vis, vector<int> &storeDfs) {
        storeDfs[node] = d; 
        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(d+1, it, vis, storeDfs); 
            }
        }
    }
	vector<int>dfsOfGraph(int np, int V){
	    vector<int> storeDfs(V, INT_MAX); 
	    vector<int> vis(V, 0); 
        dfs(0, np, vis, storeDfs); 
	    return storeDfs; 
	}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int V= edges.size();
        adj.resize(V);
        for(int i=0;i<V;i++){
            if(edges[i]!=-1)
                adj[i].push_back(edges[i]);
        } 
        vector<int> d1 = dfsOfGraph(node1, V);
        vector<int> d2 = dfsOfGraph(node2, V);
        int res = -1, mdist = INT_MAX;
        for(int i=0;i<V;i++){
            if (min(d1[i], d2[i]) >= 0 && max(d1[i], d2[i]) < mdist) {
                mdist = max(d1[i], d2[i]);
                res = i;
            }
        }
        return res;
    }
};
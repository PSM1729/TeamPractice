class Solution {
public:
    vector<bool> visited;
    vector<char> color;
    bool dfs(int v, vector<int> graph[]) {
        color[v] = 1;
        for (int u : graph[v]) {
            if (color[u] == 0) {
                if (dfs(u, graph))
                    return true;
            } else if (color[u] == 1) {
                return true;
            }
        }
        color[v] = 2;
        return false;
    }
    bool find_cycle(vector<int> graph[], int n) {
        color.assign(n, 0);

        for (int v = 0; v < n; v++) {
            if (color[v] == 0 && dfs(v, graph))
                return true;
        }
        return false;
    }
    void dfs(int v, vector<int>& ans,vector<int> adj[]) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u])
                dfs(u,ans,adj);
        }
        ans.push_back(v);
    }

    void topo_sort(vector<int> r[], vector<int>& rs, int n) {
        visited.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                dfs(i,rs,r);
        }
        reverse(rs.begin(), rs.end());
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        vector<int> r[k+1], c[k+1];
        for(int i=0;i<rc.size();i++)
            r[rc[i][0]-1].push_back(rc[i][1]-1);
        for(int i=0;i<cc.size();i++)
            c[cc[i][0]-1].push_back(cc[i][1]-1);
        
        vector<int> rs, cs; // storing row and col in topological order
        topo_sort(r,rs,k); topo_sort(c,cs,k);
        
        if(find_cycle(r, k) || find_cycle(c, k)) 
            return vector<vector<int>>();
        
        vector<vector<int>> mat(k,vector<int>(k,0));
        
        unordered_map<int, int> m;
        for(int i=0;i<k;i++) 
            m[cs[i]]=i;
        
        for(int i=0;i<k;i++) 
            mat[i][m[rs[i]]]= rs[i] + 1;
        
        
        return mat;
    }
};
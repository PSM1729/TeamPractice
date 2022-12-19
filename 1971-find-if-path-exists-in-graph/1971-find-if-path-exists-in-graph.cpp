class Solution {
public:
    vector<int> parent ;

int find(int val)
{
    if(parent[val] == val) 
        return val ;
    return 
        parent[val] = find(parent[val]) ;
}

void merge(int x,int y)
{
    int lx = find(x) ;
    int ly = find(y) ;
    
    parent[ly] = lx ;
}



bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    
    parent.resize(n) ;
    
    for(int i=0;i<n;i++)
        parent[i] = i ;
    
    for(auto edge:edges)
        merge(edge[0],edge[1]) ;
    
    return find(parent[start]) == find(parent[end]) ;
    
    
}
};
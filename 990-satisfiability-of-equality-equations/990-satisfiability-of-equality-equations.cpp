class Solution {
public:
    vector<int> par;
    int find(int x){
        if (x != par[x]) 
            par[x] = find(par[x]);
        return par[x];
    }
    bool equationsPossible(vector<string>& eq) {
        for(int i=0;i<26;i++)
            par.push_back(i);
        
        
        for(auto i: eq){
            if(i[1]=='='){
                par[find(i[0]-'a')] = find(i[3]-'a');
            }
        }
        
        for(auto i: eq){
            if(i[1]=='!'){
                if(find(i[0]-'a') == find(i[3]-'a'))
                    return false;
            }
        }
        return true;
    }
};
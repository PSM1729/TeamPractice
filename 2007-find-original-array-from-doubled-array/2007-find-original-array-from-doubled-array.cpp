class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int, int> umap;
        for (auto num : changed) 
            umap[num]++;
        
        sort(changed.begin(), changed.end());
        
        vector<int> res;
        for (auto num : changed) {
            if (umap[num] && umap[num*2]) {
                umap[num]--;
                umap[num*2]--;
                res.push_back(num);
            }
        }
        
        for(auto i:umap)
            if(i.second)
                return {};
        return res;
    }
};
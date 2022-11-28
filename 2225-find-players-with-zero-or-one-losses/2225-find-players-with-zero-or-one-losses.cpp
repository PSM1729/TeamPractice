class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> a,b;
        for(auto i:matches){
            a[i[0]]=1;
            a[i[1]]=1;
            ++b[i[1]];
        }
        vector<int> x,y;
        for(auto i:a){
            if(b.find(i.first)==b.end()) 
                x.push_back(i.first);
            if(b.find(i.first)!=b.end() && b[i.first]==1) 
                y.push_back(i.first);
        }
        return {x,y};
    }
};
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int ans = 0;
        string trg = "123450", cur = "";
        for(auto i: board){
            for(auto j: i){
                cur+=to_string(j);
            }
        }
        queue<pair<string,int>> q;
        q.push({cur,0});
        set<string> gp;
        vector<vector<int>> dir = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        while(!q.empty()){
            auto tp = q.front();
            q.pop();
            
            if(tp.first == trg)
                return tp.second;
            
            ans++;
            int idx = tp.first.find("0");
            for(auto it: dir[idx]){
                string m = tp.first;
                swap(m[idx],m[it]);
                //cout<<m<<"*";
                if(gp.find(m)==gp.end()){
                    gp.insert(m);
                    q.push({m, tp.second+1});
                }
            }
            //cout<<endl;
            
        }
        return -1;
    }
};
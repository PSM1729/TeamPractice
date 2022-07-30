class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> count( 26,0);
        
        for(auto x: words2){
            vector<int> count1(26,0);
            for(auto y: x){
                count1[y-'a']++;
                count[y-'a'] = max(count[y-'a'], count1[y-'a']);
            }
        }
        
        for(auto x : words1){
            bool f=1;
            vector<int> count1(26,0);
            for(auto y: x)
                count1[y-'a']++;
            
            for(int i=0;i<26;i++){
                if(count[i]>count1[i]){
                    f=0;
                    break;
                }
            }
            if(f==1)
                ans.push_back(x);
        }
         return ans;
    }
};
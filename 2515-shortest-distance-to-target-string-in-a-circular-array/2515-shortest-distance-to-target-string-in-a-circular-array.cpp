class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        vector<int> idx;
        int n = words.size();
        for(int i=startIndex;i<words.size();i++){
            if(words[i]==target)
                idx.push_back(i);
        }
        for(int i=startIndex;i>=0;i--){
            if(words[i]==target)
                idx.push_back(i);
        }
        int sans = INT_MAX;
        if(idx.size()==0)
            return -1;
        
        for(int i=0;i<idx.size();i++){
            int lp = abs(idx[i] - startIndex);
            sans = min(sans , min(lp, n - lp));
        }
        return sans;
    }
};
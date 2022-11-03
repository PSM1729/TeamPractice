class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map;
        int ans = 0;
        for(auto i: words){
            string s = i;
            reverse(i.begin(), i.end());
            if(map[i] > 0){
                ans += 4;
                map[i]--;
            }
            else
                map[s]++;
        }
        
        for(auto i:map){        
            if(i.second == 1 && i.first[0] == i.first[1]){  
                ans += 2;   
                break;
            }                
        }
        return ans;
    }
};
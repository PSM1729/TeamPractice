class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i = 1, j = skill.size()-2;
        long long sm = skill[0] + skill[j+1], prod = skill[0] * skill[j+1];
        while(i<j){
            if(skill[i]+skill[j]!=sm)
                return -1;
            else{
                prod += skill[i]*skill[j];
                i++;j--;
            }
        }
        return prod;
    }
};
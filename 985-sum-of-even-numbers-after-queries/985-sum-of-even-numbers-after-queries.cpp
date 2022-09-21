class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
    int e=0;
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0)
            e+=nums[i];
    }
    
     for(int i=0;i<q.size();i++){
         int val=q[i][0];
         int index=q[i][1];
         if(nums[index]%2==0){
             if((nums[index]+val)%2==0)
                    e+=val;   
             else
                 e-=nums[index];
        }
        else{
             if((nums[index]+val)%2==0)
                e+=nums[index]+val;
        }
         
        nums[index]= nums[index]+val;
        ans.push_back(e);
         
     }
    return ans;
    }
};
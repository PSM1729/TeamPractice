class cmp {
public:
	bool operator()(pair<int,string> A, pair<int,string> B) {
		if(A.first!=B.first)
            return A.first<B.first;
        
        return A.second>B.second;
    }
	};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> unmap;
        for(auto i:words)
            unmap[i]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for(auto i:unmap){
            pq.push({i.second,i.first});
        }
        vector<string> ans;
        while(k){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
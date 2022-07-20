class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> alpha (26);
		for (int i = 0; i < S.size (); ++i) alpha[S[i] - 'a'].push_back (i);
		int res = 0;

		for (const auto& word : words) {
			int x = -1;
			bool found = true;

			for (char c : word) {
				auto it = upper_bound (alpha[c - 'a'].begin (), alpha[c - 'a'].end (), x);
				if (it == alpha[c - 'a'].end ()) found = false;
				else x = *it;
			}

			if (found) res++;
		}

		return res;
    }
};

/*int numMatchingSubseq(string& s, vector<string>& words) {
        int ans = 0;
        vector<vector<int>> mappings(26);  
        for(int i = 0; i < size(s); i++) 
            mappings[s[i] - 'a'].push_back(i);
        for(auto& word : words) {
            bool found = true;
            for(int i = 0, prev = -1; found && i < size(word); i++) {
                auto& v = mappings[word[i]-'a'];
                auto it = upper_bound(begin(v), end(v), prev);   
                if(it == end(v)) 
                    found = false;                  
                else 
                    prev = *it;                                 
            }
            ans += found;
        }
        return ans;
    }*/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        vector<int> ans;
        if(M<=2) {
            M = 2;
            if(N>=2) {
                ans.push_back(M);
                M++;
            }
        }
 
        if(M%2==0)
            M++;

        for(int i=M;i<=N;i=i+2) {
            bool flag = 1;
            for(int j=2;j*j<=i;++j) {
                if(i%j==0) {
                    flag = 0;
                    break;
                }
            }
     
            if (flag == 1){
              if(i==1)
                continue;
              else
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends
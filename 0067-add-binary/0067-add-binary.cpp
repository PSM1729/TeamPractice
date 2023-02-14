class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || carry != 0){
            carry += i >= 0 ? a[i] - '0' : 0;
            carry += j >= 0 ? b[j] - '0' : 0;
            sum = char(carry % 2 + '0') + sum;
            carry /= 2;
            i--,j--;
        }
        
        return sum;
    }
};
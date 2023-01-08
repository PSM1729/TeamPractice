class Solution {
public:
    long long dl = 10000, vl = 1e9;
    string categorizeBox(int length, int width, int height, int m) {
        long long l = (long long)1*length, w = (long long)1*width, h = (long long)1*height;
        cout<<l*w*h<<" ";
        if(((l>=dl || w>=dl || h>=dl) ||(l*w*h >= vl)) && (m>=100))
            return "Both";
        else if(((l>=dl || w>=dl || h>=dl) ||(l*w*h >= vl)))
            return "Bulky";
        else if(m>=100)
            return "Heavy";
        
        return "Neither";
    }
};

    
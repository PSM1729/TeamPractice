class Solution {
public:
    int countTime(string time) {
        int res = 0;
        if(time[0]=='?'){
            if(time[1]>='0' and time[1]<='3')
                res+=3;
            else if(time[1]>='4' and time[1]<='9')
                res+=2;
            else if(time[1]=='?'){
                res+=24;
                time[1]='.';
            }
        }
        
        if(time[1]=='?'){
            if(time[0]=='0')
                res+=10;
            else if(time[0]=='1')
                res+=10;
            else if(time[0]=='2')
                res+=4;
        }
        
        if(time[3]=='?'){
            if(res==0) 
                res=1;
            if(time[4]=='?'){
                res*=60;
                time[4]='.';
            }
            else if(time[4]>='0' and time[4]<='9')
                res*=6;  
        }
        
        if(time[4]=='?'){
            if(res==0) 
                res = 1;
            if(time[3]>='0' and time[3]<='5')
                res*=10;
        }
        if(res==0) 
            return 1;
        return res;
    }
};
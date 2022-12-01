class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vw=['a','e','i','o','u','A','E','I','O','U']
        cnt1,cnt2=0,0
        hlf=len(s)//2
        for i in range(0,hlf):
            if s[i] in vw:
                cnt1+=1
                
        for i in range(hlf,len(s)):
            if s[i] in vw:
                cnt2+=1
                
        if cnt1==cnt2:
            return True
        
        return False
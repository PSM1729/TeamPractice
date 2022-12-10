class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> vc;
        string tmp="";
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==' '){
                vc.push_back(tmp);
                tmp="";
            }
            else
                tmp+=sentence[i];
        }
        vc.push_back(tmp);
        if(vc.size()==1)
            return vc[0][0] == vc[0][vc[0].length()-1];
        
        for(int i=1;i<vc.size();i++){
            if(vc[i][0]!=vc[i-1][vc[i-1].length()-1])
                return false;
        }
        if(vc[0][0]!=vc[vc.size()-1][vc[vc.size()-1].length()-1])
            return false;
        return true;
    }
};
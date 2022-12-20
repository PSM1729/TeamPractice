class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size());
        stack<int> s;
        vis[0]=true;
        s.push(0);
        while(!s.empty()){
            int tp=s.top();
            s.pop();
            for(int k=0;k<rooms[tp].size();k++){
                if(vis[rooms[tp][k]]==false){
                    vis[rooms[tp][k]]=true;
                    s.push(rooms[tp][k]);
                }
            }
        }
        for(int i=0;i<vis.size();i++)
            if(vis[i]==false)
                return false;
        
        return true;
    }
};
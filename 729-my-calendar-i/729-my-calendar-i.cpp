class MyCalendar {
public:
    vector<pair<int,int>> ans;
    MyCalendar() {
        ans.clear();
    }
    
    bool book(int start, int end) {
        for(auto i: ans){
            if(i.first<end && i.second>start)
                return false;
        }
        ans.push_back(make_pair(start,end));
        return true;
    }
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
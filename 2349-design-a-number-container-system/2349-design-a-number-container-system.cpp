class NumberContainers {
public:
    map<int,int> mp;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(mp.find(index)==mp.end())
            mp.insert({index, number});
        else
            mp[index]=number;
    }
    
    int find(int number) {
        int idx = INT_MAX;
        for(auto i: mp){
            if(i.second == number)
                return i.first;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
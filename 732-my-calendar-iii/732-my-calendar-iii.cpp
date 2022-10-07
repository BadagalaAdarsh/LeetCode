class MyCalendarThree {

  map<int ,int> mp;
  public:
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int maxcount=0;
        int curr=0;
        for(pair<int,int> x: mp){
            maxcount=max(maxcount,curr+=x.second);
        }
        return maxcount;
        
    }
};

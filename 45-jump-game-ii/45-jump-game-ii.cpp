class Solution {
public:
    int jump(vector<int>& array) {
        
        int n = array.size();

    if (n <= 1){
        return 0;
    }

    pair<int,int> interval{0,0};
    int jumps = 0;

    while(true){
        jumps++;
        int can_reach = -1;

        for(int i = interval.first; i <= interval.second; i++){
            can_reach = max(can_reach, i + array[i]);
        }

        if (can_reach >= n -1){
            return jumps;
        }

        interval = {interval.second+1, can_reach};
    }
        
    }
};
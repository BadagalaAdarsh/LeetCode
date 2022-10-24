class Solution {
public:
    bool compare(vector<int> &selected,string &currString){
        vector<int> selfCheck(26,0);
        for(int i=0;i<currString.size();i++){
            if(selfCheck[currString[i] - 'a'] == 1) return false;
            selfCheck[currString[i] - 'a'] = 1;
        }
        for(int i=0;i<currString.size();i++){
            if(selected[currString[i]-'a'] == 1) return false;
        }
        return true;
    }
    int f(int i,vector<string> &arr,vector<int> &selected,int len){
        if(i == arr.size()){
            return len;
        }
        string currString = arr[i];
        if(compare(selected,currString) == false){
            return f(i+1,arr,selected,len);
        }
        else
        {
            //pick
            for(int j=0;j<currString.size();j++){
                selected[currString[j]-'a'] = 1;
            }
            len += currString.size();
            int op1 = f(i+1,arr,selected,len);
            
            //skip
            for(int j=0;j<currString.size();j++){
                selected[currString[j]-'a'] = 0;
            }
            len -= currString.size();
            int op2 = f(i+1,arr,selected,len);
            
            return max(op1,op2);
        }
    }
    int maxLength(vector<string>& arr) {
        vector<int> selected(26,0);
        return f(0,arr,selected,0);
    }
};

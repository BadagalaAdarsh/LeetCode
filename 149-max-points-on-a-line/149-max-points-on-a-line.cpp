class Solution {
public:
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_map<string,int> m;
            int dup = 1;
            int temp = 0;
            for(int j=i+1;j<n;j++){
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1]){
                    dup++;
                }
                else{
                int dx = points[j][0]-points[i][0];
                int dy = points[j][1]-points[i][1];
                int g = __gcd(dx,dy);
                m[to_string(dx/g)+'_'+to_string(dy/g)]++;
                temp = max(temp,m[to_string(dx/g)+'_'+to_string(dy/g)]);
                }
            }
            ans = max(ans,temp+dup);
        }
        return ans * 1;    
    }
};
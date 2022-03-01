class Solution {
public:
    double average(vector<int>& salary) {
        
        int minSalary = INT_MAX;
        int maxSalary = INT_MIN;
        
        double total = 0;
        
        for(int sal: salary){
            
            total += sal;
            
            maxSalary = max(maxSalary, sal);
            minSalary = min(minSalary, sal);
        }
        
        total -= (maxSalary + minSalary);
        
        int n = salary.size() - 2;
        
        return total/(double)n;
    }
};
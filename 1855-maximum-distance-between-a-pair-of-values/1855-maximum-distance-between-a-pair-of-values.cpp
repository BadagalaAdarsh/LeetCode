class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int res = 0, i = 0, n = A.size(), m = B.size();
        for (int j = 0; j < m; ++j) {
            while (i < n && A[i] > B[j])
                i++;
            if (i == n) break;
            res = max(res, j - i);
        }
        return res;
    }
};
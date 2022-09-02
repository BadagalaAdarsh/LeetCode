class Solution
{ // Runtime: 7 ms, faster than 99.79% of C++ online submissions for Average of Levels in Binary Tree.
  // Memory Usage: 22.8 MB, less than 13.23% of C++ online submissions for Average of Levels in Binary Tree.
public:
    // map with key as level of the tree,
    // map[level] = {sum of the level, number of elements in the level}
    map<int, pair<double, double>> mp;
    void avg(TreeNode *r, int l)
    {
        // If the node is an end point, return the control
        if (r == NULL)
            return;
        // Add the current value to the sum of this level
        mp[l].first += r->val;
        // Increase the number of elements in the current level
        mp[l].second++;
        // Traverse right
        avg(r->left, l + 1);
        // Traverse left
        avg(r->right, l + 1);
    }
    vector<double> averageOfLevels(TreeNode *root)
    {
        // Resultant vector
        vector<double> ans;
        avg(root, 0);
        // Since map takes ordered_pairings, simply iterate of it
        // Staring from level 0, to the last level available in the tree
        for (auto i : mp)
            // i is the iterator pointing to the pair(key , value),
            // where i.first correspond to the key and i.second corresponds to value
            // For every key, we are only interested in the value
            // i.second.first holds the sum of that level, i.second.second holds the number of elements in that level
            ans.push_back(i.second.first / i.second.second);
        return ans;
    }
};

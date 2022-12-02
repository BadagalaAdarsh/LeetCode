class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        int sz = word1.size();

        vector<int> cnt1(26), cnt2(26);
        for(int i = 0;i < sz;i++){
            cnt1[word1[i] - 'a']++;
            cnt2[word2[i] - 'a']++;
        }

        unordered_map<int, int> mp1, mp2;
        for(int i = 0; i < 26; i++){
            if(cnt1[i] and !cnt2[i] or !cnt1[i] and cnt2[i]) return false;
            if(cnt1[i]) mp1[cnt1[i]]++;
            if(cnt2[i]) mp2[cnt2[i]]++;
        }

        //two work
        for(int i = 0;i < 26; i++){
            int freq1 = cnt1[i], freq2 = cnt2[i];
            if(mp1[freq1] != mp2[freq1]) return false;
            if(mp1[freq2] != mp2[freq2]) return false;
        }

        return true;
    }
    
  
};
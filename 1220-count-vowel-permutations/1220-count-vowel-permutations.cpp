static vector<vector<int>> relation={{1,2,4},{0,2},{1,3},{2},{2,3}};  //Relationships(can be followed after) of each vowel with others
class Solution {
public:
    int countVowelPermutation(int n) 
    {
        int MOD=1e9+7;
        vector<long long> vowels(5,1),vowels_copy;      //When N=1 all vowels are used once to for 1 letter strings
        long long result=0;
        while(--n)
        {
            vowels_copy=vowels;
            for(int i=0;i<5;i++)                         //Characters 'a' 'e' 'i' 'o' 'u'.
            {
                vowels[i]=0;
                for(int &r:relation[i])
                    vowels[i]+=vowels_copy[r],vowels[i]%=MOD;  //Add the strings that end with characters that can have 'i' after them.
            }
        }
        for(long long &i:vowels)
            result+=i,result%=MOD;
        return result;
    }
};

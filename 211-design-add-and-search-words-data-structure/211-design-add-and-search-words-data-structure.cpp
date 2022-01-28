class Trie{
    public:
        Trie *children[26];
        bool isWord=false;
        Trie(){
            for(int i=0; i<26; i++)
                children[i] = NULL;
            isWord = false;
        }
};

class WordDictionary {
public:
    
    Trie* root;
    
    WordDictionary() {
        root = new Trie;
    }
    
    void addWord(string word) {
        int n = word.size();
        Trie* curr = root;
        for(auto ch: word)
        {
            if(!curr->children[ch-'a'])
                curr->children[ch-'a'] = new Trie;
            curr = curr->children[ch-'a'];
        }
        curr->isWord = true;
    }
    
    bool mySearch(string word, Trie* root)
    {
        int n = word.size();
        Trie* curr = root;
        for(int i=0; i<n; i++)
        {
            if(word[i] == '.')
            {
                for(auto child: curr->children)
                {
                    if(child && mySearch(word.substr(i+1), child))
                        return true;
                }
                return false;
            }
            else
            {
                if(!curr->children[word[i]-'a'])
                    return false;
                curr = curr->children[word[i]-'a'];
            }
            
        }
        return curr->isWord;
    }
    
    bool search(string word) {
        return mySearch(word, root);
    }
    
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
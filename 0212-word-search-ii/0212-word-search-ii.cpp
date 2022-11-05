struct s {
    int isW;
    s* c[26];
    s() {
        isW = 0;
        for (int i = 0; i < 26; i++) {
            c[i] = nullptr;
        }
    }
};
class Solution {
public:
    int r, c;
    bool vis[14][14];
    vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<string> res = {};
    void insertRes(string curword, s* curn) {
        if (curn->isW == 2) {
            res.push_back(curword);
        }
        string tmp = "";
        for (int i = 0; i < 26; i++) {
            if (curn->c[i] != nullptr) {
                tmp = curword;
                tmp += (char)(i + 'a');
                insertRes(tmp, curn->c[i]);
            }
        }
    }
    bool withinB (int& i, int& j) {
        if (i < 0 || i >= r || j < 0 || j >= c)
            return false;
        return true;
    }
    void insert(string& ss, s* cur) {
        for (char cc : ss) {
            if (cur->c[(cc - 'a')] == nullptr)
                cur->c[(cc - 'a')] = new struct s();
            cur = cur->c[(cc - 'a')];
        }
        cur->isW = 1;
    }
    void opt(vector<vector<char>>& B, s* curn, int i, int j) {
        if (vis[i][j] == true)
            return;
        if (curn->isW == 1) {
            curn->isW = 2;
        }
        vis[i][j] = true;
        int ni, nj;
        int dcidx;
        for (auto dd : d) {
            ni = i + dd.first;
            nj = j + dd.second;
            if (withinB(ni, nj)) {
                dcidx = (int)(B[ni][nj] - 'a');
                if (curn->c[dcidx] != nullptr) {
                    opt(B, curn->c[dcidx], ni, nj);
                }
            }
        }
        vis[i][j] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        s* root = new struct s();
        r = board.size();
        c = board[0].size();
        for (int i = 0; i < 14; i++) {
            for (int j = 0; j < 14; j++) {
                vis[i][j] = false;
            }
        }
        for (string str : words) {
            insert(str, root);
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (root->c[(board[i][j] - 'a')] != nullptr) {
                    opt(board, root->c[(board[i][j] - 'a')], i, j);
                }
            }
        }
        res = {};
        insertRes("", root);
        return res;
    }
};
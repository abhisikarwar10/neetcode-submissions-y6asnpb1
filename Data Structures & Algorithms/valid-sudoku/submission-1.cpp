class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int s = board.size();
        unordered_map<int,unordered_set<char>> r;
        unordered_map<int,unordered_set<char>> c;
        map<pair<int,int>,unordered_set<char>> sq;
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                if (board[i][j] == '.') continue;
                pair<int,int> key = {i/3,j/3};
                if(r.find(i)!=r.end()){
                    if(r[i].count(board[i][j])){
                        return false;
                    }
                }
                r[i].insert(board[i][j]);
                if(c.find(j)!=c.end()){
                    if(c[j].count(board[i][j])){
                        return false;
                    }
                }
                c[j].insert(board[i][j]);
                if(sq.find(key)!=sq.end()){
                    if(sq[key].count(board[i][j])){
                        return false;
                    }
                }
                sq[key].insert(board[i][j]);
            }
        }
        return true;
    }
};

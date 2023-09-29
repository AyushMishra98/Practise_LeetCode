class Solution {
public:
    //DFS+Recursion
    bool findPath(vector<vector<char>>& board, string word,int idx,int i,int j){
        if(idx == word.length())
            return true;
        if(i<0 || j<0 || i>=board.size() ||j>=board[0].size() || board[i][j] !=word[idx] ||board[i][j] == '*')
            return false;
        board[i][j]='*';
        if(findPath(board,word,idx+1,i-1,j)||findPath(board,word,idx+1,i,j-1)||
            findPath(board,word,idx+1,i+1,j)||findPath(board,word,idx+1,i,j+1))
            return true;
        board[i][j]=word[idx];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(board[i][j] == word[0] && findPath(board,word,0,i,j))
                    return true;
        return false;
    }
};
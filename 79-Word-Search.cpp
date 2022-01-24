/*
1) DFS Backtracking
2) Everytime check if current Grid is equal the String at One Index++
3) If not return false
4) When Visit marked as visit by altering the board to ' * '
5) Remember to pop back by modifying back. 

[["A","B","C","E"]
["S","F","C","S"]
["A","D","E","E"]]

word = ABCB
A - > B  - > C -> 
go E come back
go C come back
go back B
* -> * -> B -> 
go F come back
go 

*/



class Solution {
public:
    bool ans = false;
    string temp;
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int x = 0 ; x < board[0].size() ; x++){
                
                if( backtracking(board,i,x,word,0) == true){
                    return true;
                }

            }
        }
        return false;
    }

    
    bool backtracking(vector<vector<char>>& board,int r ,int c ,string& word,int k){
        
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[k]){
            return false;
        }
        
        if(k == word.size() - 1){ // D
            return true;
        }
        
        char cur = board[r][c];
        board[r][c] = '*';
        bool search_next = backtracking(board,r+1,c,word,k+1) 
        || backtracking(board,r,c+1,word,k+1)
        || backtracking(board,r-1,c,word,k+1)
         || backtracking(board,r,c-1,word,k+1);
        
        board[r][c] = cur;
        
        
        return search_next;
        
    }
};

// A B C
//     S
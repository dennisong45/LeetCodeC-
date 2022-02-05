/*
1) DFS 
2) Identified the isolated grid that are not connected
3) If its isolated mark #
4) Traverse thru the grid now, if it is # -> O
5) if its O -> X 
6) Grid # means leaked
*/

class Solution {
public:
    int row_size;
    int col_size;
    void solve(vector<vector<char>>& board) {
        row_size = board.size();
        col_size = board[0].size();
        
        // First and last Column
        for(int i = 0; i < row_size; i++){
           if(board[i][0] == 'O'){
               dfs(board,i,0);
           }
            if(board[i][col_size - 1] == 'O'){
                dfs(board,i,col_size -1);
            }
        }
        
        for(int x = 0 ; x < col_size ;x++){
            if(board[0][x] == 'O'){
                dfs(board,0,x);
            }
            if(board[row_size - 1][x] == 'O' ){
                dfs(board,row_size - 1,x);
            }
        }
        
        for(int i = 0 ; i < row_size; i++){
            for(int x = 0 ; x < col_size; x++){
                if(board[i][x] == 'O'){
                    board[i][x] = 'X';
                }
                if(board[i][x] == '#'){
                    board[i][x] = 'O';
                }

            }
        }
        
    }
    
    void dfs(vector<vector<char>>& board,int r, int c){
        if(r < 0 || r>= row_size || c < 0 || c >= col_size || board[r][c] != 'O'){
            return;
        }
        
        board[r][c] = '#';
        
        dfs(board,r+1,c);
        dfs(board,r-1,c);
        dfs(board,r,c+1);
        dfs(board,r,c-1);
        
        
    }
};
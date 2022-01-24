/*

1. DFS go up and down
2. Visit grid if its eligible
3. modified grid to 2 to mark as visited.
4. When done everything come back Count +1

*/

class Solution {
public:
    
    int sizeR;
    int sizeC;
    int count = 0;
    int numIslands(vector<vector<char>>& grid) {
        sizeR = grid.size();
        sizeC = grid[0].size();
        for(int i = 0 ; i < grid.size();i++){
            for(int x = 0 ; x < grid[0].size(); x++){
                if(grid[i][x] == '1'){

                        dfs(grid,i,x);
                        count++;

                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int r , int c){
        if(r < 0 || r >= sizeR || c < 0 || c >= sizeC){
            return;
        }
        
        if(grid[r][c] == '2' || grid[r][c] == '0'){
            return;
        }
    
        grid[r][c] = '2';
        dfs(grid,r+1,c);
        dfs(grid,r,c+1);
        dfs(grid,r-1,c);
        dfs(grid,r,c-1);
        
    }
};
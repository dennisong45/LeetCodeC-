/*
1. Keep going adding Opening
2. If opening is more than N/2 than add closing
3. if string equal size of N push back
4. Return, 

*/
class Solution {
public:
    vector<string>temp;
    vector<string> generateParenthesis(int n) {
        backtrack("",0,0,n);
        return temp;
    }
    
    void backtrack(string s, int o, int c,int n){

        if(s.size() == n*2){
            temp.push_back(s);
            return;
        }
        
        cout << s;
        
        if(o < n){ 
            backtrack(s+"(",o+1,c,n);
        }
        if(c < o){
            backtrack(s+")",o,c+1,n);
        }
        

        //( ( ( ) ) )  
        // 
    }
};

//


// backtracking
// two varialbes = opening = ((( 

/*

    if open < close/2 and not equal to size of n 
    add Open
    if open > close/2
    add close
    
    closing = 0 
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //x1-x2 + y1+y2
        
        /*
        
        */
        vector<vector<int>>result(k);
        priority_queue<vector<int>> maxHeap;
        int dist = 0;
        for(int i = 0; i < points.size(); i++){
            int x1 =points[i][0];
            int y1 =points[i][1];
            x1 = x1*x1;
            y1 = y1*y1;
            dist = x1+y1;
          //  cout << dist;
            maxHeap.push({dist,points[i][0],points[i][1]}); // [8],[10],[5] k =2
            // 8 5
            //k=2
            // 
            if(maxHeap.size() > k ){
                maxHeap.pop();
            }
        }
        
        for(int i = 0;  i < k ; ++i){
            vector<int>top = maxHeap.top();
            maxHeap.pop();
            cout << top[0];
            cout << top[1];
            result[i] = {top[1],top[2]};
           
        }

          
        
        
        return result;
        
    }
};
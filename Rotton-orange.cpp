class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    //make a ques of pair ans integer 
    // pair conting i , j -->row number and colmn no.
    // and integer is 0 initially
        queue<pair<pair<int,int>,int>>q;
        
        vector<vector<int>>img =grid;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i =0; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                if(img[i][j]==2){
                   q.push({{i,j},0}); 
                    img[i][j]=2;
                }
            }
        }
        int ans =0;
        // apply bfs 
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            ans = max( ans , t);
            q.pop();
            int row[] ={-1,0,1,0};
            int col[] ={0,1,0,-1};
    
            for(int i =0 ; i<4; i++){
                int x , y;
                x = r+ row[i];
                y = c+ col[i];
    
                if( x>=0 && x<n && y>=0 && y<m && img[x][y]==1){
    
                    q.push({{x,y},t+1});
                    img[x][y]=2;
                }
            }
        }
       // check there is no fresh orange  
        for(int i =0 ; i<n ;i++){
            for(int j =0; j<m ; j++){
                if(img[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
        
    }
};
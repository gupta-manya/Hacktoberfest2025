class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m =heightMap[0].size();
        if(m<3 || n<3)return 0;
        vector<vector<bool>>visited(n , vector<bool>(m,false));
        using T = tuple<int, int ,int>;
        priority_queue<T , vector<T> , greater<T>> minheap;
        for(int i =0 ; i<n ; i++){
            for(int j =0 ;j<m ;j++){
                if(i==0 || i==n-1 || j==0 ||j==m-1){
                    minheap.push({heightMap[i][j] , i ,j});
                    visited[i][j]=true;
                }
            }
        }
        int res =0;
        int rows[4]={1,-1, 0 ,0};
        int cols[4]={0,0,-1,1};
        while(!minheap.empty()){
            auto[h,r,c] = minheap.top(); minheap.pop();
            for(int i =0  ; i<4 ; i++){
                int nr= r+rows[i];
                int nc= c+cols[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc]){
                    res+=max(0 , h-heightMap[nr][nc]);
                    minheap.push({max(h,heightMap[nr][nc]) ,nr , nc });
                    visited[nr][nc]=true;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    void markadjacentvis(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<int> rows={0,1,0,-1};
    vector<int> columns={-1,0,1,0};
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        if(i+rows[k]>=0 && i+rows[k]<n && j+columns[k]>=0 && j+columns[k]<m && grid[i+rows[k]][j+columns[k]]=='1' && vis[i+rows[k]][j+columns[k]]==0){
            markadjacentvis(i+rows[k],j+columns[k],vis,grid);
        }
    }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    ans++;
                    markadjacentvis(i,j,vis,grid);
                }
            }
        }
        return ans;
    }
};
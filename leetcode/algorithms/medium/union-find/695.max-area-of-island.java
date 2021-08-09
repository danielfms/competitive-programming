class Solution {
    int MAX = 2500;
    int p[] = new int[MAX];
    int rank[] = new int[MAX];
    int ans = 0;
    
    public int maxAreaOfIsland(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        Arrays.fill(rank, 1);
        
        for(int i = 0; i < n * m; i++){
            p[i] = i;
        }
        
        for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && j > 0 &&  grid[i][j - 1] == 1){
                   unionSet(i * m + j, i * m  + j - 1);
                }
               if(grid[i][j] == 1 && j < m - 1  &&  grid[i][j + 1] == 1){
                   unionSet(i * m + j,  i * m  + j + 1);
                }
               if(grid[i][j] == 1 && i > 0 &&  grid[i - 1][j] == 1){
                   unionSet(i * m + j, (i - 1) * m  + j);
                }
               if(grid[i][j] == 1 && i < n - 1  &&  grid[i + 1][j] == 1){
                   unionSet(i * m + j, (i + 1) * m  + j);
                }
               
               if(grid[i][j] == 1){
                   ans = Math.max(ans, 1);
               }
            }
        }
        
        
        return ans;
    }
    
    int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    
    boolean isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    
    void unionSet(int i, int j){
        if(!isSameSet(i,j)){
            int x = findSet(i);
            int y = findSet(j);
            
            if(rank[x] > rank[y]){
                p[y] = x;
                rank[x]  += rank[y];
                ans = Math.max(rank[x], ans);
            }else{
                p[x] = y;
                rank[y]  += rank[x];
                ans = Math.max(rank[y], ans);
            }
        }
    }
}
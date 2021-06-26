class Solution {
    public int maximumWealth(int[][] accounts) {
        int m = accounts.length;
        int n = accounts[0].length;
        int max = 0, sum = 0;
        
        /* 1. stream 2ms
        for(int i = 0; i < m; i++){
            max = Math.max(max, Arrays.stream(accounts[i]).sum());
        }
        */
        /* 2. stream 3ms
        return Arrays.stream(accounts)
            .map(v -> Arrays.stream(v).sum())
            .mapToInt(v -> v)
            .max()
            .getAsInt();
        */
        
        
        for(int i = 0; i < m; i++){
            sum = 0;
            for (int j = 0; j < n; j++)
                sum += accounts[i][j];
            max = Math.max(max, sum);
        }
        return max;
    }
}
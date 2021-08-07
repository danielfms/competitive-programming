class Solution {
    int MAX = 30;
    int p[] = new int[4*MAX*MAX];
    int rank[] = new int[4*MAX*MAX];
    int length = 0;
    
    public int regionsBySlashes(String[] grid) {
        int n = grid[0].length();
        length = n * n * 4;
        int  node, left, top, bottom, right;
        
        Arrays.fill(rank, 0); 
        for(int i = 0; i < length; i++){
            p[i] = i;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                node = ((i * n) + j) * 4;
                left = j > 0 ? ((i * n) + j - 1)* 4 : -1;
                right = j < n - 1 ? ((i * n) + j + 1) * 4 : -1;
                top = i > 0 ? ((i - 1) * n + j) * 4 : -1;
                bottom = i < n - 1 ? ((i + 1) * n + j) * 4 : -1;
                
                if(grid[i].charAt(j) == ' '){
                    unionSet(node, node + 1);
                    unionSet(node, node + 2);
                    unionSet(node, node + 3);                      
                }
                if(grid[i].charAt(j) == '\\'){
                    unionSet(node, node + 3);
                    unionSet(node + 1, node + 2);
                } 
                if(grid[i].charAt(j) == '/'){
                    unionSet(node, node + 1);
                    unionSet(node + 2, node + 3);
                }
            
                if(top != -1){
                    unionSet(node + 1, top + 3);
                }
                if(left != -1){
                    unionSet(node, left + 2);
                }
                if(right != -1){
                    unionSet(node + 2, right);
                }
                if(bottom != -1){
                    unionSet(node + 3, bottom + 1);
                }

            }
        }
        
        Set<Integer> provinces = new HashSet<>();
        
        for(int i = 0; i < length; i++){
            provinces.add(findSet(p[i]));
        }
        return provinces.size();
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
            }else{
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
}
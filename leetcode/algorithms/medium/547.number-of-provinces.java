class Solution {
    int MAX = 200;
    int p[] = new int[MAX];
    int rank[] = new int[MAX];
    
    public int findCircleNum(int[][] graph) {
        int n = graph.length;
        Arrays.fill(rank, 0);
        
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && graph[i][j] == 1){
                   unionSet(i,j);
                }
            }
        }
        
        Set<Integer> provinces = new HashSet<>();
        
        for(int i = 0; i < n; i++){
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
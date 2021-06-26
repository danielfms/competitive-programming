class Solution {
    public int[] sumZero(int n) {
        int[] arr = new int[n];
        int start = (-1)*(n/2);
        for(int i =0 ; i < n; i++, start++){
            if(start == 0 && n%2 == 0){
                ++start;
            }
            arr[i] = start;
        }
        return arr;
    }
}
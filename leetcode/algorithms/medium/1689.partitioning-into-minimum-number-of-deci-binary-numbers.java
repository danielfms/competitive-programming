class Solution {
    public int minPartitions(String n) {
        Character c, max = '0';
        int len = n.length();
        for(int i = 0; i < len ; i++){
            c = n.charAt(i);
            if(c > max){
                max = c;
            }
        }
        return Integer.parseInt(String.valueOf(max));
    }
}
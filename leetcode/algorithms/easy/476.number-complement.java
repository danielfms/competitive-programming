class Solution {
    public int findComplement(int num) {
        int nbits = (int)(Math.log(num) / Math.log(2)) + 1;
        int i = 0 ;
        while(i < nbits){
            if((num & (1 << i)) == 0){
               num = num | ( 1 << i);
            }else{
                num = num & ~(1 << i);
            }
            i++;
        }
        return num;
    }
}
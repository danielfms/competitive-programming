class Solution {
    public int reverse(int x) {
        int negative = 1;
        if(x < 0){
            negative = -1;
        }
        StringBuilder reversed = new StringBuilder(String.valueOf(Math.abs(x))).reverse();
        try{
            Integer value = negative * Integer.parseInt(reversed.toString());
            return value;
        }catch(NumberFormatException e){
            return 0;
        }
    }
}
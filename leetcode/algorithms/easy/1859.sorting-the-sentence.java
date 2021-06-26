class Solution {
    public String sortSentence(String s) {
        //Stream 3ms
        /*
        TreeMap<Integer, String> map = Stream.of(s.split(" "))
        .collect(Collectors.toMap(i -> i.charAt(i.length() - 1)-'0',
                                  i -> i.substring(0,i.length() - 1),
                                  (x, y) -> x, 
                                  TreeMap::new)
                );
        return String.join(" ", map.values());
        */
        
        //1ms
        String[] split = s.split(" ");
        String[] ordered = new String[split.length];
        int len = 0, index = 0;
        for(int i = 0; i < split.length; i++){
            len = split[i].length();
            index = (split[i].charAt(len - 1) - '0') - 1;
            ordered[index] = split[i].substring(0, len - 1);
        }
        return String.join(" ", ordered);
    }
}
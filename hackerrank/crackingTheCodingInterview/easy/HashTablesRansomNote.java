package dataStructures.easy;
import java.util.*;

public class HashTablesRansomNote  {
    Map<String, Integer> magazineMap;
    Map<String, Integer> noteMap;
    
    public HashTablesRansomNote (String magazine, String note) {
       magazineMap = getMap(magazine);
       noteMap = getMap(note);
    }
    
    public Map<String, Integer> getMap(String s){
    	Map<String, Integer> m = new HashMap<String, Integer>();
    	StringTokenizer st = new StringTokenizer(s);
    	String w;
    	while(st.hasMoreTokens()) {
    		w = st.nextToken();
    		if(m.containsKey(w)) {
    			m.put(w, m.get(w) + 1);
    		}else {
    			m.put(w, 1);
    		}
    	}
    	return m;
    }
    
    public boolean solve() {
        for(Map.Entry<String, Integer> entry: this.noteMap.entrySet()){
        	if(!this.magazineMap.containsKey(entry.getKey())) {
        		return false;
        	}
        	if(this.magazineMap.get(entry.getKey()) < entry.getValue()) {
        		return false;
        	}
        };
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        
        // Eat whitespace to beginning of next line
        scanner.nextLine();
        
        HashTablesRansomNote  s = new HashTablesRansomNote(scanner.nextLine(), scanner.nextLine());
        scanner.close();
        
        boolean answer = s.solve();
        if(answer)
            System.out.println("Yes");
        else System.out.println("No");
      
    }
}

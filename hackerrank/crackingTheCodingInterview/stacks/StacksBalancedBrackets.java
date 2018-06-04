package dataStructures.stacks;
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class StacksBalancedBrackets {

	private static final Scanner scanner = new Scanner(System.in);
	
	private Map<Character, Character> m = new HashMap<>();
	
	public void initMap() {
		m.put('[', ']');
		m.put(']', '[');
		m.put('{', '}');
		m.put('}', '{');
		m.put('(', ')');
		m.put(')', '(');
	}
	
	public boolean solve(String s) {
		Stack<Character> st = new Stack<>(); 
		for(int i = 0; i < s.length(); i++) {
			Character prev = !st.isEmpty() ? st.peek() : 'A',
					c = s.charAt(i);
			if(prev == m.get(c)) {
				st.pop();
			}else {
				st.push(c);
			}
		}
		return st.empty();
	}
	
	public static void main(String[] args) {
		int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
        
        StacksBalancedBrackets sbb = new StacksBalancedBrackets();
        
        sbb.initMap();
        for (int tItr = 0; tItr < t; tItr++) {
            String expression = scanner.nextLine();
            if(sbb.solve(expression)) {
            	System.out.println("YES");
            }else {
            	System.out.println("NO");
            }
        }

        scanner.close();

	}

}

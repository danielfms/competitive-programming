package dataStructures.easy;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class StringsMakingAnagrams {
	public static int numberNeeded(String first, String second) {
		int nf = first.length(), ns = second.length(), index;
		int[] letters = new int[26];
		char c;
		for (int i = 0; i < nf; i++) {
			c = first.charAt(i);
			index = c - 97;
			letters[index] += 1;
		}
		int cont = nf;
		for(int i = 0; i < ns; i++) {
			c = second.charAt(i);
			index = c - 97;
			if(letters[index] > 0) {
				letters[index] -= 1;
				cont -= 1;
			}else {
				cont += 1;
			}
		}
		return cont;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String a = in.next();
		String b = in.next();
		System.out.println(numberNeeded(a, b));
	}
}

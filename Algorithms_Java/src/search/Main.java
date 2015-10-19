//package search;
//
//import java.io.BufferedReader;
//import java.io.File;
//import java.io.FileReader;
//import java.nio.file.Path;
//
//public class Main {
//	public static void main(String[] args) throws Exception {
//		StringBuilder builder = new StringBuilder();
//
//		BufferedReader reader = new BufferedReader(new FileReader("bin/search/kjv.txt"));
//
//		while (true) {
//			String line = reader.readLine();
//
//			if (line == null) {
//				break;
//			}
//
//			builder.append(line + "\r\n");
//		}
//
//		reader.close();
//
//		String content = builder.toString();
//
//		// content = "w 17:9 And here is the mind which hath wisdo ajqwjeioq";
//		String pattern = " of ";
//
//		NaiveSearch search = new NaiveSearch();
//		int index0 = search.bruteForce(content, pattern);
//		
//		KarpRabin karpRabin = new KarpRabin();
//		int index1 = karpRabin.karpRabin(content, pattern);
//
//		KMP kmp = new KMP();
//		int index2 = kmp.knuthMorrisPratt(content, pattern);
//
//		System.out.println("Index0: " + index0);
//		System.out.println("Index1: " + index1);
//		System.out.println("Index2: " + index2);
//
//		if (index0 == -1) {
//			System.out.println("Can't find words");
//		} else {
//			System.out.println(content.substring(index0, index0 + pattern.length()));
//		}
//
//	}
//}
package search;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.nio.file.Path;

public class Main {
	public static void main(String[] args) throws Exception {
		StringBuilder builder = new StringBuilder();

		BufferedReader reader = new BufferedReader(new FileReader("bin/search/kjv.txt"));

		while (true) {
			String line = reader.readLine();

			if (line == null) {
				break;
			}

			builder.append(line + "\r\n");
		}

		reader.close();

		String content = builder.toString();

		// content = "w 17:9 And here is the mind which hath wisdo ajqwjeioq";
		String pattern = "And the city had no need of the sun, neither of the moon, to shine in it: for the glory of God did lighten it, and the Lamb is the light thereof";

		// NaiveSearch search = new NaiveSearch();
		KarpRabin search = new KarpRabin();

		// int index = search.bruteForce(content, "17:9 And here is the mind
		// which hath wisdo");
		int index = search.karpRabin(content, pattern);

		System.out.println("Index: " + index);

		if (index == -1) {
			System.out.println("Can't find words");
		} else {
			System.out.println(content.substring(index, index + pattern.length()));
		}
	}
}

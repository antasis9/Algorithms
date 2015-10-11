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

		NaiveSearch search = new NaiveSearch();

		int index = search.bruteForce(content, "17:9 And here is the mind which hath wisdo");
		
		System.out.println("Index: " + index);

		if (index == -1) {
			System.out.println("Can't find words");
		} else {
			System.out.println(content.substring(index, index + "17:9 And here is the mind which hath wisdo".length()));
		}
	}
}

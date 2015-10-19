package search;

public class NaiveSearch {
	public int bruteForce(String text, String pattern) {
		if (text == null || text.length() == 0 || text.length() < pattern.length()) {
			return -1;
		}

		for (int i = 0; i < text.length() - pattern.length(); i++) {
			int j = 0;

			for (j = 0; j < pattern.length(); j++) {
				if (text.charAt(i + j) != pattern.charAt(j)) {
					break;
				}
			}

			if (j == pattern.length()) {
				return i;
			}
		}

		return -1;
	}
}

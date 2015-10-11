package search;

public class KarpRabin {
	public int karpRabin(String content, String pattern) {
		int length = pattern.length();
		int patternHash = hash(pattern, 0, length - 1);
		int currentIndex = 0;
		int prevHash = 0;

		while (true) {
			int startIndex = currentIndex;
			int endIndex = currentIndex + length - 1;
			int hash = 0;

			if (startIndex + length > content.length()) {
				break;
			}

			if (startIndex == 0) {
				hash = hash(content, startIndex, endIndex);
			} else {
				hash = rehash(content, startIndex, endIndex, prevHash);
			}

			if (patternHash == hash) {
				String subString = content.substring(startIndex, endIndex + 1);

				System.out.println(pattern + " ?= " + subString + "(" + startIndex + ", " + endIndex + ", " + length
						+ ", " + (endIndex - startIndex) + ")");

				if (pattern.equals(subString)) {
					return startIndex;
				}
			}

			prevHash = hash;
			currentIndex++;
		}

		return -1;
	}

	public int hash(String content, int start, int end) {
		int result = 0;
		int length = end - start + 1;

		for (int i = 0; i < length; i++) {
			int character = content.charAt(start + i);

			result += character * (getMagic(length - i - 1));
		}

		return result;
	}

	public int rehash(String content, int start, int end, int hash) {
		return 2 * (hash - content.charAt(start - 1) * getMagic(end - start)) + (content.charAt(end) * 1);
	}

	private int getMagic(int coefficient) {
		if (coefficient == 0) {
			return 1;
		} else {
			return (int) Math.pow(2d, coefficient) % Integer.MAX_VALUE;
		}
	}
}

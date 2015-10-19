package search;

public class KMP {

	public int knuthMorrisPratt(String content, String pattern) {
		int[] borders = preprocess(pattern);
		int sourcePosition = 0;
		int targetPosition = 0;
		int startPosition = 0;

		while (true) {
			char source = content.charAt(sourcePosition);
			char target = pattern.charAt(targetPosition);
			
			//System.out.println("Source: " + source + ", Target: " + target);

			if (source == target) {
				//System.out.println("1 Source Position: " + sourcePosition + ", Target Position: " + targetPosition + "\r\n");

				sourcePosition++;
				targetPosition++;

				if (targetPosition == pattern.length()) {
					return startPosition;
				}
			} else {
				//System.out.println("2 StartPosition: " + startPosition + ", Source Position: " + sourcePosition + ", Target Position: " + targetPosition);

				startPosition = startPosition + targetPosition - borders[targetPosition];
				sourcePosition = startPosition;
				targetPosition = 0;
				
				//System.out.println("2 After StartPosition: " + startPosition + ",  Source Position: " + sourcePosition + ", Target Position: " + targetPosition + "\r\n");
				
				if (sourcePosition > content.length() - pattern.length()) {
					return -1;
				}
			}
		}
	}

	public int[] preprocess(String pattern) {
		int length = pattern.length();
		int[] result = new int[length];

		int step = 0;

		while (true) {
			if (step == 0) {
				result[0] = -1;
			} else if (step == 1) {
				result[1] = 0;
			} else {
				result[step] = findBorder(pattern.substring(0, step));

				System.out.println("Step: " + step + " / Result: " + result[step] + "\r\n");
			}

			step++;

			if (step == length) {
				break;
			}
		}

		return result;
	}

	public int findBorder(String target) {
		int length = target.length();

		if (length == 0) {
			return 0;
		} else if (length == 1) {
			return 0;
		} else {
			int step = 1;
			int result = 0;

			while (true) {
				String prefix = target.substring(0, step);
				String postfix = target.substring(length - step, length);

				//System.out.println("Prefix: " + prefix + ", Postfix: " + postfix);

				if (prefix.equals(postfix)) {
					result = step;
				}

				step += 1;

				if (step == length) {
					break;
				}
			}

			return result;
		}
	}
}

/* Filename: FastScanner.java
 * Source: http://dom8a.ru/java/template/A.java
 */

import java.awt.Point;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class FastScanner {
	BufferedReader br;
	StringTokenizer st;

	FastScanner() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	FastScanner(File f) {
		try {
			br = new BufferedReader(new FileReader(f));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	String nextLine() {
		String ret = null;
		try {
			ret = br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}

		return ret;
	}

	String next() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(next());
	}

	long nextLong() {
		return Long.parseLong(next());
	}

	double nextDouble() {
		return Double.parseDouble(next());
	}

	int[] nextIntArray(int size) {
		int[] array = new int[size];

		for (int i = 0; i < size; i++) {
			array[i] = nextInt();
		}

		return array;
	}

	long[] nextLongArray(int size) {
		long[] array = new long[size];

		for (int i = 0; i < size; i++) {
			array[i] = nextLong();
		}

		return array;
	}

	BigInteger nextBigInteger() {
		return new BigInteger(next());
	}

	Point nextIntPoint() {
		int x = nextInt();
		int y = nextInt();
		return new Point(x, y);
	}

	Point[] nextIntPointArray(int size) {
		Point[] array = new Point[size];

		for (int index = 0; index < size; ++index) {
			array[index] = nextIntPoint();
		}

		return array;
	}

	List<Integer>[] readGraph(int vertexNumber, int edgeNumber,
			boolean undirected) {
		List<Integer>[] graph = new List[vertexNumber];

		for (int index = 0; index < vertexNumber; ++index) {
			graph[index] = new ArrayList<Integer>();
		}

		while (edgeNumber-- > 0) {
			int from = nextInt() - 1;
			int to = nextInt() - 1;

			graph[from].add(to);

			if (undirected)
				graph[to].add(from);
		}

		return graph;
	}
}

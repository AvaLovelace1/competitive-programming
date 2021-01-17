/*
 * Solution to USACO '18 Open B1 - Team Tic Tac Toe by Ava Pun
 * Key concepts: implementation
 */

import java.util.*;
import java.io.*;

public class Main {
    
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(System.out);

    static int nextInt() throws IOException {
        in.nextToken();
        return (int) in.nval;
    }

    static String nextString() throws IOException {
        in.nextToken();
        return in.sval;
    }

    public static void main(String[] args) throws Exception {

        in = new StreamTokenizer(new BufferedReader(new FileReader("tttt.in")));
        out = new PrintWriter(new FileWriter("tttt.out"));

        String[] arr = new String[3];
        for (int i = 0; i < 3; ++i) {
            arr[i] = nextString();
        }

        final int[][][] lines = {
            {{0, 0}, {0, 1}, {0, 2}},
            {{1, 0}, {1, 1}, {1, 2}},
            {{2, 0}, {2, 1}, {2, 2}},
            {{0, 0}, {1, 0}, {2, 0}},
            {{0, 1}, {1, 1}, {2, 1}},
            {{0, 2}, {1, 2}, {2, 2}},
            {{0, 0}, {1, 1}, {2, 2}},
            {{2, 0}, {1, 1}, {0, 2}}};

        boolean[] ans1 = new boolean[26];
        boolean[][] ans2 = new boolean[26][26];
        for (int[][] line : lines) {
            String winners = "";
            for (int[] pos : line) {
                int r = pos[0];
                int c = pos[1];
                char ch = arr[r].charAt(c);
                if (winners.indexOf(ch) == -1) {
                    winners += ch;
                }
            }
            if (winners.length() == 1) {
                ans1[winners.charAt(0) - 'A'] = true;
            } else if (winners.length() == 2) {
                int cow1 = Math.min(winners.charAt(0) - 'A', winners.charAt(1) - 'A');
                int cow2 = Math.max(winners.charAt(0) - 'A', winners.charAt(1) - 'A');
                ans2[cow1][cow2] = true;
            }
        }

        int tot1 = 0;
        int tot2 = 0;
        for (boolean i : ans1) {
            tot1 += i ? 1 : 0;
        }
        for (boolean[] row : ans2) {
            for (boolean i : row) {
                tot2 += i ? 1 : 0;
            }
        }

        out.println(tot1);
        out.println(tot2);

        out.close();

    }
}

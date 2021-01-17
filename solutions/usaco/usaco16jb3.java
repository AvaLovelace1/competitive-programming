/*
 * Solution to USACO '16 January B3 - Mowing the Field by Ava Pun
 * Key concepts: implementation, simulation
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

        in = new StreamTokenizer(new BufferedReader(new FileReader("mowing.in")));
        out = new PrintWriter(new FileWriter("mowing.out"));

        int[][] arr = new int[2001][2001];
        for (int[] row : arr) {
            Arrays.fill(row, -1);
        }

        int x = 1000, y = 1000;
        arr[x][y] = 0;
        
        int N = nextInt();
        int ans = Integer.MAX_VALUE;
        int t = 0;
        for (int i = 0; i < N; ++i) {
            String s = nextString();
            int xDir = 0;
            int yDir = 0;
            if (s.equals("N")) {
                yDir = 1;
            } else if (s.equals("E")) {
                xDir = 1;
            } else if (s.equals("S")) {
                yDir = -1;
            } else {
                xDir = -1;
            }
            int num = nextInt();
            for (int j = 0; j < num; ++j) {
                ++t;
                x += xDir;
                y += yDir;
                if (arr[x][y] != -1) {
                    ans = Math.min(ans, t - arr[x][y]);
                }
                arr[x][y] = t;
            }
        }
        if (ans == Integer.MAX_VALUE) {
            ans = -1;
        }
        out.println(ans);

        out.close();
    }
}

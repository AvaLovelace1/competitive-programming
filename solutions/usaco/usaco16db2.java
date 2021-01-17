/*
 * Solution to USACO '16 December B2 - Block Game by Ava Pun
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

        in = new StreamTokenizer(new BufferedReader(new FileReader("blocks.in")));
        out = new PrintWriter(new FileWriter("blocks.out"));

        int N = nextInt();
        String[] arr1 = new String[N];
        String[] arr2 = new String[N];
        for (int i = 0; i < N; ++i) {
            arr1[i] = nextString();
            arr2[i] = nextString();
        }

        int[] ans = new int[26];
        for (int i = 0; i < N; ++i) {
            int[] cnt1 = new int[26];
            int[] cnt2 = new int[26];
            for (int j = 0; j < arr1[i].length(); ++j) {
                ++cnt1[arr1[i].charAt(j) - 'a'];
            }
            for (int j = 0; j < arr2[i].length(); ++j) {
                ++cnt2[arr2[i].charAt(j) - 'a'];
            }
            for (int j = 0; j < 26; ++j) {
                ans[j] += Math.max(cnt1[j], cnt2[j]);
            }
        }
        for (int i = 0; i < 26; ++i) {
            out.println(ans[i]);
        }

        out.close();

    }
}

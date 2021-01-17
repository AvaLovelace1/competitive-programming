/*
 * Solution to USACO '16 February B2 - Circular Barn by Ava Pun
 * Key concepts: implementation, simulation
 */

import java.util.*;
import java.io.*;

public class Main {
    
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(System.out, true);

    static int nextInt() throws IOException {
        in.nextToken();
        return (int) in.nval;
    }

    public static void main(String[] args) throws Exception {

        in = new StreamTokenizer(new BufferedReader(new FileReader("cbarn.in")));
        out = new PrintWriter(new FileWriter("cbarn.out"));

        int N = nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; ++i) {
            arr[i] = nextInt();
        }

        int dist = 0;
        int tot = 0;
        for (int i = 0; i < N; ++i) {
            dist += i * arr[i];
            tot += arr[i];
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < N; ++i) {
            ans = Math.min(ans, dist);
            dist -= tot - arr[i];
            dist += (N - 1) * arr[i];
        }
        out.println(ans);

        out.close();

    }
}

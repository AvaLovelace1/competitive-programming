/*
 * Solution to USACO '17 February B3 - Why Did the Cow Cross the Road III by Ava Pun
 * Key concepts: implementation, simulation
 */

import java.util.*;
import java.io.*;

class Pair implements Comparable<Pair> {
    public int f, s;
    public Pair(int f0, int s0) {
        f = f0;
        s = s0;
    }

    @Override
    public int compareTo(Pair other) {
        if (Integer.compare(f, other.f) == 0) {
            return Integer.compare(s, other.s);
        } else {
            return Integer.compare(f, other.f);
        }
    }
}

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

        in = new StreamTokenizer(new BufferedReader(new FileReader("cowqueue.in")));
        out = new PrintWriter(new FileWriter("cowqueue.out"));

        int N = nextInt();
        Pair[] arr = new Pair[N];
        for (int i = 0; i < N; ++i) {
            int t = nextInt();
            int k = nextInt();
            arr[i] = new Pair(t, k);
        }
        Arrays.sort(arr);

        int ans = 1;
        for (Pair p : arr) {
            ans = Math.max(ans, p.f);
            ans += p.s;
        }
        out.println(ans);

        out.close();

    }
}

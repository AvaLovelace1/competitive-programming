/*
 * Solution to USACO '16 December B1 - Square Pasture by Ava Pun
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

        in = new StreamTokenizer(new BufferedReader(new FileReader("square.in")));
        out = new PrintWriter(new FileWriter("square.out"));

        int minX = 100, maxX = 0;
        int minY = 100, maxY = 0;
        for (int i = 0; i < 4; ++i) {
            int x = nextInt();
            int y = nextInt();
            minX = Math.min(minX, x);
            minY = Math.min(minY, y);
            maxX = Math.max(maxX, x);
            maxY = Math.max(maxY, y);
        }
        int len = Math.max(maxX - minX, maxY - minY);
        out.println(len * len);

        out.close();
    }
}

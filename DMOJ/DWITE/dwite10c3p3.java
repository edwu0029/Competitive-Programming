/*
Dominos Tiling
DWITE Online Computer Programming Contest, December 2010, Problem 3
https://dmoj.ca/problem/dwite10c3p3
*/

import java.io.*;
import java.util.*;

public class dwite10c3p3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        long[]f = new long[31], h = new long[31];
        h[1]=1; f[2]=3;
        for(int i = 3;i<=30;i++){
            f[i]=f[i-2]+2*h[i-1];
            h[i]=h[i-2]+f[i-1];
        }
        for(int i = 0;i<5;i++){
            int N = readInt();
            System.out.println(f[N]%1000000);
        }
    }
    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
}
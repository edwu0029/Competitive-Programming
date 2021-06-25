//Problem: https://dmoj.ca/problem/coci13c1p2

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class coci13c1p2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = readInt(), M = readInt();
        System.out.println(M-gcd(N,M));
    }
    static int gcd(int n , int m){
        if(n==0) return m;
        return gcd(m%n, n);
    }
    static String next() throws IOException{
        while(st==null||!st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt() throws IOException{
        return Integer.parseInt(next());
    }
    static long readLong() throws IOException{
        return Long.parseLong(next());
    }
    static double readDouble() throws NumberFormatException, IOException{
        return Double.parseDouble(next());
    }
}
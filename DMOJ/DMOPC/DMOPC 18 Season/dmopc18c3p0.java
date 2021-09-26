/*
Bob and ICS Class
DMOPC '18 Contest 3 P0
https://dmoj.ca/problem/dmopc18c3p0
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class dmopc18c3p0 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int R1 = (int) Math.sqrt(readInt()); int G1 = (int) Math.sqrt(readInt()); int B1 = (int) Math.sqrt(readInt());
        String s = R1+","+G1+","+B1;
        int R2 = (int) Math.sqrt(readInt()); int G2 = (int) Math.sqrt(readInt()); int B2 = (int) Math.sqrt(readInt());
        String s2 = R2+","+G2+","+B2;
        if(s.equals(s2)){
            System.out.println("Dull");
        }else{
            System.out.println("Colourful");
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
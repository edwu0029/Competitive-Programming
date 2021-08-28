//Problem: https://dmoj.ca/problem/coci06c3p2

import java.util.*;
import java.io.*;

public class coci06c3p2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        char[][]ref = new char[][]{
            {'A','B','C','D'},
            {'E','F','G','H'},
            {'I','J','K','L'},
            {'M','N','O','.'}
            };
        char[][]F = new char[4][4];
        int cnt = 0;
        for(int i = 0;i<4;i++){String s = next();for(int d =0;d<4;d++)F[i][d]=s.charAt(d);}
        for(int i = 0;i<4;i++){
            for(int j = 0;j<4;j++){
                if(F[i][j]!=ref[i][j]&&F[i][j]!='.'){
                    int t = F[i][j]-'A';
                    int r = t/4; int c = t%4;
                    cnt+=(Math.abs(r-i)+Math.abs(c-j));
                }
            }
        }
        System.out.println(cnt);
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
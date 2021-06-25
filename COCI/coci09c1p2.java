//Problem: https://dmoj.ca/problem/coci09c1p2

import java.util.*;
import java.io.*;

public class coci09c1p2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        int N = readInt();
        int total = 0; int temp = 0;
        for(int i = 0;i<=N;i++){
            for(int d=0;d<=N;d++){
                if(i!=d){
                    temp = temp+i+d;
                }
                total = total+i+d;
            }
        }
        System.out.println(total-(temp/2));
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
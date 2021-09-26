/*
Note
COCI '09 Contest 1 #1
https://dmoj.ca/problem/coci09c1p1
*/

import java.util.*;
import java.io.*;

public class coci09c1p1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        int[]A= {1,2,3,4,5,6,7,8};
        int[]B= {8,7,6,5,4,3,2,1};
        int[]C = new int[8];
        for(int i = 0;i<8;i++){
            C[i]=readInt();
        }
        boolean flag = true;
        for(int i = 0;i<8;i++){
            if(A[i]!=C[i])
                flag = false;
        }
        if(flag){
            System.out.println("ascending");
            return;
        }
        flag = true;
        for(int i = 0;i<8;i++){
            if(B[i]!=C[i])
                flag = false;
        }
        if(flag){
            System.out.println("descending");
            return;
        }
        System.out.println("mixed");
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
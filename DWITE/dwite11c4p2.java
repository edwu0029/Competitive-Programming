//Problem: https://dmoj.ca/problem/dwite11c4p2

import java.util.*;
import java.io.*;

public class dwite11c4p2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static int[]primefactors = new int[100000];
    public static void main(String args[]) throws IOException{
        for(int i = 0;i<5;i++){
            int n = readInt();
            for(int d = 2;d<=n;d++){
                    primefactor(d);
            }
            boolean flag = true;
            for(int d=0;d<100000;d++){
                if(primefactors[d]!=0&&flag){
                    System.out.print(d+"^"+primefactors[d]);
                    flag = false;
                }else if(primefactors[d]!=0){
                    System.out.print(" * "+d+"^"+primefactors[d]);
                }
            }
            primefactors = new int[100000];
            System.out.println("");
        }
    }
    public static void primefactor(int n){
        for(int i = 2;i<=n;i++){
            while(true){
                if(n%i==0){
                    n = n/i;
                    primefactors[i]++;
                }else{
                    break;
                }
            }
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
/*
Troyangles
Canadian Computing Olympiad: 2014 Day 1, Problem 1
https://dmoj.ca/problem/cco14p1
*/

import java.util.*;
import java.io.*;

public class cco14p1{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[]args) throws IOException{
        int N = readInt(); String s="";
        char[][]F = new char[N][N];
        for(int i = 0;i<N;i++){
            s = read();
            for(int d = 0;d<N;d++){ 
                F[i][d]=s.charAt(d);
            }
        }
        int[][]dp = new int[N][N];
        for(int i = N-1;i>=0;i--){
            for(int d=0;d<N;d++){
                if(F[i][d]=='#'){
                    dp[i][d] = 1;
                    if(i+1<N&&d-1>=0&&d+1<N) dp[i][d]+=Math.min(dp[i+1][d-1], Math.min(dp[i+1][d], dp[i+1][d+1]));
                }else{
                    dp[i][d]=0;
                }
            }
        }
        int cnt = 0;
        for(int i = 0;i<N;i++){
            for(int d = 0;d<N;d++){
                cnt+=dp[i][d];
            }
        }
        System.out.println(cnt);
    }
    static String read() throws IOException{
        while(st==null||!st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt() throws IOException{
        return Integer.parseInt(read());
    }
    static long readLong() throws IOException{
        return Long.parseLong(read());
    }
    static double readDouble() throws IOException{
        return Double.parseDouble(read());
    }
}
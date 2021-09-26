/*
Balancing Act
DWITE Online Computer Programming Contest, February 2011, Problem 3
https://dmoj.ca/problem/dwite10c5p3
*/

import java.util.*;
import java.io.*;

public class dwite10c5p3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        for(int q = 0;q<5;q++){
            int N = readInt(), sum = 0;
            int[]F = new int[N]; for(int i = 0;i<N;i++){F[i]=readInt();sum+=(F[i]);}
            int half = sum/2;
            int[]dp = new int[half+1]; dp[0]=1;
            for(int i = 0;i<N;i++){
                for(int j = half;j>=F[i];j--){
                    if(dp[j]==0) dp[j]=dp[j-F[i]];
                }
            }
            for(int i = half;i>=0;i--){
                if(dp[i]!=0){ System.out.println(sum-i-i); break;}
            }
        }
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
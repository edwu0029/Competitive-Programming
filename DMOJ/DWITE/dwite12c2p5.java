/*
Car Hoppers
DWITE Online Computer Programming Contest, November 2012, Problem 5
https://dmoj.ca/problem/dwite12c2p5
*/

import java.io.*;
import java.util.*;

public class dwite12c2p5 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        for(int b = 0;b<5;b++){
            int N = readInt(), M = readInt();
            int[]height = new int[N], dp = new int[N];
            for(int i = 0;i<N;i++)height[i] = readInt();
            for(int i = 0;i<N;i++){
                int min = Integer.MAX_VALUE;
                temp:
                for(int j = 1;j<=M*2+1&&i-j>0;j++){
                    for(int k = 1;k<j;k++){
                        if(!see(height, i-j, i-k) && !see(height, i, i-k)) continue temp;
                    }
                    min = Math.min(dp[i-j], min);
                }
                if (i<=M&&see(height, i, 0))
                    min = 0;
                dp[i] = min + 1;
            }
            int min = dp[N-1];
            for (int j = 1;j<=M&&N-1-j>=0;j++) {
                if (see(height, N-1-j, N-1))
                    min = Math.min(dp[N-1-j],min);
            }
            System.out.println(min);
        }
    }
    static boolean see(int[]heights, int g, int c){
        if(g-c>0){
            for(int i = g-1;i>c;i--){
                if(heights[g]<heights[i])return false;
            }
        }else{
            for(int i = g+1;i<c;i++){
                if(heights[g]<heights[i])return false;
            }
        }
        return true;
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
    static double readDouble() throws IOException{
        return Double.parseDouble(next());
    }
}
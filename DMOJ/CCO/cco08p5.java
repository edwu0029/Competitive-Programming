//Problem: https://dmoj.ca/problem/cco08p5

import java.util.*;
import java.io.*;

public class cco08p5 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        int N = readInt(); int[]q = new int[N], v = new int[N];
        int total = 0;
        for(int i = 0;i<N;i++){
            q[i]=readInt(); v[i]=readInt();
            total+=(q[i]*v[i]);
        }
        int half = total/2;
        int[]dp = new int[half+1];
        dp[0]=1;
        for(int i = 0;i<N;i++){
            int[]cnt = new int[half+1];
            for(int j = v[i];j<=half;j++){
                if(dp[j-v[i]]==1&&cnt[j-v[i]]<q[i]&&dp[j]!=1){
                    dp[j]=1; cnt[j]=cnt[j-v[i]]+1;
                }
            }
        }
        for(int i = half;i>=0;i--){
            if(dp[i]==1){
                System.out.println(Math.abs(total-(2*i)));
                return;
            }
        }
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
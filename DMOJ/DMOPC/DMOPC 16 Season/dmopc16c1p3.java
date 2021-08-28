//Problem: https://dmoj.ca/problem/dmopc16c1p3

import java.io.*;
import java.util.*;

public class dmopc16c1p3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = readInt();
        int[]F = new int[N+1];
        double[]dp = new double[N+1];
        for(int i = 1;i<=N;i++) F[i] = readInt(); 
        if(N==0){
            System.out.println(0+".0");
            return;
        }
        if(N==1){
            System.out.println(F[1]+".0");
            return;
        }
        dp[1]=F[1];
        dp[2] = calc(F,2,2);    
        for(int i = 3;i<=N;i++){
            dp[i]=Math.min(dp[i-3]+calc(F,i,1), Math.min(dp[i-2]+calc(F,i,2),dp[i-1]+F[i]));
        }
        String s = Double.toString(dp[N]);
        if(s.indexOf('.')==-1){
            System.out.println(s+".0");
            return;
        }
        System.out.printf("%.1f",dp[N]);
    }
    static double calc(int[]F, int index, int key){
        if(key==1){
            double sum = F[index]+F[index-1]+F[index-2];
            return sum-Math.min(F[index], Math.min(F[index-1], F[index-2]));
        }else{
            double sum = F[index]+F[index-1];
            return ((double)Math.min(F[index-1], F[index])/2)+sum-Math.min(F[index], F[index-1]);
        }
        
    }
    static String find_binary(int N,String s){
        if(N==0||N==1) return s+N+"";
        int tmp = N%2;
        return find_binary((N-tmp)/2,s+tmp+"");
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
}
//Problem: https://dmoj.ca/problem/dmopc17c5p3

import java.util.*;
import java.io.*;

public class dmopc17c5p3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int maxF = 0;
    static long gcf;
    public static void main(String args[]) throws IOException{
        int N = readInt(); long[]F = new long[N];
        gcf = readLong();
        for(int i = 1;i<N;i++){
            gcf = gcd(gcf,readLong());
        }
        if(gcf==1){System.out.println("DNE");return;}
        for(int i=2;i<Math.sqrt(gcf)+2;i++){
            if(gcf%i==0){
                maxF = Math.max(maxF,i);
                while(gcf%i==0)gcf/=i;
            }
        }
        if(maxF==0)System.out.println(gcf);
        else System.out.println(maxF);
    }
    static long gcd(long m, long n){
        if(m==0){
            return n;
        }else return gcd(n%m,m);
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
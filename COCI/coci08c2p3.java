//Problem: https://dmoj.ca/problem/coci08c2p3

import java.util.*;
import java.io.*;

public class coci08c2p3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static long sumT = 0, productT = 1, best = Long.MAX_VALUE;
    static int N;
    static int[]s, b;
    public static void main(String[] args) throws IOException {
        N = readInt(); best = Long.MAX_VALUE;
        s = new int[N]; b = new int[N];
        for(int i = 0;i<N;i++){
            s[i]=readInt(); b[i] = readInt();
            productT*=s[i]; sumT+=b[i];
        }
        for(int i = 0;i<N;i++){
            check(i,0,0,productT,sumT);
        }
        System.out.println(best);
    }
    static void check(int len, int curI, int curL, long productC, long sumC){
        if(len==curL){best = Math.min(best, Math.abs(productC-sumC)); return;}
        for(int i = curI;i<N;i++){
            check(len,i+1,curL+1,productC/s[i],sumC-b[i]);
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
}
//Problem: https://dmoj.ca/problem/dmopc14c2p5

import java.util.*;
import java.io.*;

public class dmopc14c2p5 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = readInt(), M = readInt();
        int[]in = new int[N+1], out = new int[N+1];
        double[]prob = new double[N+1];
        ArrayList<Integer>[]F = new ArrayList[N+1];
        for(int i = 0;i<=N;i++){
            F[i] = new ArrayList<Integer>();
        }
        for(int i = 0;i<M;i++){
            int temp = readInt(), temp2 = readInt();
            in[temp]++; out[temp2]++;
            F[temp].add(temp2);
        }
        prob[1]=1;
        for(int i = 1;i<=N;i++){
            for(int j = 0;j<F[i].size();j++){
                prob[F[i].get(j)]+=(prob[i]/in[i]);
            }
        }
        for(int i = 1;i<=N;i++){
            if(in[i]==0)System.out.println(prob[i]);
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
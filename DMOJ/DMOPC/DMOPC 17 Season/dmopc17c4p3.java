//Problem: https://dmoj.ca/problem/dmopc17c4p3

import java.io.*;
import java.util.*;

public class dmopc17c4p3{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static class Edge{
        int endV; int weight;
        public Edge(int endV, int weight){
            this.endV = endV;
            this.weight = weight;
        }
    }
    static int N, index = 0;
    static long max = -1;
    static long[]dis, dA, dB;
    static ArrayList<Edge>[]F;
    public static void main(String args[]) throws IOException{
        N = readInt(); dA = new long[N]; dB = new long[N];
        F = new ArrayList[N];
        for(int i = 0;i<N;i++)
            F[i] = new ArrayList<Edge>();
        for(int i = 0;i<N-1;i++){
            int tempSt = readInt()-1;
            int tempEnd = readInt()-1;
            int tempWeight = readInt();
            F[tempSt].add(new Edge(tempEnd,tempWeight));
            F[tempEnd].add(new Edge(tempSt, tempWeight));
        }
        dis = dA; max = -1;
        alg(0,-1);
        int a = index; max = -1; dis[a]=0;
        alg(a,-1);
        int b = index; dis = dB;
        alg(b,-1);
        long ans = 0;
        for(int i = 0;i<N;i++){
            if(i==a||i==b){
                continue;
            }
            ans = Math.max(ans, dA[i]);
            ans = Math.max(ans, dB[i]);
        }
        System.out.println(ans);
    }
    public static void alg(int start, int pre){
        if(dis[start]>max){
            max = dis[start]; index = start;
        }
        for(Edge cur: F[start]){
            if(cur.endV!=pre){
                dis[cur.endV] = dis[start]+cur.weight;
                alg(cur.endV,start);
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
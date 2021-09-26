/*
Thanksgiving Feast
DMOPC '18 Contest 2 P3
https://dmoj.ca/problem/dmopc18c2p3
*/

import java.io.*;
import java.util.*;
 
public class dmopc18c2p3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        int N = readInt(), M = readInt(), K = readInt(), A = readInt(), B = readInt();
        int[]giftB = new int[N+1], disTg = new int[N+1], dis = new int[N+1]; 
        for(int i = 0;i<K;i++)giftB[readInt()]++;
        ArrayList<Integer>[]adj =new ArrayList[N+1];
        for(int i = 0;i<=N;i++)adj[i]=new ArrayList<Integer>();
        for(int i = 0;i<M;i++){
            int a = readInt(), b = readInt();
            adj[a].add(b); adj[b].add(a);
        }
        LinkedList<Integer>l = new LinkedList<Integer>();
        Arrays.fill(disTg, Integer.MAX_VALUE); disTg[A]=0; l.add(A);
        int cur = 0, v = 0;
        while(!l.isEmpty()){
            cur = l.poll();
            for(int i = 0;i<adj[cur].size();i++){
                v = adj[cur].get(i);
                if(disTg[v]>disTg[cur]+1){
                    l.add(v); disTg[v]=disTg[cur]+1;
                }
            }
        }
        Arrays.fill(dis, Integer.MAX_VALUE); dis[B]=0; l.add(B);
        while(!l.isEmpty()){
            cur = l.poll();
            for(int i = 0;i<adj[cur].size();i++){
                v = adj[cur].get(i);
                if(dis[v]>dis[cur]+1){
                    l.add(v); dis[v]=dis[cur]+1;
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for(int i = 1;i<=N;i++){
            if(giftB[i]>0)
            ans = Math.min(ans, disTg[i]+dis[i]);
        }
        System.out.println(ans);
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
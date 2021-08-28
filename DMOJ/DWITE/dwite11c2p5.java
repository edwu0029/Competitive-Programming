//Problem: https://dmoj.ca/problem/dwite11c2p5

import java.util.*;
import java.io.*;

public class dwite11c2p5 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int[]parent;
    static int[]rank;
    public static void main(String args[]) throws IOException{
        for(int pq = 0;pq<5;pq++){
            int N = readInt(), temp = 0, k1 = 0, k2 = 0;
            parent = new int[2*N]; for(int i = 0;i<2*N;i++){parent[i]=i;}
            rank = new int[2*N]; 
            Hashtable<String, Integer>h = new Hashtable<String,Integer>();
            for(int i = 0;i<N;i++){
                char a = next().charAt(0);
                String s = next(), s2 = next();
                if(!h.containsKey(s)){h.put(s, temp); temp++;}
                if(!h.containsKey(s2)){h.put(s2, temp); temp++;}
                k1 = find(h.get(s)); k2 = find(h.get(s2));
                if(a=='p') Union(k1,k2);
                if(a=='q'){
                    if(k1==k2){
                        System.out.println("connected");
                    }else{
                        System.out.println("not connected");
                    }
                }
            }
        }
    }
    static void Union(int a, int b){
        if(rank[a]>rank[b]){
            parent[a]=b;
        }else{
            parent[b]=a;
            if(rank[a]==rank[b]){
                rank[b]++;
            }
        }
    }
    static int find(int u){
        if(parent[u]==u){
            return u;
        }else{
            parent[u]=find(parent[u]);
            return parent[u];
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
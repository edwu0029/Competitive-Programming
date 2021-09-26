/*
Line Graph
DMOPC '15 Contest 6 P4
https://dmoj.ca/problem/dmopc15c6p4
*/

import java.util.*;
import java.io.*;

public class dmopc15c6p4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static int[]parent;
    public static int[]rank;
    public static class Edge implements Comparable<Edge>{
        int startV;
        int endV;
        int weight;
        public Edge(int startV, int endV, int weight){
            this.startV = startV;
            this.endV = endV;
            this.weight = weight;
        }
        @Override
        public int compareTo(Edge o) {
            return this.weight-o.weight;
        }
    }
    public static int find(int v){
        if(parent[v]==-1){
            return v;
        }else{
            parent[v]=find(parent[v]);
            return parent[v];
        }
    }
    public static void Union(int a, int b){
        if(rank[a]>rank[b]){
            parent[a]=b;
        }else{
            parent[b]=a;
            if(rank[a]==rank[b]){
                rank[b]++;
            }
        }
    }
    public static void main(String args[]) throws IOException{
        int N = readInt(); int K = readInt();
        parent = new int[100000]; Arrays.fill(parent, -1);
        rank = new int[100000];
        Edge[]edgesF = new Edge[200000];
        int weightTemp = 0;
        int temp = 0;
        for(int i = 0;i<N-1;i++){
            weightTemp = readInt();
            edgesF[temp] = new Edge(i,i+1,weightTemp); temp++;
            if(i+K<=N-1){
                edgesF[temp] = new Edge(i,i+K,0); temp++;
            }
        }
        Edge[]edges = new Edge[temp];
        for(int i = 0;i<temp;i++){
            edges[i] = new Edge(edgesF[i].startV, edgesF[i].endV,edgesF[i].weight);
        }
        Arrays.sort(edges);
        int startV = 0, endV = 0, parentA = 0,parentB = 0;
        int total = 0;
        for(int i = 0;i<edges.length;i++){
            startV = edges[i].startV;
            endV = edges[i].endV;
            parentA = find(startV);
            parentB = find(endV);
            if(parentB!=parentA){
                total = total+edges[i].weight;
                Union(parentA,parentB);
            }
        }
        System.out.println(total);
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
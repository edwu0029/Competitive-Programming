/*
Apples to Oranges
DMPG '15 S6
https://dmoj.ca/problem/dmpg15s6
*/

import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class dmpg15s6{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static class trade{
        int v; double r;
        public trade(int v, double r){
            this.v = v; this.r = r;
        }
    }
    static HashMap<String, Integer>fruits = new HashMap<String, Integer>();
    static ArrayList<trade>[]adj;
    static double[]A;
    public static void main(String[]args) throws IOException{
        int N = readInt(), M = readInt(), tmp = 0;
        adj = new ArrayList[N+1]; A = new double[N+1];
        for(int i = 1;i<=N;i++) {
            adj[i] = new ArrayList<trade>();
            fruits.put(read(), ++tmp);
        }
        for(int i = 1;i<=M;i++){
            String s = read(), s2 = read();
            double rate = readDouble();
            adj[fruits.get(s)].add(new trade(fruits.get(s2), rate));
        }
        int start = fruits.get("APPLES");
        LinkedList<Integer>q = new LinkedList<Integer>();
        q.add(start); A[start]=1000.0;
        while(!q.isEmpty()){
            int cur = q.poll();
            if(cur==start&&A[start]-1000.0>0.1){
                System.out.println("YA");
                return;
            }
                for(trade i:adj[cur]){
                if(A[i.v]<i.r*A[cur]){
                    A[i.v] = i.r*A[cur];
                    q.add(i.v);
                }
            }
        }
        System.out.println("NAW");
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
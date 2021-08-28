//Problem: https://dmoj.ca/problem/dmopc14ce1p4

import java.util.*;
import java.io.*;

public class dmopc14ce1p4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static class road{
        int endV; double distance; double speed; double time;
        public road(int endV, double distance, double speed){
            this.endV = endV;
            this.distance = distance;
            this.speed = speed;
            this.time = (double)distance/speed;
        }
    }
    public static void main(String args[]) throws IOException{
        int V = readInt(), E = readInt();
        ArrayList<road>[]F = new ArrayList[V];
        for(int i = 0;i<V;i++) F[i] = new ArrayList<road>();
        for(int i = 0;i<E;i++){
            int a = readInt()-1, b = readInt()-1; double d = readDouble(), s = readDouble();
            F[a].add(new road(b,d,s)); F[b].add(new road(a,d,s));
        }
        int[]numedges = new int[V]; Arrays.fill(numedges, Integer.MAX_VALUE);
        double[]dis = new double[V]; Arrays.fill(dis,Double.MAX_VALUE);
        int[]pre = new int[V];
        LinkedList<Integer>l = new LinkedList<Integer>();
        l.add(0); dis[0] = 0; numedges[0] = 0;
        int cur = 0, temp = 0; double v = 0;
        while(!l.isEmpty()){
            cur = l.poll();
            for(int i = 0;i<F[cur].size();i++){
                temp = F[cur].get(i).endV; v = F[cur].get(i).time;
                if(dis[temp]>dis[cur]+v||(dis[temp]==dis[cur]+v&&numedges[cur]+1<=numedges[temp])){
                    l.add(temp); dis[temp] = dis[cur]+v;
                    numedges[temp] = numedges[cur]+1;
                    pre[temp] = cur;
                }
            }
        }
        System.out.println(numedges[V-1]);    
        System.out.printf("%.0f\n", 60.0 * (dis[V-1]/0.75-dis[V-1]));
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
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}

/*
Air Travel Planning
DWITE Online Computer Programming Contest, April 2010, Problem 5
https://dmoj.ca/problem/dwite09c6p5
*/

import java.io.*;
import java.util.*;

public class dwite09c6p5 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static int[][]connectionsP;
    public static void main(String args[]) throws IOException{
        for(int gh =0;gh<5;gh++){
            int N = readInt(), temp = 0;
            connectionsP = new int[40][40];
            HashMap<String,Integer>h = new HashMap<String,Integer>();
            for(int i = 0;i<N;i++){
                String s = next(); String s2 = next(); int price = readInt();
                if(!h.containsKey(s)){
                    h.put(s, temp++);
                }
                if(!h.containsKey(s2)){
                    h.put(s2, temp++);
                }
                connectionsP[h.get(s)][h.get(s2)] = price;
                connectionsP[h.get(s2)][h.get(s)] = price;
            }
            int start = h.get("YYZ"); int end = h.get("SEA");
            LinkedList<Integer>l = new LinkedList<Integer>();
            int[]dis = new int[40]; Arrays.fill(dis,Integer.MAX_VALUE);
            l.add(start); dis[start] = 0;
            int cur = 0;
            while(!l.isEmpty()){
                cur = l.poll();
                for(int i = 0;i<40;i++){
                    if(connectionsP[cur][i]!=0&&dis[i]>dis[cur]+connectionsP[cur][i]){
                        l.add(i); dis[i]=dis[cur]+connectionsP[cur][i];
                    }
                }
            }
            System.out.println(dis[end]);
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
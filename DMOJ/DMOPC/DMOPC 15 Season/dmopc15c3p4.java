/*
Contagion
DMOPC '15 Contest 3 P4
https://dmoj.ca/problem/dmopc15c3p4
*/

import java.util.*;
import java.io.*;


public class dmopc15c3p4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        int N = readInt();
        int[]Fx = new int[N]; int[]Fy = new int[N];
        for(int i = 0;i<N;i++){
            Fx[i] = readInt(); Fy[i] = readInt();
        }
        int X = readInt()-1;
        boolean[]vis = new boolean[N]; 
        long[]dis = new long[N];Arrays.fill(dis,Long.MAX_VALUE);
        dis[X] = 0; 
        int cur = 0; long temp = 0;
        for(int i = 0;i<=N;i++){
            cur = minDist(dis,vis); if(cur==-1) break;
            vis[cur] = true;
            for(int d = 0;d<N;d++){
                temp = time(Fx[d],Fy[d],Fx[cur],Fy[cur]);
                if(dis[d]>temp+dis[cur]){
                    dis[d] = temp+dis[cur];
                }
            }
        }
        Arrays.sort(dis);
        int Q = readInt(); int f = 0;
        for(int i = 0;i<Q;i++){
            temp = readLong();
            f = Arrays.binarySearch(dis,temp);
            if(f<0){
                f = -f-1;
            }else{
                while(f<N&&dis[f]<=temp) f++;
            }
            System.out.println(f);
        }
    }
    public static int minDist(long[]dis,boolean[]vis){
        long min = Long.MAX_VALUE; int index = -1;
        for(int i = 0;i<dis.length;i++){
            if(min>dis[i]&&!vis[i]){min = dis[i]; index = i;}
        }
        return index;
    }
    public static long time(long point1x, long point1y, long point2x, long point2y){
        return ((Math.abs(point1x-point2x))*(Math.abs(point1x-point2x)))+((Math.abs(point1y-point2y))*(Math.abs(point1y-point2y)));
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
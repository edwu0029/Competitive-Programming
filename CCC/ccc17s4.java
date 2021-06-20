//Problem: https://dmoj.ca/problem/ccc17s4

import java.util.*;
import java.io.*;

public class ccc17s4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int [][]nodes;
    static class path implements Comparable<path>{
        int fr,to, w,nw ;
        path(int a, int b, int c, int d){
            fr=a;to=b;w=c;nw=d;
        }
        public int compareTo(path e){
            if(this.w<e.w||(this.w==e.w&&this.nw<e.nw))return -1;
            else if(this.w>e.w||(this.w==e.w&&this.nw>e.nw))return 1;
            else return 0;
        }
    }
    static int find(int cur){
        if(nodes[cur][0]==-1)return cur;
        else return find(nodes[cur][0]);
    }
    static void union(int x, int y){
        if(nodes[x][1]>nodes[y][1])nodes[y][0]=x;
        else if(nodes[x][1]<nodes[y][1]) nodes[x][0]=y;
        else{
            nodes[y][0]=x;
            nodes[x][1]++;
        }
    }
    public static void main(String args[]) throws IOException{
        int n = readInt(), m = readInt(), d = readInt();
        nodes=new int[n][2];
        LinkedList<path>paths=new LinkedList<path>();
        for(int i=0;i<n;i++)nodes[i][0]=-1;
        for(int i=0;i<m;i++){
            int a = readInt()-1, b = readInt()-1, w = readInt();
            if(i<n-1){
                paths.add(new path(a,b,w,0));
            }else{
                paths.add(new path(a,b,w,1));
            }
        }
        Collections.sort(paths);
        int days=0, max=0, maxn=0;
        for(int i=0;i<m;i++){
            path p = paths.poll();
            int xR=find(p.fr), yR=find(p.to);
            if(xR!=yR){
                union(xR,yR);
                days+=p.nw;
                max=p.w;
                maxn=p.nw;
            }
            paths.add(p);
        }
        for(int i=0;i<n;i++)nodes[i][0]=-1;
        if(maxn==1){
            for(int i=0;i<m;i++){
                path p =paths.poll();
                int xR=find(p.fr), yR=find(p.to);
                if(xR!=yR){
                    if(p.w<max||(p.w==max&&p.nw==0)){
                        union(xR, yR);
                    }else if(p.nw==0&&p.w<=d){
                        days--;
                        break;
                    }
                }
                paths.add(p);
            }
        }
        System.out.println(days);
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
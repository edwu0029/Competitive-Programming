/*
AFK
DMOPC '13 Contest 1 P4
https://dmoj.ca/problem/dmopc13c1p4
*/

import java.util.*;
import java.io.*;

public class dmopc13c1p4{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int[]mover = {0, 0, 1, -1};
    static int[]movec = {1, -1, 0, 0};

    public static void main(String[]args) throws IOException{
        int t = readInt();
        while(t>0){
            t--;
            solve();
        }
    }
    static void solve() throws IOException{
        int L = readInt(), W = readInt();
        char[][]m = new char[W+1][L+1];
        int[][]dis = new int[W+1][L+1];
        boolean[][]vis = new boolean[W+1][L+1];
        int str = 0, stc = 0, endr = 0, endc = 0;
        for(int i = 1;i<=W;i++){
            String l = read();
            for(int j = 1;j<=L;j++){
                m[i][j] = l.charAt(j-1);
                if(m[i][j]=='C'){
                    str = i;
                    stc = j;
                }else if(m[i][j]=='W'){
                    endr = i;
                    endc = j;
                }
            }
        }
        vis[str][stc] = true;
        Queue<Integer>qr = new LinkedList<Integer>(), qc = new LinkedList<Integer>();
        qr.add(str); qc.add(stc);
        while(!qr.isEmpty()){
            int curr = qr.poll(), curc = qc.poll();
            for(int i = 0;i<4;i++){
                int nxtr = mover[i]+curr, nxtc = movec[i]+curc;
                if(1<=nxtr&&nxtr<=W&&1<=nxtc&&nxtc<=L&&!vis[nxtr][nxtc]
                    &&m[nxtr][nxtc]!='X'){
                    qr.add(nxtr); qc.add(nxtc);
                    vis[nxtr][nxtc] = true;
                    dis[nxtr][nxtc] = dis[curr][curc]+1;
                }
            }
        }
        if(vis[endr][endc]&&dis[endr][endc]<60) System.out.println(dis[endr][endc]);
        else System.out.println("#notworth");
    }
    static String read() throws IOException{
        while(st==null||!st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static char readChar() throws IOException{
        return read().charAt(0);
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
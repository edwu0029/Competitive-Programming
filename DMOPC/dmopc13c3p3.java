//Problem: https://dmoj.ca/problem/dmopc13c3p3

import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.LinkedList;
import java.util.Queue;

public class dmopc13c3p3{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int[]mover = {0, 0, 1, -1};
    static int[]movec = {1, -1, 0, 0};

    public static void main(String[]args) throws IOException{
        int N = readInt(), H = readInt();
        int[][]F = new int[N+1][N+1];
        boolean[][]vis = new boolean[N+1][N+1];
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=N;j++)
                F[i][j] = readInt();
        Queue<Integer>qr = new LinkedList<Integer>(), qc = new LinkedList<Integer>();
        qr.add(1); qc.add(1);
        vis[1][1] = true;
        while(!qr.isEmpty()){
            int curr = qr.poll(), curc = qc.poll();
            for(int i = 0;i<4;i++){
                int nxtr = curr+mover[i], nxtc = curc+movec[i];
                if(1<=nxtr&&nxtr<=N&&1<=nxtc&&nxtc<=N&&!vis[nxtr][nxtc]
                    &&Math.abs(F[curr][curc]-F[nxtr][nxtc])<=H){
                    qr.add(nxtr); qc.add(nxtc);
                    vis[nxtr][nxtc] = true;
                }
            }
        }
        if(vis[N][N]) System.out.println("yes");
        else System.out.println("no");
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
//Problem: https://dmoj.ca/problem/ccc21s2

import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class ccc21s2{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[]args) throws IOException{
        int M = readInt(), N = readInt(), K = readInt();
        int[][]F = new int[M+1][N+1];
        for(int i = 1, x;i<=K;i++){
            char op = read().charAt(0); x = readInt();
            if(op=='R') F[x][0]++;
            else F[0][x]++;
        }
        int ans = 0;
        for(int i = 1;i<=M;i++){
            for(int j = 1;j<=N;j++){
                F[i][j]+=F[i-1][j]+F[i][j-1]-F[i-1][j-1];
                if(F[i][j]%2==1) ans++;
            }
        }
        System.out.println(ans);
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
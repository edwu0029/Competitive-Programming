/*
Sunflowers
Canadian Computing Competition: 2018 Stage 1, Junior #4, Senior #2
https://dmoj.ca/problem/ccc18s2
*/

import java.util.*;
import java.io.*;

public class ccc18s2{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int MAXN = 2000002;
    public static void main(String[]args) throws IOException{
        int N = readInt();
        int[][]F = new int[N][N];
        for(int i = 0;i<N;i++)
            for(int d = 0;d<N;d++) F[i][d] = readInt();
        
        for(int i = 0;i<4;i++){
            if(!check(F,N)){
                F = rotate(F,N);
            }else{
                for(int h = 0;h<N;h++){
                    for(int k = 0;k<N;k++) System.out.print(F[h][k]+" ");
                    System.out.println("");
                }
                return;
            }
        }
    }
    public static boolean check(int[][]F,int N){
        int[]tempy = new int[N];
        for(int i = 0;i<N;i++) tempy[i] = F[i][0];
        Arrays.sort(tempy);
        for(int i = 0;i<N;i++)
            if(tempy[i]!=F[i][0]) return false;
        int[]tempx = new int[N];
        for(int i = 0;i<N;i++){
            for(int h = 0;h<N;h++) tempx[h]=F[i][h];
            Arrays.sort(tempx);
            for(int d = 0;d<N;d++)
                if(tempx[d]!=F[i][d]) return false;
        }
        return true;
    }
    public static int[][] rotate(int[][]F,int N){
        int[][]newN = new int[N][N];
        int[]temp = new int[N];
        for(int i = 0;i<N;i++){
            temp = F[i];
            for(int d = 0;d<N;d++) newN[d][i] = temp[N-1-d];
        }
        return newN;
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
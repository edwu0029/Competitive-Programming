//Problem: https://dmoj.ca/problem/coci15c4p3

import java.util.*;
import java.io.*;

public class coci15c4p3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = readInt(); int[]ans = new int[N];
        int[][]F = new int[N][N];
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                int k = readInt();
                if(ans[i]==0){ans[i]=k;}else{ans[i]=ans[i]|k;}
                if(ans[j]==0){ans[j]=k;}else{ans[j]=ans[j]|k;}
            }
        }
        System.out.println();
        for(int i = 0;i<N;i++){
            System.out.print(ans[i]+" ");
        }
    }
    static String next() throws IOException{
        while(st==null||!st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt() throws IOException{
        return Integer.parseInt(next());
    }
    static long readLong() throws IOException{
        return Long.parseLong(next());
    }
}
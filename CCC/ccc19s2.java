//Problem: https://dmoj.ca/problem/ccc19s2

import java.util.*;
import java.io.*;

public class ccc19s2{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int MAXN = 2000002;
    public static void main(String[]args) throws IOException{
        boolean[]p = new boolean[MAXN];
        for(int i = 2;i<MAXN;i++){
            if(p[i]) continue;
            for(int j = 2*i;j<MAXN;j+=i){
                p[j] = true;
            }
        }
        int T = readInt();
        for(int i = 0;i<T;i++){
            int N = readInt();
            for(int j = 2;j<=MAXN/2;j++){
                int A = j, B = 2*N-A;
                if(!p[A] && !p[B]){
                    System.out.println(A+" "+B);
                    break;
                }
            }
        }
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
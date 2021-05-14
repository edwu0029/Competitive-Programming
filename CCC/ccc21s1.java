//Problem: https://dmoj.ca/problem/ccc21s1

import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class ccc21s1{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[]args) throws IOException{
        int N = readInt();
        int tot = 0;
        int[]h = new int[N+2], w = new int[N+1];
        for(int i = 1;i<=N+1;i++) h[i] = readInt();
        for(int i = 1;i<=N;i++) w[i] = readInt();
        for(int i = 1;i<=N;i++){
            tot+=(h[i]+h[i+1])*w[i];
        }
        if(tot%2==0) System.out.println(tot/2);
        else System.out.println(tot/2+".5");
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
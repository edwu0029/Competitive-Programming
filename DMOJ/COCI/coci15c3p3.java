/*
Molekule
COCI '15 Contest 3 #3
https://dmoj.ca/problem/coci15c3p3
*/

import java.util.*;
import java.io.*;

public class coci15c3p3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        int N = readInt();
        int[]a = new int[N-1], b = new int[N-1], ans = new int[N];
        Arrays.fill(ans, -1);
        ans[0]=0;
        ArrayList<Integer>[]F = new ArrayList[N];
        for(int i = 0;i<N;i++)F[i] = new ArrayList<Integer>();
        for(int i = 0;i<N-1;i++){
            a[i]=readInt()-1; b[i]=readInt()-1;
            F[a[i]].add(b[i]);
            F[b[i]].add(a[i]);
        }
        LinkedList<Integer>l = new LinkedList<Integer>();
        l.add(0);
        while(!l.isEmpty()){
            int cur = l.poll();
            for(int i:F[cur]){
                if(ans[i]!=-1)continue;
                if(ans[cur]==0)ans[i]=1;
                else ans[i]=0;
                l.add(i);
            }
        }
        for(int i = 0;i<N-1;i++){
            System.out.println(ans[a[i]]);
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
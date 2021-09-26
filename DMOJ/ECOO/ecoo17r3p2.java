/*
Family Trees
ECOO '17 R3 P2
https://dmoj.ca/problem/ecoo17r3p2
*/

import java.util.*;
import java.io.*;

public class ecoo17r3p2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int MOD = 1000000007;
    public static void main(String[] args) throws IOException{
        for(int t = 0;t<10;t++){
            int N = readInt(), total = 0, tmp = 1;
            HashMap<Integer, Integer>[] people = new HashMap[N*20+1];
            int[] maxV = new int[N*20+1];
            for(int i = 0; i < 20*N+1; i++){
                people[i] = new HashMap<Integer, Integer>();
                maxV[i] = -1;
            }
            for(int i = 1;i<=N;i++){
                String s = read();
                String[] ID = s.split("\\.");
                int cnt=0;
                for(int j = 0; j < ID.length; j++){
                    int cur=Integer.parseInt(ID[j]);
                    if(!people[cnt].containsKey(cur)){
                        people[cnt].put(cur, tmp++);
                        if(cur>maxV[cnt]) {
                            if(cur==0) {
                                total=(total+1)%MOD;
                            } else {
                                if(maxV[cnt]==-1) total=(total+cur)%MOD;
                                else total=(total+(cur-maxV[cnt]))%MOD;
                            }
                            maxV[cnt]=cur;
                        }
                    }
                    cnt=people[cnt].get(cur);
                }
            }
            System.out.println(total);
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
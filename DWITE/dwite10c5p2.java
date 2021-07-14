//Problem: https://dmoj.ca/problem/dwite10c5p2

import java.util.*;
import java.io.*;

public class dwite10c5p2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        for(int j = 0;j<5;j++){
            int R = readInt(), C = readInt(), num = readInt();
            ArrayList<Integer>tmpr = new ArrayList<Integer>(), tmpc = new ArrayList<Integer>();
            for(int i = 0;i<num;i++){
                int Rr = readInt(), Cr = readInt();
                if(!tmpr.contains(Rr))tmpr.add(Rr);
                if(!tmpc.contains(Cr))tmpc.add(Cr);
            }
            System.out.println((R-tmpr.size())*(C-tmpc.size()));
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
//Problem: https://dmoj.ca/problem/coci14c1p2

import java.util.*;
import java.io.*;

public class coci14c1p2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int n = readInt();
        int minx = Integer.MAX_VALUE;
        int maxx = -1;
        int miny = Integer.MAX_VALUE;
        int maxy = -1;
        int x = 0;
        int y = 0;
        
        for(int i = 0;i<n;i++){
            x = readInt();
            y  = readInt();        
            minx = Math.min(x, minx);
            maxx = Math.max(x, maxx);
            miny = Math.min(y, miny);
            maxy = Math.max(y, maxy);
        }
        if((maxx-minx)>(maxy-miny)){
            System.out.println((maxx-minx)*(maxx-minx));
        }else if((maxx-minx)<(maxy-miny)){
            System.out.println((maxy-miny)*(maxy-miny));
        }else{
            System.out.println((maxx-minx)*(maxx-minx));
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
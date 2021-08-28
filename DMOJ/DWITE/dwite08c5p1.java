//Problem: https://dmoj.ca/problem/dwite08c5p1

import java.io.*;
import java.util.*;

public class dwite08c5p1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        //dwite08c5p1
        for(int i = 0;i<5;i++){
            String s = br.readLine(); String s2 = br.readLine();
            int total = 0;
            for(int d = 0;d<Math.min(s.length(), s2.length());d++){
                if(s.charAt(d)==s2.charAt(d)){
                    total++;
                }else{
                    break;
                }
            }
            System.out.println(total);
        }
    }
    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
}
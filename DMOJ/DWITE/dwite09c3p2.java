/*
Rounding to Fibonacci
DWITE Online Computer Programming Contest, December 2009, Problem 2
https://dmoj.ca/problem/dwite09c3p2
*/

import java.io.*;
import java.util.*;

public class dwite09c3p2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static char[][]cage;
    static int[][]room;
    static ArrayList<Integer>[]F;
    static Stack<Integer>s;
    static boolean[]vis;
    static boolean[]vis2;
    public static void main(String args[]) throws IOException{
        LinkedList<Long>l = new LinkedList<Long>();
        l.add((long) 0);
        l.add((long) 1);
        long temp = (long) 0;
        while(true){
            temp = l.get(l.size()-1)+l.get(l.size()-2);
            l.add(temp);
            if(temp>=1134903170){
                break;
            }
            
        }
        long diff1, diff2;
        for(int i = 0;i<5;i++){
            temp = readLong();
            for(int d = l.size()-2;d>=0;d--){
                if(l.get(d+1)>=temp&&l.get(d)<=temp){
                    diff1 = l.get(d+1)-temp;
                    diff2 = temp-l.get(d);
                    if(diff1>diff2){
                        System.out.println(l.get(d));
                    }else{
                        System.out.println(l.get(d+1));
                    }
                    break;
                }
            }
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
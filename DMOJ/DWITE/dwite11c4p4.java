/*
Lego Ladder
DWITE Online Computer Programming Contest, January 2012, Problem 4
https://dmoj.ca/problem/dwite11c4p4
*/

import java.io.*;
import java.util.*;

public class dwite11c4p4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N;
    static String ans;
    static boolean[]lose = new boolean[1<<16];
    static boolean[]solved = new boolean[1<<16];
    static int[]F;
    public static void main(String args[]) throws IOException{
        for(int h = 0;h<5;h++){
             ans = "";
            for(int g = 0;g<3;g++){
                lose = new boolean[1<<16];
                solved = new boolean[1<<16];
                N = readInt(); F = new int[N];
                for(int i= 0;i<N;i++){F[i]=readInt();}
                if(solve(0)){ans=ans+"B";}else ans=ans+"A";
            }
            System.out.println(ans);
        }
    }
    static boolean check(int mask){
        if(solved[mask])return lose[mask];
        int pre = -1;
        boolean increase = true, decrease = true;
        for(int i = 0;i<N;i++){
            if((mask&1<<i)==0){
                if(pre==-1)pre=F[i];
                if(F[i]>pre)decrease=false;
                if(F[i]<pre)increase=false;
                pre = F[i];
            }
        }
        return increase||decrease;
    }
    static boolean solve(int bitmask){
        int cur = 0;
        if(solved[bitmask])return lose[bitmask];
        if(check(bitmask))return true;
        for(int i = 0;i<N;i++){
            if((bitmask&1<<i)==0){
                cur = bitmask|1<<i;
                if(check(cur)){lose[cur]=true;}
                else {lose[cur]=solve(cur);}
                solved[cur]=true;
                if(lose[cur]){lose[bitmask]=false;return lose[bitmask];}
            }
        }
        lose[bitmask]=true;
        return lose[bitmask];
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

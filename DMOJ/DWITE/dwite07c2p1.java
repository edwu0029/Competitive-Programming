/*
Not Quite Prime
DWITE Online Computer Programming Contest, November 2007, Problem 1
https://dmoj.ca/problem/dwite07c2p1
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class dwite07c2p1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        int[]primes = new int[10001]; for(int i = 0;i<=1001;i++) primes[i]=i;
        ArrayList<Double>p = new ArrayList<Double>();
        for(int i = 2;i<=1001;i++){
            if(primes[i]!=-1){
                p.add((double)i); 
                for(int d = 2*i;d<=1001;d+=i) primes[d]=-1;
            }
        }
        boolean f = true;
        for(int i = 0;i<5;i++){
            int N = readInt(); f = true;
            for(int d = 0;d<p.size();d++){
                if(p.contains((double)(N/p.get(d)))){
                    System.out.println("semiprime");
                    f = false;
                    break;
                }
            }
            if(f) System.out.println("not");
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
    static double readDouble() throws IOException{
        return Double.parseDouble(next());
    }
}
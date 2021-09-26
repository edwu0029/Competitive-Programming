/*
Sum of Primes
DWITE Online Computer Programming Contest, May 2010, Problem 2
https://dmoj.ca/problem/dwite09c7p2
*/

import java.io.*;
import java.util.*;

public class dwite09c7p2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        for(int i = 0;i<5;i++){
            int n = readInt(), total = 0;
            for(int d = 2;d<=n;d++){
                if(isPrime(d))
                    total = total+d;
            }
            System.out.println(total);
        }
    }
    public static boolean isPrime(int n){
        for(int i = 2;i<=Math.sqrt(n);i++)
            if(n%i==0)
                return false;
        return true;
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
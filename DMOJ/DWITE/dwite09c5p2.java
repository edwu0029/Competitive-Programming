//Problem: https://dmoj.ca/problem/dwite09c5p2

import java.io.*;
import java.util.*;

public class dwite09c5p2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        //problem/dwite09c5p2
        int[]primes = new int[10001];
        for(int i = 0;i<=1001;i++){
            primes[i]=i;
        }
        ArrayList<Integer>p = new ArrayList<Integer>();
        for(int i = 2;i<=1001;i++){
            if(primes[i]!=-1){
                p.add(i); 
                for(int d = 2*i;d<=1001;d+=i) primes[d]=-1;
            }
        }
        for(int i = 0;i<5;i++){
            int N = readInt(), temp = N+1, temp2 = N-1, cnt = 0, cntm = 0;
            while(true){
                if(p.contains(temp)) cnt++;
                if(p.contains(temp2))cntm++;
                if(cnt==2){
                    System.out.println(temp);
                    break;
                }
                if(cntm==2){
                    System.out.println(temp2);
                    break;
                }
                temp++; temp2--;
            }
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
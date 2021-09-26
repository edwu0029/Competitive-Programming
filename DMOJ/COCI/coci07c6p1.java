/*
Parking
COCI '07 Contest 6 #1
https://dmoj.ca/problem/coci07c6p1
*/

import java.util.*;
import java.io.*;

public class coci07c6p1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        int A = readInt(); int B = readInt(); int C = readInt();
        int[]Ap = new int[100]; int[]Bp =  new int[100]; int[]Cp = new int[100];
        for(int k = 0;k<3;k++){
            int st = readInt(); int end = readInt();
            if(k==0){
                for(int i = st;i<end;i++){
                    Ap[i]=1;
                }
            }else if(k==1){
                for(int i = st;i<end;i++){
                    Bp[i]=1;
                }
            }else{
                for(int i = st;i<end;i++){
                    Cp[i]=1;
                }
            }
        }
        int total = 0;
        for(int i = 0;i<100;i++){
            if(Ap[i]+Bp[i]+Cp[i]==1){
                total = total + A;
            }else if(Ap[i]+Bp[i]+Cp[i]==2){
                total = total + (B*2);
            }else if(Ap[i]+Bp[i]+Cp[i]==3){
                total = total + (C*3);
            }
        }
        System.out.println(total);
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
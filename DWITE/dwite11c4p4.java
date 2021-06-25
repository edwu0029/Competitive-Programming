//Problem: https://dmoj.ca/problem/dwite11c4p4

import java.io.*;
import java.util.*;

public class dwite11c4p4 {
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
    final private static int BUFFER_SIZE = 1 << 16;
    private static DataInputStream din = new DataInputStream(System.in);
    private static byte[] buffer = new byte[BUFFER_SIZE];
    private static int bufferPointer = 0, bytesRead = 0;
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    public static String readLine() throws IOException {
        byte[] buf = new byte[64]; // line length
        int cnt = 0, c;
        while ((c = Read()) != -1) {
            if (c == '\n')
                break;
            buf[cnt++] = (byte) c;
        }
        return new String(buf, 0, cnt);
    }
    public static String read() throws IOException{
        byte[] ret = new byte[1024];
        int idx = 0;
        byte c = Read();
        while (c <= ' ') {
            c = Read();
        }
        do {
            ret[idx++] = c;
            c = Read();
        } while (c != -1 && c != ' ' && c != '\n' && c != '\r');
        return new String(ret, 0, idx);
    }
    public static int readInt() throws IOException {
        int ret = 0;
        byte c = Read();
        while (c <= ' ')
            c = Read();
        boolean neg = (c == '-');
        if (neg)
            c = Read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = Read()) >= '0' && c <= '9');

        if (neg)
            return -ret;
        return ret;
    }

    public static long readLong() throws IOException {
        long ret = 0;
        byte c = Read();
        while (c <= ' ')
            c = Read();
        boolean neg = (c == '-');
        if (neg)
            c = Read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = Read()) >= '0' && c <= '9');
        if (neg)
            return -ret;
        return ret;
    }

    public static double readDouble() throws IOException {
        double ret = 0, div = 1;
        byte c = Read();
        while (c <= ' ')
            c = Read();
        boolean neg = (c == '-');
        if (neg)
            c = Read();

        do {
            ret = ret * 10 + c - '0';
        } while ((c = Read()) >= '0' && c <= '9');

        if (c == '.') {
            while ((c = Read()) >= '0' && c <= '9') {
                ret += (c - '0') / (div *= 10);
            }
        }

        if (neg)
            return -ret;
        return ret;
    }

    private static void fillBuffer() throws IOException {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1)
            buffer[0] = -1;
    }

    private static byte Read() throws IOException {
        if (bufferPointer == bytesRead)
            fillBuffer();
        return buffer[bufferPointer++];
    }

    public void close() throws IOException {
        if (din == null)
            return;
        din.close();
    }

    static void print(Object o) {
        pr.print(o);
    }

    static void println(Object o) {
        pr.println(o);
    }

    static void flush() {
        pr.flush();
    }

    static void println() {
        pr.println();
    }

    static void exit() throws IOException {
        din.close();
        pr.close();
        System.exit(0);
    }
}

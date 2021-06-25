//Problem: https://dmoj.ca/problem/coci07c2p3

import java.io.*;
import java.util.*;

public class coci07c2p3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int cnt;
    public static void main(String args[]) throws IOException{
        int R = readInt(), C = readInt();
        char[][]F = new char[R][C];
        ArrayList<Integer>lr = new ArrayList<Integer>();
        ArrayList<Integer>lc = new ArrayList<Integer>();
        for(int r = 0;r<R;r++){
            String s = next();
            for(int c = 0;c<C;c++){
                F[r][c]=s.charAt(c);
                if(F[r][c]=='#'){
                    lr.add(r); lc.add(c);
                }
            }
        }
        ArrayList<String>l = new ArrayList<String>();
        for(int i = 0;i<R;i++){
            if(F[i][0]!='#'){
                l.add(check(F,R,C,i,0,2));
            }
        }
        for(int i = 0;i<C;i++){
            if(F[0][i]!='#'){
                l.add(check(F,R,C,0,i,1));
            }
        }
        for(int i = 0;i<lc.size();i++){
            if(lr.get(i)!=R-1) l.add(check(F,R,C,lr.get(i)+1,lc.get(i),1));
            if(lc.get(i)!=R-1) l.add(check(F,R,C,lr.get(i),lc.get(i)+1,2));
        }
        Collections.sort(l);
        for(int i = 0;i<l.size();i++){
            if(l.get(i).length()>=2){
                System.out.println(l.get(i));
                return;
            }
        }
    }
    static String check(char[][]F, int R, int C, int r, int c, int key){
        String s = "";
        if(key==1){
            for(int i = r;i<R;i++){
                int j = c;
                if(F[i][j]!='#'){s+=(F[i][j]);}
                else break;
            }
            return s;
        }else{
            for(int j = c;j<C;j++){
                int i = r;
                if(F[i][j]!='#'){s+=(F[i][j]);}
                else break;
            }
        }
        return s;
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
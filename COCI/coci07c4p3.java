//Problem: https://dmoj.ca/problem/coci07c4p3

import java.io.*;
import java.util.*;

public class coci07c4p3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String args[]) throws IOException{
        String s = read(), ans = "";
        ArrayList<String>l = new ArrayList<String>();
        for(int i = 0;i<s.length();i++){
            for(int j = i+1;j<s.length()-1;j++){
                ans = "";
                String tmp = s.substring(0, i+1);
                String tmp2 = s.substring(i+1,j+1);
                String tmp3 = s.substring(j+1);
                for(int k = 0;k<tmp.length();k++){
                    ans+=(tmp.charAt(tmp.length()-1-k));
                }
                for(int k = 0;k<tmp2.length();k++){
                    ans+=(tmp2.charAt(tmp2.length()-1-k));
                }
                for(int k = 0;k<tmp3.length();k++){
                    ans+=(tmp3.charAt(tmp3.length()-1-k));
                }
                l.add(ans);
            }
        }
        Collections.sort(l);
        System.out.println(l.get(0));
        
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
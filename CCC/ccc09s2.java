//Problem: https://dmoj.ca/problem/ccc09s2

import java.util.*;
import java.io.*;

public class ccc09s2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String args[]) throws IOException{
        int row = readInt(); int col = readInt();
        String temp = "", temp2 = "", new3="";    
        int[][]light = new int[row][col];    
        for(int i = 0;i<row;i++){
            for(int c = 0;c<col;c++){
                light[i][c] = readInt();
            }
        }
        LinkedList<String>pre = new LinkedList<String>();
        for(int i = 0;i<col;i++) temp+=light[0][i];
        pre.add(temp);
        for(int r = 1;r<row;r++){
            temp2 = "";
            for(int c=0;c<col;c++){
                temp2 = temp2+Integer.toString(light[r][c]);
            }
            LinkedList<String>cur=new LinkedList<String>();
            cur.add(temp2);
            for(int i = 0;i<pre.size();i++){
                new3 = Combine(temp2,pre.get(i));
                if(!cur.contains(new3)){
                    cur.add(new3);
                }
            }
            pre=cur;
        }
        System.out.println(pre.size());
    }
    public static String Combine(String s1,String s2){
        char a, a2;
        String new2 = "";
        for(int i = 0;i<s1.length();i++){
            a = s1.charAt(i);
            a2 = s2.charAt(i);
            if(a==a2){
                new2=new2+"0";
            }else{
                new2 = new2+"1";
            }
        }
        return new2;
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
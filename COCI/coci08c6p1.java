//Problem: https://dmoj.ca/problem/coci08c6p1

import java.util.*;
import java.io.*;

public class coci08c6p1 {
    public static LinkedList<Integer>l = new LinkedList<Integer>();
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        String s = sc.next();
        char a = sc.next().charAt(0);
        String s2 = sc.next();

        String ans = "";
        char[]A;
        if(a=='*'){
            ans = ans+"1";
            for(int i = 0;i<(s.length()-1+s2.length()-1);i++){
                ans = ans+"0";
            }
            System.out.println(ans);
        }else if(a=='+'){
            if(s.length()>s2.length()){
                ans = s;
                A = s.toCharArray();
                char temp = A[s.length()-s2.length()];
                int newdigit = Integer.parseInt(temp+"")+1;
                String stemp = newdigit+"";
                A[s.length()-s2.length()] = stemp.charAt(0);
                for(int i = 0;i<A.length;i++){
                    System.out.print(A[i]);
                }
            }else{
                ans = s2;
                A = s2.toCharArray();
                char temp = A[s2.length()-s.length()];
                int newdigit = Integer.parseInt(temp+"")+1;
                String stemp = newdigit+"";
                A[s2.length()-s.length()] = stemp.charAt(0);
                for(int i = 0;i<A.length;i++){
                    System.out.print(A[i]);
                }
            }
        }
    }
}
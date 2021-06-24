//Problem: https://dmoj.ca/problem/ecoo18r2p2

import java.io.*;
import java.util.*;

public class ecoo18r2p2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String args[]) throws IOException{
		for(int t = 0;t<10;t++){
			int N = readInt(), Di = 0, maxday = 0;
			double total = 0, Wi = 0;
			ArrayList<Double>[]V = new ArrayList[1000005];
			for(int i = 0;i<V.length;i++)V[i] = new ArrayList<Double>();
			for(int i = 0;i<N;i++){
				Di = readInt(); Wi = readDouble();
				V[Di].add(Wi);
				maxday = Math.max(maxday, Di);
			}
			PriorityQueue<Double> pq = new PriorityQueue<Double> (
					  new Comparator<Double> () {
					    public int compare(Double a, Double b) {
					    	if(a<b) return +1;
			                if(a>b) return -1;
			                return 0;
					    }
					  }
					);
			for(int i = maxday;i>0;i--){
				if(!V[i].isEmpty()){
					for(int j =0;j<V[i].size();j++){
						pq.add(V[i].get(j));
					}
				}
				if(!pq.isEmpty())total = total+pq.poll();
			}
			System.out.printf("%.4f\n",total);
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
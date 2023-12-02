import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        HashSet<String> hs = new HashSet<String>();
        
        for(int i = 0; i < n; i++) {
            hs.add(br.readLine());
        }
        
        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), ",");
            while(st.hasMoreTokens()) {
                String key = st.nextToken();
                if(hs.contains(key)) {
                    hs.remove(key);
                }
            }
            sb.append(hs.size()+"\n");
        }
        System.out.print(sb);
	}
}

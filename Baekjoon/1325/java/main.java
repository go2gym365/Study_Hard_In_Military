import java.io.*;
import java.util.*;

public class main {
    static boolean[] vis;
    static int max = Integer.MIN_VALUE;
    static int n, m;
    static int cnt;
    static ArrayList<Integer> arrayList = new ArrayList<>();


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i = 0; i <= n; i++) {
            arrayList.add(new ArrayList<>());
            System.out.println();
        }
    }
}
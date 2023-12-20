import java.util.*;
import java.io.*;

public class Main {
    static int n, m;
    static int[] parent;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        parent = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if (merge(a, b)) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(0);
    }

    static boolean merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return true;

        if (x < y)
            parent[y] = x;
        else
            parent[x] = y;

        return false;
    }

    static int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

}

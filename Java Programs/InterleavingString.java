
import java.util.LinkedList;
import java.util.Queue;

public class InterleavingString {
    public static void main(String[] args){
        System.out.println(new InterleavingString().isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    }

    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        boolean[][] visited = new boolean[s1.length() + 1][s2.length() + 1];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        while (!queue.isEmpty()) {
            int[] p = queue.poll();
            if (visited[p[0]][p[1]]) continue;
            if (p[0] == s1.length() && p[1] == s2.length()) return true;

            if (p[0] < s1.length() && s1.charAt(p[0]) == s3.charAt(p[0] + p[1]))
                queue.offer(new int[]{p[0] + 1, p[1]});
            if (p[1] < s2.length() && s2.charAt(p[1]) == s3.charAt(p[0] + p[1]))
                queue.offer(new int[]{p[0], p[1] + 1});
            visited[p[0]][p[1]] = true;
        }
        return false;
    }
    public boolean isInterleave1(String s1, String s2, String s3) {
        int m = s1.length(), n = s2.length(), l=s3.length();
        if(m+n != l) return false;
        boolean[][] dp = new boolean[m+1][n+1];
        for(int i=0; i<=m;i++){
            for(int j=0; j<=n; j++){
                if(i ==0 && j ==0) dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = dp[i][j-1] && s2.charAt(j-1) == s3.charAt(j-1);
                else if(j == 0)
                    dp[i][j] = dp[i-1][j] && s1.charAt(i-1) == s3.charAt(i-1);
                else
                    dp[i][j] = (s2.charAt(j-1) == s3.charAt(i+j-1) && dp[i][j-1]) || (s1.charAt(i-1) == s3.charAt(i+j-1) && dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
}

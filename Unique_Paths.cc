class Solution {
public:
    int uniquePaths(int m, int n) {
        memset(d, 0, sizeof(d));
        int i, j;
        for (i = 0; i < m; i++)
            d[i][0] = 1;
        for (j = 0; j < n; j++)
            d[0][j] = 1;
        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                d[i][j] = d[i-1][j]+d[i][j-1];
            }
        }
        return d[m-1][n-1];
    }
    int d[100][100];
/*
TLE...
        void solve(int i, int j, int m, int n)
        {
                if (i < m && j < n && !used[i][j]) {
                        used[i][j] = true;
                        if (i == m - 1 && j == n -1) {
                                count++;
                                return;
                        }
                        if (i+1<m) {
                                solve(i+1,j,m,n);
                                used[i+1][j] = false;
                        }
                        if (j+1<n) {
                                solve(i,j+1,m,n);
                                used[i][j+1] = false;
                        }
                }

                return;
        }

        int uniquePaths(int m, int n)
        {
                count = 0;
                memset(used, 0, sizeof(used));
                solve(0, 0, m, n);
                return count;
        }
        bool used[100][100];
        int count;
*/
};

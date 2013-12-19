// http://blog.sina.com.cn/s/blog_71d59f9a01017irg.html
class Solution {
public:
    int numTrees(int n) {
        vector<int> d(n+1, 0);
        d[0] = 1;
        d[1] = 1;
        int i;
        int k;
        for (i = 2; i <= n; i++)
            for (k = 0; k < i; k++) {
                d[i] += d[k]*d[i-k-1];
            }
        return d[n];
    }
};

/*
发现左右子树的规律，树的问题都是发现左右子树的规律
动态规划，区间式，求总数，可以简化成一维
*/

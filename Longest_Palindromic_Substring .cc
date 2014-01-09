class Solution {
public:
    string findPalindrome(string &s) {
        memset(d, 0, sizeof(d));
        int n = s.length();
        int maxlen = 0;
        int begin = 0;
        
        for (int i = 0; i < n; ++i) {
            d[i][i] = true;
            maxlen = 1;
        }
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == s[i+1]) {
                d[i][i+1] = true;
                maxlen = 2;
                begin = i;
            }
        }
        // k is the length of substring
        /*  1.注意d[i][j]还是表示下标，而不是d[i][k]，k表示长度
         *    不是这样的，而是实现的时候k表示长度，子串长度，遍历子串长度
         *  2.不好弄的可以都放到初始化里面，如上面
         */
        for (int k = 3; k <= n; ++k) {
            for (int i = 0; i <= n-k; ++i) {
                int j = i + k -1;
                if (j < n && s[i] == s[j] && d[i+1][j-1]) {
                    d[i][j] = true;
                    if (k > maxlen) {
                        maxlen = k;
                        begin = i;
                    }
                } else
                    d[i][j] = false;
            }
        }
        return s.substr(begin, maxlen);
    }
    string longestPalindrome(string s) {
        return findPalindrome(s);
    }
    bool d[1000][1000];
};

class Solution {
private:
int pos[4];
vector<string> ret;
public:
    bool isvalid(string &s, int start, int len)
    {
        if (start+len > s.length()) return false;  // notice
        string tmp(s, start, len);
        if (len == 1) {
            return "0" <= tmp && tmp <= "9";
        } else if (len == 2) {
            return "10" <= tmp && tmp <= "99";
        } else if (len == 3) {
            return "100" <= tmp && tmp <= "255";
        } else
            return false;
    }
    
    void solve(string &s, int start, int depth)
    {
        int len;
        if (depth == 4) {
            if (start == s.length()) {
                int j = 0;
                int beg = 0;
                string addr;
                for (j = 0; j < 4; j++) {
                    string tmp(s, beg, pos[j]);
                    addr += tmp;
                    if (j != 3) addr += ".";
                    beg += pos[j];
                }
                //cout<<addr<<endl;
                ret.push_back(addr);
            }
            return;
    
        }
        for (len = 1; len < 4; ++len) {
            if (isvalid(s, start, len)) {
                pos[depth] = len;
                solve(s, start+len, depth+1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ret.clear();
        solve(s, 0, 0);
        return ret;
    }
};

/*
DFS深搜
1.注意string的构造函数string (const string& str, size_t pos, size_t len = npos);   len是算当前的。
2.相同位数下，字符串比较等同于数值比较，因为权重一样，要是位数不同，比如"99"和"100"就不等同于数值比较了，有权重了
*/

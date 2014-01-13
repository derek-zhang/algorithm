#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
vector<int> part;
void dynamicPartition(string &s, vector<vector<bool> > &dp) {
    for (int i = 0; i < s.size(); ++i) {
        dp[i][i] = true;
        if (i+1 < s.size()) {
            if (s[i] == s[i+1])
                dp[i][i+1] = true;
        }
    }
    for (int k = 3; k <= s.size(); ++k) {  // 注意是长度，所以 <= s.size 
        for (int i = 0; i < s.size() - k + 1; ++i) {
            int j = i + k -1;
            if (s[i] == s[j] && dp[i+1][j-1])
                dp[i][j] = true;
        }
    }
}

int getCut(string &s, vector<vector<bool> > &dp) {
    vector<int> res;
    part.resize(s.size(), s.size()-1);
    res.resize(s.size(), 0xFFFFFFF);
    res[0] = 0;
    part[0] = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[0][i]) {
                res[i] = 0;
                part[i] = i;
            }
            else if (dp[j+1][i]) {
                if (res[j] + 1 < res[i]) {
                    res[i] = res[j] + 1;
                    part[i] = j;
                }
                //res[i] = min(res[i], res[j] + 1);
            }
        }
                                                                                }
    return res[s.size()-1];
}

int minCut(string s) {
    vector<vector<bool> > dp;
    dp.resize(s.size());
    for (int i = 0; i < s.size(); ++i) {
        dp[i].resize(s.size());
    }
    dynamicPartition(s, dp);
    return getCut(s, dp);
}

void printPath(string &s, int begin, int end)
{
    int i = end;
    if (i != part[i]) {
        printPath(s, begin, part[i]);
        cout<<"|";
        for (int j = part[i]+1; j <= end; ++j)
            cout<<s[j];
        return;
    }
    for (int j = begin; j <= i; ++j)
        cout<<s[j];
}

int main()
{
    string s;
    cin>>s;
    cout<<minCut(s)<<endl;
    printPath(s, 0, s.size()-1);
}

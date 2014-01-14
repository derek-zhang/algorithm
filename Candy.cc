    /*
     * O(n)
     */
    int candy(vector<int> &ratings) {
        if (ratings.size() == 0) return 0;
        vector<int> res;
        res.resize(ratings.size(), 1);
        for (int i = 0; i < res.size() - 1; ++i) {
            if (ratings[i] < ratings[i+1])
                res[i+1] = res[i] + 1;
        }
        for (int i = res.size() - 1; i >= 1; --i) {
            if (ratings[i] < ratings[i-1] && res[i-1] <= res[i])
                res[i-1] = res[i] + 1;
        }
        int sum = 0;
        for (int i = 0; i < res.size(); ++i)
            sum += res[i];
        
        return sum;        
    }
    
    /*
     *  O(n^2) 笨方法
     */
    int candy(vector<int> &ratings) {
        if (ratings.size() == 0) return 0;
        vector<int> res;
        res.resize(ratings.size(), 1);
        for (int i = 0; i < res.size() - 1; ++i) {
            if (ratings[i] < ratings[i+1])
                res[i+1] = res[i] + 1;
            else if (ratings[i] == ratings[i+1])
                res[i+1] = 1;
            else {
                int j = i + 1;
                while (j >= 1 && ratings[j] < ratings[j-1] && res[j] >= res[j-1]) {
                    res[j-1] = res[j] + 1;
                    j--;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < res.size(); ++i)
            sum += res[i];
        return sum;
    }

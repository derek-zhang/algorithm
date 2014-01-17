    int removeDuplicates(int A[], int n) {
        if (n == 0)  return 0;
        int j = 0;
        int count = 0;
        /*
         * 不相等就一起往后移动，相等的话看情况j停下来
         */
        for (int i = 1; i < n; ++i) {
            if (A[i] == A[j]) {
                if (count == 0) {
                    count++;
                    j++;
                    A[j] = A[i];
                }
                if (count == 1) {
                    continue;
                }
                
            } else {
                j++;
                A[j] = A[i];
                count = 0;
            }
        }
        return j + 1;
    }

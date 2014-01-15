class Solution {
public:
     double findKth(int A[], int m, int B[], int n, int k) {
        if (m <= 0) return B[k-1];
        if (n <= 0) return A[k-1];
        if (k <= 1) return min(A[0], B[0]);

        if (m/2 + n/2 + 1 >= k) {
            if (A[m/2] >= B[n/2]) {
                return findKth(A, m/2, B, n, k);
            } else {
                return findKth(A, m, B, n/2, k);
            }
        } else {
            /*
             *  就像binary search一样(比如left = mid + 1)， 不能停在原(A+m/2)，要+1 (A+m/2+1). 
             *  类似binary search思想的都这样
             */
            if (A[m/2] >= B[n/2]) {
                return findKth(A, m, B + n/2 + 1, n - n/2 - 1, k - n/2 -1);
            } else {
                return findKth(A + m/2 + 1, m - m/2 - 1, B, n, k - m/2 -1);
            }
        }
        
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total & 0x01)
            return findKth(A, m, B, n, total/2 + 1);
        else
            return (findKth(A, m, B, n, total/2) + findKth(A, m, B, n, total/2 + 1)) / 2.0;
    }
};

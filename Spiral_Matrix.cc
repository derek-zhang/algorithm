class Solution {
public:
  void spiral(vector<vector<int> > &matrix, int rb, int re, int cb, int ce, vector<int> &res) {
      /* 
       * 特殊情况还是特殊处理比较好，一行、一列的情况。
       * 要是放到下面循环里面，就理不清楚了，判断条件极其复杂，还出错
       */
  
      if (re-rb==1) {
          for (int i = cb; i < ce; ++i) {
              res.push_back(matrix[rb][i]);
          }
          return;
      }
      if (ce-cb==1) {
          for (int i = rb; i < re; ++i) {
              res.push_back(matrix[i][cb]);
          }
          return;
      }
  
      for (int i = cb; i < ce; ++i) {
          res.push_back(matrix[rb][i]);
      }
      //for (int i = rb+1; i < re && (re-1-rb)>1; ++i) {
      for (int i = rb+1; i < re; ++i) {
          res.push_back(matrix[i][ce-1]);
      }
      //for (int i = ce-1-1; i >= cb && (re-1-rb)>1; --i) {
      for (int i = ce-1-1; i >= cb; --i) {
          res.push_back(matrix[re-1][i]);
      }
      //for (int i = re-1-1; i > rb && (ce-1-cb)>1; --i) {
      for (int i = re-1-1; i > rb; --i) {
          res.push_back(matrix[i][cb]);
      }
      rb = rb+1;
      re = re-1;
      cb = cb+1;
      ce = ce-1;
      //if (rb == re-1 || cb == ce -1 || rb >=re || cb >=ce) return;
      if (rb >=re || cb >=ce) return;
      spiral(matrix, rb, re, cb, ce, res);
  }
  
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
      vector<int> res;
      if (matrix.size() == 0) return res;
      spiral(matrix, 0, matrix.size(), 0, matrix[0].size(), res);
      return res;
  
  }
};

int main()
{
    vector<vector<int> > matrix;
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(2);
    //tmp.push_back(3);
    //tmp.push_back(4);
    matrix.push_back(tmp);
    //tmp[0] = 5;
    //tmp[1] = 6;
    //tmp[2] = 7;
    //tmp[3] = 8;
    //matrix.push_back(tmp);
    /*
    tmp[0] = 9;
    tmp[1] = 10;
    tmp[2] = 11;
    tmp[3] = 12;
    matrix.push_back(tmp);
    tmp[0] = 13;
    tmp[1] = 14;
    //tmp[2] = 15;
    //tmp[3] = 16;
    matrix.push_back(tmp);
    */
    vector<int> res  = spiralOrder(matrix);
    for (int i = 0; i < res.size(); ++i)
        cout<<res[i]<<" ";

}




http://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
上面的简单写法，竟然可以这样。。。

#include <stdio.h>
#define R 3
#define C 6

void spiralPrint(int m, int n, int a[R][C])
{
    int i, k = 0, l = 0;

    /*  k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */

    while (k < m && l < n)
    {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i)
        {
            printf("%d ", a[k][i]);
        }
        k++;

        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            printf("%d ", a[i][n-1]);
        }
        n--;

        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                printf("%d ", a[m-1][i]);
            }
            m--;
        }

        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                printf("%d ", a[i][l]);
            }
            l++;    
        }        
    }
}

/* Driver program to test above functions */
int main()
{
    int a[R][C] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };

    spiralPrint(R, C, a);
    return 0;
}

/* OUTPUT:
  1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
*/

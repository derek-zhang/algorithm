Sclass Solution {

public:
   string addBinary(string a, string b) {
      if (a.size() > b.size()) {
         res = a;
      } else {
         res = b;
      }
      int carry = 0;
      int i,j;
      for (i = 0; i < res.size(); i++) {
         char cha = i < a.size()?a[a.size()-1-i]:'0';
         char chb = i < b.size()?b[b.size()-1-i]:'0';
         int tmp = cha-'0'+chb-'0'+carry;
         carry = tmp/2;
         res[res.size()-1-i] = tmp%2 + '0';
      }
      if (carry)
         res = "1" + res;
      return res;
   }
   string res;
};

/*
主要还是要看相加后最多有几位，大数加法，乘法都是要看最后最多有几位
注意对比stringmutiply那题
*/

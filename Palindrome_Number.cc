class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int dev = 1;
        while (x /dev >= 10) {
            dev = dev * 10;
        }
        while (x > 0) {
            int l = x /dev;
            int r = x %10;
            if (l != r) return false;
            x = (x %dev) /10;
            dev = dev /100;
        }
        return true;
    }
};

/*  对10^n取模，是去掉最高位
 *  除以10，是去掉最低位。
 *
 *  除以10^n，是取最高位
 *  对10取模，是取最低位
 */

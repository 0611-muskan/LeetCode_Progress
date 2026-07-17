class Solution {
public:
    bool isPalindrome(int x) {
        int original=x;
        long long rem = 0;;
        if (x < 0)
            return false;
        while(x!=0){
            int rev=x%10;
            rem=rem*10+rev;
            x=x/10;
        }
        return (rem==original);
    }
};
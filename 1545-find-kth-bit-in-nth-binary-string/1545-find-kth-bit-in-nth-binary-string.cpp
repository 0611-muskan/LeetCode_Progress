class Solution {
public:
    string generate(int n){
        if(n==1)
            return "0";
        string prev=generate(n-1);
        string rev=prev;
        reverse(rev.begin(),rev.end());
        for(char &c:rev){
            c=(c=='0')?'1':'0';
        }
        return prev+'1'+rev;
    }
    char findKthBit(int n, int k) {
        string sn=generate(n);
        return sn[k-1];
    }
};
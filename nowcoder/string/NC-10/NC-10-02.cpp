class Solution {
public:
string solve(string s, string t) {
    if (s == "0" || t == "0") return "0";

    int sLen = s.length();
    int tLen = t.length();

    int sStart = 0;
    int tmp[2002] = {0};
    for(int i = tLen-1; i >= 0; i--){
        int tStart = 0;
        for(int j = sLen-1; j >= 0; j--){
            int product = (s[j] - '0') * (t[i] - '0');
            tmp[2001 - sStart - tStart] += product;
            tStart++;
        }
        sStart++;
    }
    return adjustTmpArray(tmp);
}

string adjustTmpArray(int tmp[]){
    string ans;
    for(int i = 2001; i >= 0; ){
       ans += to_string(tmp[i] % 10);
       if (i == 0)
           break;
       else
           tmp[--i] += tmp[i] / 10;
    }
    reverse(ans.begin(),ans.end());
    int k = 0;
    for(; k < 2002; k++){
        if (ans[k] != '0')
            break;
    }
    return ans.substr(k, 2002-k);
}
};


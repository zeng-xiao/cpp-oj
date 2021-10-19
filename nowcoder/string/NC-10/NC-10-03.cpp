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
            tmp[2001 - sStart - tStart - 1] += tmp[2001 - sStart - tStart] / 10;
            tmp[2001 - sStart - tStart] %= 10;
            tStart++;
        }
        sStart++;
    }
    return adjustTmpArray(tmp);
}

string adjustTmpArray(int tmp[]){
    string ans; 
    int k = 0;
    for(; k < 2002; k++){
        if (tmp[k] != 0)
            break;
    }
    for(; k < 2002; k++){
        ans += to_string(tmp[k]);
    }
    return ans;
}
};

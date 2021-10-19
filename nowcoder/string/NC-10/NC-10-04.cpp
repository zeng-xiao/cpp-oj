class Solution {
public:
string solve(string s, string t) {
    if (s == "0" || t == "0") return "0";

    int sLen = s.length();
    int tLen = t.length();

    int index = 0;
    string ans = "";
    int *tmp = (int *)calloc(sLen+tLen, sizeof(int));

    for(int j = sLen-1; j >= 0; j--){
        for(int i = tLen-1; i >= 0; i--){
            int product = (s[j] - '0') * (t[i] - '0');

            tmp[i+j+1] += product;
            tmp[i+j] += tmp[i+j+1] / 10;
            tmp[i+j+1] %= 10;
        }
    }

    if (tmp[0] == 0) index = 1;

    for(; index < sLen+tLen; index++){
        ans += to_string(tmp[index]);
    }
    return ans;
}
};

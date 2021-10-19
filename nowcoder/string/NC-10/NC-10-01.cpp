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
            int currentTmpIndexValue = tmp[2001 - sStart - tStart];
            adjustTmpArray(tmp, product, currentTmpIndexValue, 2001 - sStart - tStart);
            tStart++;
        }
        sStart++;
    }
    return T(tmp);
}

void adjustTmpArray(int tmp[], int product, int currentTmpIndexValue, int index){
    if (product + currentTmpIndexValue < 10) tmp[index] = product + currentTmpIndexValue;
    else {
        tmp[index] = (product + currentTmpIndexValue) % 10;
        index--;
        int productAgain = (product + currentTmpIndexValue) / 10;
        int currentTmpIndexValueAgain = tmp[index];
        adjustTmpArray(tmp, productAgain, currentTmpIndexValueAgain, index);
    }
}

string T(int tmp[]){
    string ans = "";
    int k = 0;
    for(int i = 0; i < 2002; i++) ans += to_string(tmp[i]);
    for(k = 0; k < 2002; k++){
        if (ans[k] != '0')
            break;
    }
    return ans.substr(k, 2002-k);
}
};

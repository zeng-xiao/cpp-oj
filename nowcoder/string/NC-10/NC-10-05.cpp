class Solution {
public:
string solve(string s, string t) {
    if (s == "0" || t == "0") return "0";

    string ans = "";
    vector<int> tmp(s.length()+t.length(), 0);

    for(auto chs = s.rbegin(); chs != s.rend(); chs++){
        for(auto cht = t.rbegin(); cht != t.rend(); cht++){
            int product = (*chs - '0') * (*cht - '0');
            tmp[s.rend()-chs+t.rend()-cht-1] += product;
            tmp[s.rend()-chs+t.rend()-cht-2] += tmp[s.rend()-chs+t.rend()-cht-1] / 10;
            tmp[s.rend()-chs+t.rend()-cht-1] %= 10;
        }
    }

   int index = tmp[0] ? 0 : 1;

    for(auto int2str = tmp.begin() + index; int2str != tmp.end(); int2str++)
        // tmp.begin() + index
        ans += to_string(*int2str);
    return ans;
}
};

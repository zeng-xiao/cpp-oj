#include <iostream>

using namespace std;

int main(){
    string name = "zengxiao";
    int index = 1;
    if (index == 1) name++;
    for (auto ch : name) cout << ch << endl;
    return 0;

}

#include <iostream>

using namespace std;

int lengthOfLastWord(string s) {
    int len = s.length();
    int res = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            continue;
        }
        do {
            res++;
            i--;
        } while (i >= 0 && s[i] != ' ');
        break;
    }
    return res;
}



int main(){
    
    string s = "a";
    int total = lengthOfLastWord(s);
    cout<<total;

    return 0;
}
/*
 Solution to CCC '96 S4 - When in Rome by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int N;
map<char, int> m;
vector< pair<string, string> > replaces;

string intToRoman(int i) {
    
    if (i == 0) {
        return "";
    }
    
    if (i > 1000) {
        return "CONCORDIA CUM VERITATE";
    }
    
    string s;

    int max = 0;
    char c = ' ';
    for (auto val : m) {
        if (i >= val.second && val.second > max) {
            c = val.first;
            max = val.second;
        }
    }
    
    s += c;
    s += intToRoman(i - max);

    return s;
    
}

string simplifyRoman(string s) {
    
    if (s == "CONCORDIA CUM VERITATE") {
        return s;
    }
    
    int it;
    
    for (auto r : replaces) {
        it = (int) s.find(r.first);
        if (it != string::npos) {
            s.replace(it, r.first.length(), r.second);
        }
    }
    
    return s;
}

int romanToInt(string s) {
    
    int n = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (i < s.length() - 1 && m[s[i]] < m[s[i + 1]]) {
            n += m[s[i + 1]] - m[s[i]];
            i++;
        } else {
            n += m[s[i]];
        }
    }
    
    return n;
    
}

int main() {
    
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    
    replaces.push_back({"DCCCC", "CM"});
    replaces.push_back({"CCCC", "CD"});
    replaces.push_back({"LXXXX", "XC"});
    replaces.push_back({"XXXX", "XL"});
    replaces.push_back({"VIIII", "IX"});
    replaces.push_back({"IIII", "IV"});
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    string s, n1, n2;
    int a, b;
    
    while (N--) {
        cin >> s;
        n1 = "";
        n2 = "";
        int i;
        for (i = 0; i < s.length() && s[i] != '+'; i++) {
            n1 += s[i];
        }
        n2 = s.substr(i + 1, s.length() - i - 2);
        a = romanToInt(n1);
        b = romanToInt(n2);
        cout << s << simplifyRoman(intToRoman(a + b)) << "\n";
    }
    
    return 0;
    
}

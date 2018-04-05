/*
 Solution to TLE '16 Contest 7 P1 - Math Helper by Ava Pun
 Key concepts: implementation, simple math
 */

#include <bits/stdc++.h>

using namespace std;

int N;

string deriv(int coeff, int exp, bool variable) {
    
    string s = "y' = ";
    int a = coeff * exp;
    int b = exp - 1;
    
    if (a == 0 || !variable) {
        s += "0";
        return s;
    } else {
        if (b != 0) {
            if (a == -1){
                s += "-";
            } else if (a != 1) {
                s += to_string(a);
            }
        } else {
            s += to_string(a);
        }
    }
    
    if (b == 0) {
        return s;
    } else {
        s += "x";
        if (b != 1) {
            s += "^" + to_string(b);
        }
    }
    
    return s;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin.ignore();
    
    string s;
    while (N--) {
        getline(cin, s);
        s = s.substr(4, s.length() - 4);
        bool variable = false;
        int a = 1, b = 1, i = 0;
        string coeff = "", exp = "";
        while (i < s.length() && s[i] != 'x') {
            coeff += s[i];
            i++;
        }
        if (coeff != "") {
            if (coeff == "-") {
                coeff = "-1";
            }
            a = stoi(coeff);
        }
        if (i < s.length() && s[i] == 'x') {
            variable = true;
        }
        while (i < s.length() && s[i] != '^') {
            i++;
        }
        i++;
        while (i < s.length()) {
            exp += s[i];
            i++;
        }
        if (exp != "") {
            b = stoi(exp);
        }
        cout << deriv(a, b, variable) << "\n";
    }
    
    return 0;
    
}

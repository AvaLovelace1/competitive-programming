/*
 Solution to CCC '15 J2 - Happy or Sad by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    getline(cin, s);
    
    int happy = 0, sad = 0;
    char previous = 0;

    for (char c : s) {
        if (previous == '-') {
            if (c == ')') {
                happy++;
            } else if (c == '(') {
                sad++;
            }
        }
        if (c == ':') {
            previous = c;
        } else if (c == '-' && previous == ':'){
            previous = c;
        } else {
            previous = 0;
        }
    }
    
    if (happy == 0 && sad == 0){
        cout << "none";
    } else if (happy > sad) {
        cout << "happy";
    } else if (sad > happy) {
        cout << "sad";
    } else {
        cout << "unsure";
    }
    
    return 0;
    
}

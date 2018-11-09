/*
 Solution to IOI '18 P1 - Combo by Ava Pun
 Key concepts: ad hoc
 */

#include "combo.h"
#include <bits/stdc++.h>

using namespace std;

std::string guess_sequence(int N) {
    
    string ans = "";
    int a = press("AB"), b = press("AX");
    if (a && b) {
        ans += 'A';
    } else if (a) {
        ans += 'B';
    } else if (b) {
        ans += 'X';
    } else {
        ans += 'Y';
    }
    
    if (N > 1) {
        
        vector<char> buttons = {'A', 'B', 'X', 'Y'};
        buttons.erase(find(buttons.begin(), buttons.end(), ans[0]));
        
        for (int i = 2; i <= N - 1; i++) {
            string guess = "";
            for (char c : buttons) {
                guess += ans + buttons[0] + c;
            }
            guess += ans + buttons[1];
            a = press(guess);
            if (a == i + 1) {
                ans += buttons[0];
            } else if (a == i) {
                ans += buttons[1];
            } else {
                ans += buttons[2];   
            }
        }
        
        if (press(ans + buttons[0]) == N) {
            ans += buttons[0];
        } else if (press(ans + buttons[1]) == N) {
            ans += buttons[1];
        } else{
            ans += buttons[2];
        }
    }
    
    return ans;
}

/*
 Solution to Boolean by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int count = -1;
    string word;
    
    while (word != "True" && word != "False") {
        cin >> word;
        count++;
    }
    
    if ((word == "True" && count % 2 == 0) || (word == "False" && count % 2 == 1)) {
        cout << "True";
    } else {
        cout << "False";
    }
    
    return 0;
    
}

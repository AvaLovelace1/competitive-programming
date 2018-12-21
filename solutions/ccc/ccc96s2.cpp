/*
 Solution to CCC '96 S2 - Divisibility by 11 by Ava Pun
 Key concepts: implementation, simple math
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    string n;
    string s;
    int subtr;
    bool done = true;
    
    for (int i = 1; i <= N; i++) {
        cin >> n;
        s = n;
        cout << s << "\n";
        while (s.length() >= 2) {
            
            if (s.length() > 1) {
                
                subtr = s[s.length() - 1] - '0';
                string tmp = s.substr(0, s.length() - 1);
                done = false;
                int j = (int) tmp.length() - 1;
                while (!done && j >= 0) {
                    if (tmp[j] - subtr < '0'||tmp.length()<2) {
                        tmp[j] += 10;
                        tmp[j] -= subtr;
                        j--;
                        subtr = 1;
                    } else {
                        tmp[j] -= subtr;
                        done = true;
                    }
                }
                
                if (!done) {
                    break;
                } else {
                    s = tmp;
                }
            }
            
            if (s[0] == '0' && s != "0") {
                s = s.substr(1, s.length() - 1);
            }
            
            if (s != "0") {
                cout << s << "\n";
            }
        }
        
        if (stoi(s) % 11 == 0) {
            cout << "The number " << n << " is divisible by 11." << "\n";
        } else {
            cout << "The number " << n << " is not divisible by 11." << "\n";
        }

        cout << "\n";
        
    }
    
    return 0;
    
}

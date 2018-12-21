/*
 Solution to CCC '97 S1 - Sentences by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int N, S, V, O;
string subj[20], verb[20], obj[20];

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    string s;
    
    while (N--) {
        cin >> S >> V >> O;
        cin.ignore();
        
        for (int i = 0; i < S; i++) {
            getline(cin, s);
            subj[i] = s;
        }
        for (int i = 0; i < V; i++) {
            getline(cin, s);
            verb[i] = s;
        }
        for (int i = 0; i < O; i++) {
            getline(cin, s);
            obj[i] = s;
        }
        
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < V; j++) {
                for (int k = 0; k < O; k++) {
                    cout << subj[i] << " " << verb[j] << " " << obj[k] << ".\n";
                }
            }
        }
        
        cout << "\n";
    }
    
}

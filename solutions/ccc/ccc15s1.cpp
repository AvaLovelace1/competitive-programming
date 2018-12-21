/*
 Solution to CCC '15 S1 - Zero That Out by Ava Pun
 Key concepts: implementation, stacks
 */

#include <bits/stdc++.h>

using namespace std;

int K;

int main() {

    scanf("%d", &K);
    stack<int> s;
    int n;
    while (K--) {
        scanf("%d", &n);
        if (n == 0) {
            s.pop();
        } else {
            s.push(n);
        }
    }
    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    printf("%d", sum);
    
    return 0;
    
}

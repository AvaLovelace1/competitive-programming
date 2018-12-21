/*
 Solution to CCC '14 S3 - The Geneva Confection by Ava Pun
 Key concepts: implementation, stacks
 */
 
 #include <bits/stdc++.h>

using namespace std;

int T, N;

int main() {

    scanf("%d", &T);
    stack<int> m, b;
    int num;
    while (T--) {
        scanf("%d", &N);
        while (N--) {
            scanf("%d", &num);
            m.push(num);
        }
        int curr = 1;
        bool moved;
        while (!m.empty() || !b.empty()) {
            moved = false;
            if (!m.empty() && m.top() == curr) {
                m.pop();
                curr++;
                moved = true;
            }
            if (!b.empty() && b.top() == curr) {
                b.pop();
                curr++;
                moved = true;
            }
            if (!moved && !m.empty()) {
                b.push(m.top());
                m.pop();
            }
            if (m.empty() && !b.empty() && b.top() != curr) {
                break;
            }
        }
        printf((m.empty() && b.empty()) ? "Y\n" : "N\n");
        while (!m.empty()) {
            m.pop();
        }
        while (!b.empty()) {
            b.pop();
        }
    }
    
    return 0;
    
}

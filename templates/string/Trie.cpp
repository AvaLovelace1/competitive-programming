/*
 ~ Trie Data Structure ~
 
 Data structure for storing a set of strings.
 Can also be used to query prefixes.
 Can be implemented as an array or using pointers.
 
 Time complexity:
    Insert - O(|S|)
    Search - O(|S|)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e4 + 5;

int Q;
int trie[MAX][26];
bool isWord[MAX];
int cnt = 1;

void insert(string s) {
    int n = 0;
    for (char c : s) {
        if (trie[n][c - 'a'] == 0) {
            trie[n][c - 'a'] = cnt;
            cnt++;
        }
        n = trie[n][c - 'a'];
    }
    isWord[n] = true;
}

bool contains(string s) {
    int n = 0;
    for (char c : s) {
        if (trie[n][c - 'a'] == 0) {
            return false;
        }
        n = trie[n][c - 'a'];
    }
    return isWord[n];
}

struct node {
    bool isWord = false;
    map<char, node*> child;
};

node *root = new node;

void insertPtr(string s) {
    node *n = root;
    for (char c : s) {
        if (n->child.find(c) == n->child.end()) {
            n->child[c] = new node;
        }
        n = n->child[c];
    }
    n->isWord = true;
}

bool containsPtr(string s) {
    node *n = root;
    for (char c : s) {
        if (n->child.find(c) == n->child.end()) {
            return false;
        }
        n = n->child[c];
    }
    return n->isWord;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> Q;
    char c;
    string s;
    while (Q--) {
        cin.ignore();
        cin >> c >> s;
        if (c == 'U') {
            insert(s);
            insertPtr(s);
        } else if (c == 'Q') {
            cout << "With array: " << (contains(s) ? s + " is in the dictionary.\n" : s + " is not in the dictionary.\n");
            cout << "With pointers: " << (containsPtr(s) ? s + " is in the dictionary.\n" : s + " is not in the dictionary.\n");
        }
    }
    
    return 0;
    
}


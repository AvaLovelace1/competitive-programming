/*
 Solution to CCC '05 J5 - Bananas by Ava Pun
 Key concepts: recursion
 */

#include <bits/stdc++.h>

using namespace std;

bool isMonkeyWord(string word, vector<string> validWords) {
    
    bool isWord = false;
    
    if (find(validWords.begin(), validWords.end(), word) != validWords.end()) {
        isWord = true;
    } else if (word == "A"){
        isWord = true;
    } else if (word[0] == 'B' && word[word.length() - 1] == 'S' && word.substr(1, word.length() - 2) != "" && isMonkeyWord(word.substr(1, word.length() - 2), validWords)) {
        isWord = true;
    }
    
    for (unsigned int i = 1; i < word.length() - 1 && !isWord; i++) {
        if (word[i] == 'N' && isMonkeyWord(word.substr(0, i), validWords) && isMonkeyWord(word.substr(i + 1, word.length() - 1), validWords)) {
            isWord = true;
        }
    }
    
    if (isWord) {
        validWords.push_back(word);
    }
    return isWord;
}

bool isMonkeyWord(string word) {
    vector<string> validWords;
    return isMonkeyWord(word, validWords);
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string word;
    getline(cin, word);
    
    while (word != "X") {
        
        if (isMonkeyWord(word)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
        getline(cin, word);
    }
    
    return 0;
    
}

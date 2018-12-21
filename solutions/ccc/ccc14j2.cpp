/*
 Solution to CCC '14 J2 - Vote Count by Ava Pun
 Key concepts: implementation
 */
 
 #include <bits/stdc++.h>

using namespace std;
int main() {
    
    int nVotes;
    scanf("%d", &nVotes);
    
    char vote;
    int nAVotes = 0, nBVotes = 0;
    
    for (int i = 1; i <= nVotes; i++) {
        scanf(" %c", &vote);
        if (vote == 'A') {
            nAVotes++;
        } else {
            nBVotes++;
        }
    }
    
    if (nAVotes > nBVotes) {
        printf("A");
    } else if (nBVotes > nAVotes) {
        printf("B");
    } else {
        printf("Tie");
    }
    
    return 0;
    
}

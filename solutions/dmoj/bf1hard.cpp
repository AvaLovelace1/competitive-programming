/*
 Solution to List Minimum (Hard) by Ava Pun
 Key concepts: sorting, implementation
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int size;
    scanf("%d", &size);
    
    int nums[size];
    
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    sort(nums, nums + size);
    
    for (int n : nums) {
        printf("%d\n", n);
    }
}

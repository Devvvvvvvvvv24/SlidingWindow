#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string s = "abcabcbb";
    int n = s.length();

    int i = 0, j = 0;
    int maxLen = 0;
    unordered_map<char, int> mp;

    while(j < n){
        mp[s[j]]++;

        // If character is repeating, shrink window from left
        while(mp[s[j]] > 1){
            mp[s[i]]--;
            i++;
        }

        // Update max length
        maxLen = max(maxLen, j - i + 1);

        j++;
    }

    cout << maxLen << endl;
    return 0;
}

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string toys = "abaccab";
    int i = 0, j = 0;
    int maxLen = 0;
    unordered_map<char, int> mp;

    while(j < toys.length()){
        mp[toys[j]]++;

        // If we have more than 2 types, shrink the window
        while(mp.size() > 2){
            mp[toys[i]]--;
            if(mp[toys[i]] == 0){
                mp.erase(toys[i]);
            }
            i++;
        }

        // Update max length if current window is valid
        maxLen = max(maxLen, j - i + 1);
        j++;
    }

    cout << maxLen << endl;
    return 0;
}
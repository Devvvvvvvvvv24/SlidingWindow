#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string s = "aabbaccc";
    int k = 2; // number of unique characters required

    int i = 0, j = 0;
    int maxLen = 0;
    unordered_map<char, int> mp;

    while(j < s.length()){
        mp[s[j]]++;

        // If map size > k, shrink from left
        while(mp.size() > k){
            mp[s[i]]--;
            if(mp[s[i]] == 0){
                mp.erase(s[i]);
            }
            i++;
        }

        // If exactly k unique characters
        if(mp.size() == k){
            maxLen = max(maxLen, j - i + 1);
        }

        j++;
    }

    cout << maxLen << endl;
    return 0;
}

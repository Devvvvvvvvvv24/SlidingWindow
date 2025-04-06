#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";

    unordered_map<char, int> mp;
    for(char c : t) mp[c]++;

    int i = 0, j = 0;
    int count = mp.size(); // total unique characters needed
    int minLen = INT_MAX;
    int start = 0;

    while(j < s.length()){
        // Decrease freq if character is in t
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if(mp[s[j]] == 0) count--;
        }

        // When all characters matched
        while(count == 0){
            // Update min window
            if(j - i + 1 < minLen){
                minLen = j - i + 1;
                start = i;
            }

            // Try to shrink from left
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]]++;
                if(mp[s[i]] > 0) count++;
            }
            i++;
        }

        j++;
    }

    if(minLen == INT_MAX)
        cout << "" << endl;
    else {
        for(int k = start; k < start + minLen; k++){
            cout << s[k];
        }
        cout << endl;
    }

    return 0;
}

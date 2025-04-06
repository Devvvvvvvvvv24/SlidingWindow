#include<iostream>
#include<map>
using namespace std;

int main(){
    string s1 = "aabaabaa";
    string s2 = "aaba";
    int n = s1.length();
    int k = s2.length();
    
    map<char, int> mp;
    for(char ch : s2){
        mp[ch]++;
    }
    
    int count = mp.size(); // Number of unique characters to match
    int ans = 0;
    int i = 0, j = 0;

    while(j < n){
        // Process current character
        if(mp.find(s1[j]) != mp.end()){
            mp[s1[j]]--;
            if(mp[s1[j]] == 0){
                count--;
            }
        }

        // Window size < k, just expand
        if(j - i + 1 < k){
            j++;
        }

        // Window size == k
        else if(j - i + 1 == k){
            if(count == 0){
                ans++; // Valid anagram found
            }

            // Before sliding window, restore i-th element
            if(mp.find(s1[i]) != mp.end()){
                if(mp[s1[i]] == 0){
                    count++;
                }
                mp[s1[i]]++;
            }

            i++;
            j++;
        }
    }

    cout << ans;
    return 0;
}

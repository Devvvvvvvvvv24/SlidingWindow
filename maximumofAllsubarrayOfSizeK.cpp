#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main(){
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    vector<int> v;
    deque<int> dq; // stores indices of maximums

    int i = 0, j = 0;

    while(j < n){
        // Remove elements smaller than the current from the back
        while(!dq.empty() && arr[dq.back()] < arr[j]){
            dq.pop_back();
        }
        dq.push_back(j); // store index

        // Expand window
        if(j - i + 1 < k){
            j++;
        }
        // When window size == k
        else if(j - i + 1 == k){
            v.push_back(arr[dq.front()]); // element at front is the maximum

            // Remove the element going out of the window
            if(dq.front() == i){
                dq.pop_front();
            }
            i++;
            j++;
        }
    }

    // Print result
    for(int x : v){
        cout << x << " ";
    }

    return 0;
}

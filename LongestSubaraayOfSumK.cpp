#include<iostream>
using namespace std;

int main(){
    int arr[] = {4, 1, 1, 1, 2, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 5; // Target sum
    int sum = 0;
    int mx = 0; // To store max length of subarray with sum = k

    int i = 0, j = 0;

    while(j < n){
        sum += arr[j];

        // Shrink the window from left while sum > k
        while(sum > k && i <= j){
            sum -= arr[i];
            i++;
        }

        // If sum equals k, update maximum length
        if(sum == k){
            mx = max(mx, j - i + 1);
        }

        j++;
    }

    cout << mx << endl;
    return 0;
}

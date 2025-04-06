#include<iostream>
using namespace std;

int main(){
    int arr[] = {2, 5, 1, 8, 2, 9, 1};
    int i = 0, j = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    int k = 3;
    int mx = INT_MIN; // <-- Change this from 0 to INT_MIN to handle negative numbers too

    while(j < n){
        sum += arr[j];
        if(j - i + 1 < k)
            j++;
        else if(j - i + 1 == k){
            mx = max(mx, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    cout << mx;
}

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int arr[]={12,-1,-7,8,-15,30,16,28};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3; // Window size

    vector<int> v;
    queue<int> q;
    int i=0, j=0;
    
    while(j<n){
        // If current element is negative, push to queue
        if(arr[j] < 0) q.push(arr[j]);
        
        // Expand the window
        if(j-i+1 < k) {
            j++;
        } else if(j-i+1 == k){
            // If queue is empty, push 0 (no negative number in window)
            if(q.empty()) {
                v.push_back(0);
            } else {
                v.push_back(q.front());
                // Remove the element going out of the window
                if(arr[i] == q.front()) {
                    q.pop();
                }
            }
            i++; // Slide window forward
            j++;
        }
    }
    
    // Printing the result
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}
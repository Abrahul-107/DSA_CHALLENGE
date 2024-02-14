/*Time complexity = 0(NLogN)
  Space complexity = 0(1)*/
  
#include<bits/stdc++.h>
using namespace std;


bool twoSumWithouSpace(vector<int> &arr, int sum) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    
    while (left < right) {
        int check = arr[left] + arr[right];
        
        if (check == sum) {
            return true;
        } else if (check < sum) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 1};
    
    if (twoSumWithouSpace(arr, 5)) {
        cout << "Sum exists";
    } else {
        cout << "Does not exist in this array";
    }

    return 0;
}

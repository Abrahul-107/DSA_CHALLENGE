#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    vector<int>ans;

    int i=0,j=0;

    while (i<m and j<n)
    {   
        if(nums1[i]<nums2[j])
            ans.push_back(nums1[i++]);
        else
            ans.push_back(nums2[j++]);

    }
    while(i<m)
        ans.push_back(nums1[i++]);
    while(j<n)
        ans.push_back(nums2[j++]);
    nums1 = ans;
    
}


int main()
{
    int m = 4, n = 6;
	vector<int> v1 = {1, 5, 5, 10, 0, 0, 0, 0, 0, 0};
	vector<int> v2 = {2, 3, 6, 6, 6, 9};

	merge(v1, m, v2, n);
	
	for(int num : v1)
		cout << num << ' ';
	return 0;
}
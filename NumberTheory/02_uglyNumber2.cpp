#include<bits/stdc++.h>
using namespace std;

int uglyNumber2(int n)
{
	if(n<=0)
		return 0;
	if(n==1)
		return 1; 

	vector<int>arr(n);
	int p2=0,p3=0,p5=0;
	arr[0]=1;//First ugly number 
	
	for(int i=1;i<n;i++)
	{
		arr[i] = min(arr[p2]*2,min(arr[p3]*3,arr[p5]*5));
		if(arr[i] == arr[p2]*2) p2++;
        if(arr[i] == arr[p3]*3) p3++;
        if(arr[i] == arr[p5]*5) p5++;

	}
	
	return arr[n-1];
}

int main()
{
	int n;
	cin>>n;
	int  ans = uglyNumber2(10);
	cout<<ans<<endl;

	return 0;

}

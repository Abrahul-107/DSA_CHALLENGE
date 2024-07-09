//https://leetcode.com/problems/average-waiting-time/description




#include<bits/stdc++.h>
using namespace std;

double averageWaitingTime(vector<vector<int>>&arr)
{
	int n = arr.size();
	double averageWaiting = 0;
	int currTime = 0;

	for(auto &vec:arr)
	{
		int arrivalTime = vec[0];
		int cookingTime = vec[1];
		
		if(currTime<arrivalTime)
			currTime = arrivalTime;
		int waitingTime = currTime - arrivalTime + cookingTime;
		averageWaiting += waitingTime;
		currTime += cookingTime;
	}
	
	return averageWaiting/n;



}


int main()
{
	vector<vector<int>>arr = {{1,2},{2,5},{4,3}};
	double ans = averageWaitingTime(arr);
	cout<<ans<<endl;

	return 0;

}

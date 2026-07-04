#include<iostream>
#include<vector>

using namespace std;

int maxAreaCake(int h,int v,vector<int>&horizantalCuts,vector<int>&verticalCuts)
{
    int MOD = 1e9 + 7;

    sort(verticalCuts.begin(),verticalCuts.end());
    sort(horizantalCuts.begin(),horizantalCuts.end());

    int  hSize = horizantalCuts.size();
    int  vSize = verticalCuts.size();

    long long maxH = max(horizantalCuts[0],h-horizantalCuts.back());
    long long maxV = max(verticalCuts[0],v-verticalCuts.back());

    for(int i=1;i<hSize;++i)
        maxH = max(maxH,(long long) horizantalCuts[i]-horizantalCuts[i-1]);
    for(int i=1;i<vSize;++i)
        maxV = max(maxV,(long long) verticalCuts[i]-verticalCuts[i-1]);
    
    return maxH*maxV % MOD;

}


int main()
{
    int h = 5;
    int w = 4;

    vector<int>horizantalCuts = {1,2,4};
    vector<int>verticalCuts = {1,3};
    cout<<maxAreaCake(h,w,horizantalCuts,verticalCuts);


    return 0;
}



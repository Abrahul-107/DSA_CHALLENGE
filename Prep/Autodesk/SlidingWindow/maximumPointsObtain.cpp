#include<iostream>
#include<vector>
#include<numeric>

using  namespace std;

int maxPointObtain(vector<int>&cardPoints,int k)
{
    int totalSum = accumulate(cardPoints.begin(),cardPoints.end(),0);

    int size = cardPoints.size();
    int windowSize = size-k;

    //The intution is find the min subarray sum in the window size and substract 
    //that from the total sum for getting maxPoint 
    int firstWindowSum = 0;
    for(int i=0;i<windowSize;++i)
        firstWindowSum += cardPoints[i];
    
    /*Now i have to add after windowSize and remove from the left

    Pick from ends        Leave in middle
    [1 2 3 4] 5 6 1   <-- leave first 4
    1 [2 3 4 5] 6 1
    1 2 [3 4 5 6] 1
    1 2 3 [4 5 6 1]
    */

    int windowMinSum = firstWindowSum;
    for(int i=windowSize;i<size;++i)
    {
        firstWindowSum += cardPoints[i];
        firstWindowSum -= cardPoints[i-windowSize];
        windowMinSum = min(windowMinSum,firstWindowSum);
    }
    return totalSum - windowMinSum;
    
}

int main()
{
    vector<int>cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    cout<<maxPointObtain(cardPoints,k);

    return 0;
}
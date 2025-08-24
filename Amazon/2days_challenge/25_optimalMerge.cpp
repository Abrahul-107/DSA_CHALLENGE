#include<iostream>
using namespace std;


int minComputation(vector<int>arr)
{
    priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());

    //For debugging purpose
    priority_queue<int,vector<int>,greater<int>>forprint;

    int cost = 0;
    while(pq.size()>1)
    {
        int file1 = pq.top();pq.pop();
        int file2 = pq.top();pq.pop();

        int mergeCost = file1+file2;
        cost+=mergeCost;
        pq.push(mergeCost);

        /*
        For debugging purpose
        forprint = pq;
        while (!forprint.empty())
        {
            cout<<forprint.top()<<" ";
            forprint.pop();
        }
        cout<<endl;
        */
    }
    return cost; 
}
int main()
{
    vector<int>arr = {2 ,3 ,4, 5, 6, 7};
    cout<<minComputation(arr);
    return 0;

}
#include<iostream>
#include<vector>

using namespace std;

bool searchInMatrix(vector<vector<int>>&matrix,int target)
{
    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    int start = 0;
    int end = rowSize*colSize - 1;
    while(start<=end)
    {
        int mid = (start + end)/2;
        int rowPos = mid / colSize;
        int colPos = mid % colSize;
        if(matrix[rowPos][colPos]==target)
            return true;
        else if(matrix[rowPos][colPos]<target)
        {
            start =  mid+1;
        }
        else    
            end = mid -1;
    }
    return false;
}

int main()
{
    vector<vector<int>>matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3666;
    cout<<searchInMatrix(matrix,target);


    return 0;
}
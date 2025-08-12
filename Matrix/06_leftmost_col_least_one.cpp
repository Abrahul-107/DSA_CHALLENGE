#include<iostream>
using namespace std;

class BinaryMatrix
{
    private:
    vector<vector<int>>matrix;
    public:
    BinaryMatrix(vector<vector<int>>mat): matrix(mat){}

    int get(int i,int j)
    {
        return matrix[i][j];
    }
    vector<int>dimensions()
    {
        return { (int)matrix.size(), (int)matrix[0].size() };
    }
};


int leftMostColWithLeastOne(BinaryMatrix&bm)
{
    vector<int>rowColSize = bm.dimensions();
    int rowSize = rowColSize[0];
    int colSize = rowColSize[1];

    int row = 0;
    int leftMost= -1;
    int col = colSize -1;

    while(row<rowSize && col>=0)
    {
        if(bm.get(row,col)==1)
        {
            leftMost = col;
            //Move left (Col wise)
            col--;
        }
        else{
            //Mode down (row wise)
            row++;
        }
    }
    return leftMost;
}



int main()
{
    vector<vector<int>> mat = {
        {0, 0, 0, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1}
    };

    BinaryMatrix bm(mat);
    cout<<leftMostColWithLeastOne(bm);
    return 0;

}
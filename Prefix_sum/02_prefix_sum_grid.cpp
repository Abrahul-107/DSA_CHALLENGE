#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;

    int grid[n + 1][m + 1] = {0}, prefix[n + 1][m + 1] = {0};

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>grid[i][j];
            prefix[i][j] = grid[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    int q;cin>>q;
    while(q--)
    {
        int from_row,from_col,to_row,to_col;
        cin>>from_row>>from_col>>to_row>>to_col;

        cout<<prefix[to_row ][to_col] - prefix[from_row-1][to_col] - prefix[to_row][from_col-1] + prefix[from_row-1][from_col-1];
    }

    return 0;
}
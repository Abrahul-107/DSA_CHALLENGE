#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreateElement(vector<int> arr)
{
    int n = arr.size();
    vector<int> v(n);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {

        while (!st.empty() && arr[i % n] >= st.top())
            st.pop();
        if (st.empty())
            v[i % n] = -1;
        else
            v[i % n] = st.top();
        st.push(arr[i % n]);
    }

    return v;
}

int main()
{
    vector<int> v = {4, 2, 3, 7, 17, 5, 8};
    vector<int> ans = nextGreateElement(v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
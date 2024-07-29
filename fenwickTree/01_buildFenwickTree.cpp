#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Retrieves the sum of the first 'index' elements in the Fenwick Tree.
 *
 * This function uses a Fenwick Tree (also known as Binary Indexed Tree)
 * to efficiently calculate prefix sums.
 *
 * @param index The position up to which the sum is calculated (1-based index).
 * @param fenwick The Fenwick Tree represented as a vector of integers.
 * @return The sum of elements from the start up to the 'index'.
 */
int getSum(int index, vector<int> &fenwick)
{
    int runningSum = 0;
    for (; index > 0; index -= (index & -index))
    {
        runningSum += fenwick[index];
    }
    return runningSum;
}

/**
 * @brief Updates the Fenwick Tree by adding a value to a specific index.
 *
 * This function adds the value 'x' to the 'index'-th element in the Fenwick Tree
 * and updates all affected elements. The Fenwick Tree helps in maintaining
 * prefix sums efficiently.
 *
 * @param index The position to be updated (1-based index).
 * @param x The value to be added to the 'index'-th element.
 * @param fenwick The Fenwick Tree represented as a vector of integers.
 */
void update(int index, int x, vector<int> &fenwick)
{
    int size = fenwick.size();
    for (; index < size; index += (index & -index))
    {
        fenwick[index] += x;
    }
}

/**
 * @brief Computes the sum of elements within a range [l, r] in the Fenwick Tree.
 *
 * This function calculates the sum of elements from the l-th to the r-th
 * element (both inclusive) in the Fenwick Tree.
 *
 * @param l The left boundary of the range (1-based index).
 * @param r The right boundary of the range (1-based index).
 * @param fenwick The Fenwick Tree represented as a vector of integers.
 * @return The sum of elements within the range [l, r].
 */
int rangeQuery(int l, int r, vector<int> &fenwick)
{
    return getSum(r, fenwick) - getSum(l - 1, fenwick);
}

int main()
{
    int n = 5; // Number of elements in the array

    // 1-based indexing array
    vector<int> arr{-1000000000, 1, 2, 3, 4, 5};

    // Initially, all the values of the Fenwick Tree are 0
    vector<int> fenwick(n + 1, 0);

    // Build the Fenwick Tree with the given array values
    for (int i = 1; i <= n; i++)
    {
        update(i, arr[i], fenwick);
    }

    // Perform range queries
    cout << "Sum of elements from index 1 to 4: " << rangeQuery(1, 4, fenwick) << endl;
    cout << "Sum of elements from index 2 to 4: " << rangeQuery(2, 4, fenwick) << endl;

    return 0;
}

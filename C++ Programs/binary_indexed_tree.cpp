/**
 * This program is used to solve https://dmoj.ca/problem/ds1
 * It uses a Binary Indexed Tree, a data structure which takes O(log N) time to update and O(log N) time
 * to get the sum of a range of elements
 * Arrays take O(1) time to update and O(N) time to make a range sum query
 * Prefix sum arrays take O(N) time to update and O(1) time to make a range sum query
 * So a Binary Indexed Tree is good for when we need to do both a large number of times
 */

#include <iostream>
#define MAXN 100005
using namespace std;
typedef long long ll;

ll N, M, x[MAXN], bit[MAXN], freq[MAXN];

// adds `val` to the element at index `i`
void update(ll bit[], int i, int val)
{
    while (i <= MAXN)
    {
        bit[i] += val;
        i += (i&-i);
    }
}

// gets the sum of the elements up to and including index i
ll query(ll bit[], int i)
{
    ll ans = 0;
    while (i > 0)
    {
        ans += bit[i];
        i -= (i&-i);
    }
    return ans;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> x[i];
        update(bit, i, x[i]);
        update(freq, x[i], 1);
    }

    char c;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> c;
        if (c == 'C')
        {
            // we change the a-th element of the BIT to the value b
            cin >> a >> b;
            update(bit, a, b-x[a]);
            update(freq, x[a], -1);
            update(freq, b, 1);
            x[a] = b;
        }
        else if (c == 'S')
        {
            // gets the sum of the elements from a to b inclusive
            cin >> a >> b;
            cout << query(bit, b) - query(bit, a-1) << '\n';
        }
        else if (c == 'Q')
        {
            // the number of elements less than or equal to a
            cin >> a;
            cout << query(freq, a) << '\n';
        }
    }

    return 0;
}

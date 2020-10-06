#include <bits/stdc++.h>
using namespace std;

// building the segment tree in the array segTree
void build(int s, int e, int i, vector<int>& segTree, vector<int>& array)
{
	if(s == e)
	{
		segTree[i] = array[s];
		return;
	}
	int mid = (s + e) / 2;
	build(s, mid, (i<<1), segTree, array);
	build(mid + 1, e, (i<<1) + 1, segTree, array);
	segTree[i] = max(segTree[(i<<1)], segTree[(i<<1) + 1]);
	return;
}

// query for getting maximum element in array from l to r (0-based indexing)
// indexing of the segment tree is 1-based
int query(int s, int e, int i, int l, int r, vector<int>& segTree)
{
	if(s > r || e < l)
		return INT_MIN;
	if(s >= l && e <= r)
		return segTree[i];
	int mid = (s + e) / 2;
	int q1 = query(s, mid, (i<<1), l, r, segTree);
	int q2 = query(mid + 1, e, (i<<1) + 1, l, r, segTree);
	return max(q1, q2);
}

int main()
{
	int n;
	cout<<"Enter the count of numbers in the array: ";
	cin>>n;

	vector<int> array;
	int i;
	cout<<"Enter n space separated numbers of the array\n";
	for(i = 0; i < n; ++i)
	{
		int val;
		cin>>val;
		array.push_back(val);
	}
	vector<int> segTree(4*n + 5, 0);
	build(0, n - 1, 1, segTree, array);

	int q;
	cout<<"Enter the number of queries you want to ask: ";
	cin >> q;

	while(q--)
	{
		int l, r;
		cout<<"Enter the space separated range of indices (1-based indexing)\n";
		cin >> l >> r;
		int ans = query(0, n - 1, 1, l - 1, r - 1, segTree);
		cout<<"Maximum value in the range of " << l << " to " << r << " is " << ans << endl;
	}
	return 0;
}

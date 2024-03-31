#include <bits/stdc++.h>

class SegmentTree
{
    vector<int> seg;

public:
    SegmentTree()
    {
        seg = {};
    }

    SegmentTree(int size)
    {
        seg.resize(2 * size + 1);
    }

    void build(int idx, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    void update(int idx, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);
        else
            update(2 * idx + 2, mid + 1, high, i, val);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r)
    {
        if (r < low || high < l)
        {
            return INT_MAX;
        }

        if (l <= low && high <= r)
        {
            return seg[idx];
        }

        int mid = low + (high - low) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return min(left, right);
    }
}

int
main()
{
    return 0;
}
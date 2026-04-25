#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> data;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            data[idx] = val;
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }

public:
    SegmentTree(const vector<int>& arr) {
        data = arr;
        n = arr.size();
        if (n > 0) {
            tree.assign(4 * n, 0);
            build(1, 0, n - 1);
        }
    }

    void update(int idx, int val) {
        if (n > 0) {
            update(1, 0, n - 1, idx, val);
        }
    }

    int query(int l, int r) {
        if (n == 0) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    cout << st.query(1, 3) << "\n";

    st.update(1, 10);

    cout << st.query(1, 3) << "\n";

    return 0;
}
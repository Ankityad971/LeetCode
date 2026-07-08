class Solution {
public:
    const int MOD = 1e9 + 7;

    struct Node {
        long long num;
        int sum;
        int cnt;
    };

    vector<Node> tree;
    vector<long long> pw;
    string s;

    Node merge(Node a, Node b) {
        Node res;
        res.cnt = a.cnt + b.cnt;
        res.sum = a.sum + b.sum;
        res.num = (a.num * pw[b.cnt] + b.num) % MOD;
        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            if (s[l] == '0') {
                tree[node] = {0, 0, 0};
            } else {
                int d = s[l] - '0';
                tree[node] = {d, d, 1};
            }
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (l == ql && r == qr)
            return tree[node];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(
            query(node * 2, l, mid, ql, mid),
            query(node * 2 + 1, mid + 1, r, mid + 1, qr)
        );
    }

    vector<int> sumAndMultiply(string str, vector<vector<int>>& queries) {
        s = str;
        int n = s.size();

        pw.resize(n + 1);
        pw[0] = 1;
        for (int i = 1; i <= n; i++)
            pw[i] = (pw[i - 1] * 10) % MOD;

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {
            Node cur = query(1, 0, n - 1, q[0], q[1]);
            ans.push_back((cur.num * cur.sum) % MOD);
        }

        return ans;
    }
};
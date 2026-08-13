class Solution {
public:
    struct Node {
        int pref, suff, best, len;
        char leftChar, rightChar;

        Node() {
            pref = suff = best = len = 0;
            leftChar = rightChar = '#';
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        res.suff = b.suff;
        res.best = max(a.best, b.best);

        // If the boundary characters are same,
        // suffix of left + prefix of right can form one segment.
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suff + b.pref);

            if (a.pref == a.len)
                res.pref = a.len + b.pref;

            if (b.suff == b.len)
                res.suff = b.len + a.suff;
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {
        if (l == r) {
            tree[node].len = 1;
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].best = 1;
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node].leftChar = c;
            tree[node].rightChar = c;
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].best = 1;
            tree[node].len = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};
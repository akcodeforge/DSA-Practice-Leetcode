#define ll long long
class Solution {
public:

    struct Node {
        int prod;
        ll cnt[5];

        Node() {
            prod = 1;
            for(int i = 0; i < 5; i++) {
                cnt[i] = 0;
            }
        }
    };

    int n, k;
    int size;
    vector<Node> num;

    Node mergeNode(const Node& a, const Node& b) {
        Node r;

        r.prod = (1LL * a.prod * b.prod) % k;

        for(int i = 0; i < k; i++) {
            r.cnt[i] = a.cnt[i];
        }

        for(int i = 0; i < k; i++) {
            if(b.cnt[i] == 0) continue;

            int x = (1LL * a.prod * i) % k;
            r.cnt[x] += b.cnt[i];
        }

        return r;
    }

    void update(int p, int val) {
        p += size;

     num[p] = Node();

        val %= k;

     num[p].prod = val;
     num[p].cnt[val] = 1;

        p >>= 1;

        while(p) {
         num[p] = mergeNode (num[p << 1], num[p << 1 | 1]);
            p >>= 1;
        }
    }

    Node query(int l, int r) {
        Node a, b;

        l += size;
        r += size;

        while(l < r) {
            if(l & 1) {
                a = mergeNode(a, num[l]);
                l++;
            }

            if(r & 1) {
                r--;
                b = mergeNode (num[r], b);
            }

            l >>= 1;
            r >>= 1;
        }

        return mergeNode(a, b);
    }

    vector<int> resultArray(vector<int>& nums, int K, vector<vector<int>>& queries) {

        n = nums.size();
        k = K;

        size = 1;

        while(size < n) {
            size <<= 1;
        }

     num.resize(2 * size);

        for(int i = 0; i < n; i++) {
            int x = nums[i] % k;

         num[size + i].prod = x;
         num[size + i].cnt[x] = 1;
        }

        for(int i = size - 1; i >= 1; i--) {
         num[i] = mergeNode (num[i << 1], num[i << 1 | 1]);
        }

        vector<int> ans;

        for(auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(index, value);

            Node r = query(start, n);

            ans.push_back(r.cnt[x]);
        }

        return ans;

        
    }
};
#include <bits/stdc++.h>

using namespace std;

#define ft first
#define sd second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define boost ios_base::sync_with_stdio(false), cin.tie(NULL)
#define inp freopen("code.in", "r+", stdin)
#define out freopen("code.out", "w+", stdout)
#define debug(x) cout << "DEBUG: " << x << endl

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long int ll;

#define maxn (int)1e5

int bit[maxn];

void update(int id)
{
    for (int i = id; i <= maxn; i += (i & (-i)))
        bit[i]++;  
}

int get(int id)
{
    int ans = 0;
    for (int i = id; i > 0; i -= (i & (-i)))   
        ans += bit[i];
    return ans;
}

int main()
{
    //inp;
    int n, x, cnt;
    while (scanf("%d", &n), n) {
        cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            update(x);
            cnt += get(n) - get(x);
        }
        if (cnt & 1 and cnt != 1)
            printf("Marcelo\n");
        else
            printf("Carlos\n");
        memset(bit, 0, sizeof bit);
    }
}

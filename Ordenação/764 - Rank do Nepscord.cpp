
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

bool mycomparator(pair<string, int> a, pair<string, int> b)
{
    if (a.sd > b.sd)
        return 1;
    else if (a.sd == b.sd)
        return a.ft > b.ft ? 0 : 1;
    else
        return 0;
}

int main()
{
    //inp;
    int n, k, x;
    string user;
    unordered_map<string, int> reg, xp;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        cin >> user >> x;
        if (!xp[user]) {
            xp[user] += 25;
            reg[user] = x;
            continue;
        }
        if (x - reg[user] >= k)
            xp[user] += 25, reg[user] = x;
    }
    vector<pair<string, int>> win;
    for (auto i : xp)
        win.push_back({i.ft, i.sd});
    sort(all(win), mycomparator);
    cout << "--Rank do Nepscord--" << endl;
    int cnt = 0;
    while (sz(win) <= 3)
        win.push_back({"", -1});
    for (int i = 0; i < 3; i++) {
        if (win[i].ft == "")
            cout << "#" << ++cnt << "." << endl;
        else
            cout << "#" << ++cnt << ". " << win[i].ft << " - Nivel " << win[i].sd / 100 + 1 << endl;
    }
}
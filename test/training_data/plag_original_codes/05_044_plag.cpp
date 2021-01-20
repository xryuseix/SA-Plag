// 引用元 : https://atcoder.jp/contests/abc127/submissions/6435857
// 得点 : 400
// コード長 : 1196
// 実行時間 : 121


#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    ll dd = n;
    vector<ll> a(n);
    vector<pair<ll, ll>> bc(m + n);
    for (int i = 0; i < n; i++)
    {
        bc[i].second = 1;
        cin >> bc[i].first;
    }
    for (int i = n; i < m + n; i++)
    {
        cin >> bc[i].second >> bc[i].first;
    }
    sort(rall(bc));
    //for (int i = 0; i < m + n; i++)
    //{
      //  cout << bc[i].first;
        //cout<<" "<<bc[i].second<<endl;
    //}
    ll count = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        count += bc[i].second;
        if (count < n)
        {
            ans += bc[i].first * bc[i].second;
        }
        else
        {
            count -= bc[i].second;
            for (int j = 0; j < 200000; j++)
            {
                ans += bc[i].first;
                count++;
                if (count == n)
                {
                    break;
                }
            }
            break;
        }
    }
    cout << ans << endl;
}

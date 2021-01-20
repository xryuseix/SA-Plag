// 引用元 : https://atcoder.jp/contests/abc158/submissions/10701568
// 得点 : 400
// コード長 : 1793
// 実行時間 : 108


#include <bits/stdc++.h>
using namespace std;
 
//code start
 
int main()
{
    // freopen("/root/Programming/output.txt", "w", stdout);
    string str, sb;
    int q;
    vector<string> vstart, vend;
    cin >> str;
    scanf("%d", &q);
    // freopen("/root/Programming/input.txt", "r", stdin);
    bool flag = true;
    int ti, fi;
    while (q--)
    {
        scanf("%d", &ti);
        if (ti == 1)
        {
            flag = !flag;
        }
        else
        {
            scanf("%d", &fi);
            getchar();
            cin >> sb;
            if (fi == 1)
            {
                if (flag)
                    vstart.push_back(sb);
                else
                    vend.push_back(sb);
            }
            else
            {
                if (flag)
                    vend.push_back(sb);
                else
                    vstart.push_back(sb);
            }
        }
    }
    if (flag)
    {
        int x = vstart.size();
        for (int i = x - 1; i > -1; i--)
        {
            cout << vstart[i];
        }
        cout << str;
        for (int i = 0; i < vend.size(); i++)
        {
            cout << vend[i];
        }
        printf("\n");
    }
    else
    {
        int x = vend.size();
        for (int i = x - 1; i > -1; i--)
        {
            reverse(vend[i].begin(), vend[i].end());
            cout << vend[i];
        }
        reverse(str.begin(), str.end());
        // cout<<"wojfoej";
        cout<<str;
        for (int i = 0; i < vstart.size(); i++)
        {
            reverse(vstart[i].begin(), vstart[i].end());
            cout << vstart[i];
 
        }
        printf("\n");
    }
    // cout << str << endl;
    return 0;
}

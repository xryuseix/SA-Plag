// 引用元 : https://atcoder.jp/contests/abc127/submissions/6438124
// 得点 : 600
// コード長 : 2022
// 実行時間 : 148


//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define mem(a,v) memset((a), (v), sizeof (a))
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int i = 0; i < (n); i++) ni(a[i])
#define nal(a, n) for (int i = 0; i < (n); i++) nl(a[i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pil pair<int, long long>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vil vector<pil>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 1e6 + 5;
const double eps = 1e-9;
multiset<ll> med1, med2;

int main() {
	int q, cnt=0; ni(q);
	ll bsm = 0, lo = 0, hi = 0;
	while (q--) {
		int t; ni(t);
		if (t == 1) {
			ll a, b; scanf("%lld %lld", &a, &b);
			cnt++;
			bsm += b;
			if (med1.empty() || a <= *med1.rbegin()) {
				lo += a;
				med1.insert(a);
			} else {
				hi += a;
				med2.insert(a);
			}
			
// 風
// 子
// が
// 帰
// っ
// て
// か
// ら
// 、
// 主
// 人
// が
// 書
// 斎
// に
// 入
// っ
// て
// 机
// の
// 上
// を
// 見
// る
// と
// 、
// い
// つ
// の
// 間
// 《
// ま
// 》
// に
// か
// 迷
// 亭
// 先
// 生
// の
// 手
// 紙
// が
// 来
// て
// い
// る
// 。

// ［
// ＃
// こ
// こ
// か
// ら
// ２
// 字
// 下
// げ
// ］

// 「
// 新
// 年
// の
// 御
// 慶
// 《
// ぎ
// ょ
// け
// い
// 》
// 目
// 出
// 度
// 《
// め
// で
// た
// く
// 》
// 申
// 納
// 候
// 《
// も
// う
// し
// お
// さ
// め
// そ
// ろ
// 》
// 。
// …
// …
// 」

// ［
// ＃
// こ
// こ
// で
// 字
// 下
// げ
// 終
// わ
// り
// ］

// 　
// い
// つ
// に
// な
// く
// 出
// が
// 真
// 面
// 目
// だ
// と
// 主
// 人
// が
// 思
// う
// 。
// 迷
// 亭
// 先
// 生
// の
// 手
// 紙
// に
// 真
// 面
// 目
// な
// の
// は
// ほ
// と
// ん
// ど
// な
// い
// の
// で
// 、
// こ
// の
// 間
// な
// ど
// は
// 「
// 其
// 後
// 《
// そ
// の
// ご
// 》
// 別
// に
// 恋
// 着
// 《
// れ
// ん
// ち
// ゃ
// く
// 》
// せ
// る
// 婦
// 人
// も
// 無
// 之
// 《
// こ
// れ
// な
// く
// 》
// 、
// い
// ず
// 方
// 《
// か
// た
// 》
// よ
// り
// 艶
// 書
// 《
// え
// ん
// し
// ょ
// 》
// も
// 参
// ら
// ず
// 、
// 先
// 《
// ま
// 》
// ず
// 先
// 《
// ま
// 》
// ず
// 無
// 事
// に
// 消
// 光
// ｜
// 罷
// 《
// ま
// か
// 》
// り
// 在
// り
// 候
// 《
// そ
// ろ
// 》
// 間
// 、
// 乍
// 憚
// 《
// は
// ば
// か
// り
// な
// が
// ら
// 》
// 御
// 休
// 心
// ｜
// 可
// 被
// 下
// 候
// 《
// く
// だ
// さ
// る
// べ
// く
// そ
// ろ
// 》
// 」
// と
// 云
// う
// の
// が
// 来
// た
// く
// ら
// い
// で
// あ
// る
// 。
// そ
// れ
// に
// 較
// 《
// く
// ら
// 》
// べ
// る
// と
// こ
// の
// 年
// 始
// 状
// は
// 例
// 外
// に
// も
// 世
// 間
// 的
// で
// あ
// る
// 。

// ［
// ＃
// こ
// こ
// か
// ら
// ２
// 字
// 下
// げ
// ］

// 「
// 一
// 寸
// 参
// 堂
// 仕
// り
// 度
// 《
// た
// く
// 》
// 候
// え
// ど
// も
// 、
// 大
// 兄
// の
// 消
// 極
// 主
// 義
// に
// 反
// し
// て
// 、
// 出
// 来
// 得
// る
// 限
// り
// 積
// 極
// 的
// 方
// 針
// を
// 以
// 《
// も
// っ
// 》
// て
// 、
// 此
// 千
// 古
// ｜
// 未
// 曾
// 有
// 《
// み
// ぞ
// う
// 》
// の
// 新
// 年
// を
// 迎
// う
// る
// 計
// 画
// 故
// 、
// 毎
// 日
// 毎
// 日
// 目
// の
// 廻
// る
// 程
// の
// 多
// 忙
// 、
// 御
// 推
// 察
// 願
// 上
// ｜
// 候
// 《
// そ
// ろ
// 》
// …
// …
// 」

// ［
// ＃
// こ
// こ
// で
// 字
// 下
// げ
// 終
// わ
// り
// ］

// 　
// な
// る
// ほ
// ど
// あ
// の
// 男
// の
// 事
// だ
// か
// ら
// 正
// 月
// は
// 遊
// び
// 廻
// る
// の
// に
// 忙
// が
// し
// い
// に
// 違
// い
// な
// い
// と
// 、
// 主
// 人
// は
// 腹
// の
// 中
// で
// 迷
// 亭
// 君
// に
// 同
// 意
// す
// る
// 。

// ［
// ＃
// こ
// こ
// か
// ら
// ２
// 字
// 下
// げ
// ］

// 「
// 昨
// 日
// は
// 一
// 刻
// の
// ひ
// ま
// を
// 偸
// 《
// ぬ
// す
// 》
// み
// 、
// 東
// 風
// 子
// に
// ト
// チ
// メ
// ン
// ボ
// ー
// ［
// ＃
// 「
// ト
// チ
// メ
// ン
// ボ
// ー
// 」
// に
// 傍
// 点
// ］
// の
// 御
// 馳
// 走
// 《
// ご
// ち
// そ
// う
// 》
// を
// 致
// さ
// ん
// と
// 存
// じ
// 候
// 処
// 《
// そ
// ろ
// と
// こ
// ろ
// 》
// 、
// 生
// 憎
// 《
// あ
// い
// に
// く
// 》
// 材
// 料
// 払
// 底
// の
// 為
// 《
// た
// 》
// め
// 其
// 意
// を
// 果
// さ
// ず
// 、
// 遺
// 憾
// 《
// い
// か
// ん
// 》
// 千
// 万
// に
// 存
// 候
// 《
// ぞ
// ん
// じ
// そ
// ろ
// 》
// 。
// …
// …
// 」

// ［
// ＃
// こ
// こ
// で
// 字
// 下
// げ
// 終
// わ
// り
// ］

// 　
// そ
// ろ
// そ
// ろ
// 例
// の
// 通
// り
// に
// な
// っ
// て
// 来
// た
// と
// 主
// 人
// は
// 無
// 言
// で
// 微
// 笑
// す
// る
// 。

			while (med1.size() > med2.size() + 1) {
				lo -= *med1.rbegin();
				hi += *med1.rbegin();
				med2.insert(*med1.rbegin());
				med1.erase(--med1.end());
			}
			while (med2.size() > med1.size()) {
				lo += *med2.begin();
				hi -= *med2.begin();
				med1.insert(*med2.begin());
				med2.erase(med2.begin());
			}
		} else {
			printf("%lld %lld\n", *med1.rbegin(), bsm + hi - lo + (ll)((ll)med1.size() - (ll)med2.size()) * *med1.rbegin());
		}
	}
    return 0;
}
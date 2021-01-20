// 引用元 : https://atcoder.jp/contests/agc033/submissions/8716020
// 得点 : 300
// コード長 : 1285
// 実行時間 : 80





#include <bits/stdc++.h>



#define rep(i,N) for(int i=0;i<N;i++)

#define rep2(i,N) for(int i=1;i<=N;i++)



using namespace std;

long long  INF=1000000000000000000;

long long mod=1000000007;

using namespace std;





int main(){



bool checked[1010][1010]={};

vector<queue<int>>q(2020);

int h,w;

cin>>h>>w;

rep2(i,h){

				rep2(k,w){

								char c;

								cin>>c;

								if(c=='#'){

												checked[i][k]=true;

												q[0].push(k);

												q[0].push(i);

								}

				}

}



int dx[4]={0,1,0,-1};

int dy[4]={1,0,-1,0};

int p=0;

while(1){

				bool finish=true;

				while(!q[p].empty()){

								int x=q[p].front();q[p].pop();

								int y=q[p].front();q[p].pop();

								rep(i,4){

												int nowx=x+dx[i];

												int nowy=y+dy[i];

												if(nowx>=1 && nowx<=w && nowy>=1 && nowy<=h){

																if(checked[nowy][nowx])continue;

																checked[nowy][nowx]=true;

																q[p+1].push(nowx);

																q[p+1].push(nowy);

																finish=false;

												}

								}

				}

				if(finish)break;

				p++;



}

cout<<p<<endl;



 return 0;

}

/*



by my self

first  23m 43s

second 17m 44s



3 3

...

.#.

...



2





6 6

..#..#

......

#..#..

......

.#....

....#.



3

*/


// 引用元 : https://atcoder.jp/contests/abc079/submissions/5997342
// 得点 : 300
// コード長 : 724
// 実行時間 : 1


#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

typedef long long ll;
typedef pair<int,int>P;

#define F first
#define S second

string s;
char sign[3];
int a[4];
int temp;
int main(){
  cin>>s;
  
  for(int i=0;i<4;i++){
    a[i]=s[i]-'0';
  }

  for(int i=0;i<8;i++){
    temp=a[0];
    for(int j=0;j<3;j++){
      if((i>>j)%2 == 1) sign[j]='-';
      else sign[j]='+';
    }

    for(int j=0;j<3;j++){
      if(sign[j]-'+'==0) temp+=a[j+1];
      else temp-=a[j+1];
    }
    if(temp-7==0){
      printf("%d",a[0]);
      for(int j=0;j<3;j++){
	printf("%c%d",sign[j],a[j+1]);
      }
      printf("=7\n");
      break;
    }
  }
  
  return 0;
}

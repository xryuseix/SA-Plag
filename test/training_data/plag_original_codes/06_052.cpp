// 引用元 : https://atcoder.jp/contests/abc076/submissions/5997538
// 得点 : 300
// コード長 : 798
// 実行時間 : 1


#include<bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int,int>P;
     
#define F first
#define S second
     
int main(){
  string s,t,ans;
  bool flg=false;
  cin>>s;
  cin>>t;
     
  for(int i=0;i<s.size();i++){
    if(s[i]=='?') ans[i]='a';
    else ans[i]=s[i];
  }
      
  for(int i=s.size()-t.size();i>=0;i--){
    if(s[i]==t[0]||s[i]=='?'){
      for(int j=0;j<t.size();j++){
    	if(s[i+j]!=t[j]&&s[i+j]!='?') break;
    	if(j==t.size()-1&&!flg){
    	  for(int k=0;k<t.size();k++){
    	    ans[k+i]=t[k];
    	  }
    	  flg=true;
    	}
      }
    }
  }
     
  if(flg){
    for(int i=0;i<s.size();i++){
      cout<<ans[i];
    }
    cout<<'\n';
  }else{
    cout<<"UNRESTORABLE\n";
  }
  return 0;
}

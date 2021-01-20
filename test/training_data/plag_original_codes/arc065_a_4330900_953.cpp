/*
引用元：https://atcoder.jp/contests/arc065/tasks/arc065_a
C - DaydreamEditorial
// ソースコードの引用元 : https://atcoder.jp/contests/arc065/submissions/4330900
// 提出ID : 4330900
// 問題ID : arc065_a
// コンテストID : arc065
// ユーザID : xryuseix
// コード長 : 1496
// 実行時間 : 939



*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

int main(void) {
  int i;
  string s;
  cin >> s;
  //	while(s.length()>=5){
  //		int place=s.find("erasereraser");
  //		if(place!=-1)s=s.replace(place,12,"");
  //		else{
  //			place=s.find("dreamereraser");
  //			if(place!=-1)s=s.replace(place,13,"");
  //			else{
  //				place=s.find("dreamererase");
  //				if(place!=-1)s=s.replace(place,12,"");
  //				else{
  //					place=s.find("dreameraser");
  //					if(place!=-1)s=s.replace(place,11,"");
  //					else{
  //						place=s.find("dreamerase");
  //						if(place!=-1)s=s.replace(place,10,"");
  //						else{
  //							place=s.find("erase");
  //							int
  //dplace=s.find("dream");
  //							if(place!=-1)s=s.replace(place,5,"");
  //							if(dplace!=-1)s=s.replace(dplace,5,"");
  //							if(place==-1&&dplace==-1)break;
  //						}
  //					}
  //				}
  //			}
  //		}
  //	}
  bool ch = true;
  while (ch) {
    int place = s.find("eraser");
    if (place != -1)
      s = s.replace(place, 6, "");
    else
      ch = false;
  }
  ch = true;
  while (ch) {
    int place = s.find("erase");
    if (place != -1)
      s = s.replace(place, 5, "");
    else
      ch = false;
  }
  ch = true;
  while (ch) {
    int place = s.find("dreamer");
    if (place != -1)
      s = s.replace(place, 7, "");
    else
      ch = false;
  }
  ch = true;
  while (ch) {
    int place = s.find("dream");
    if (place != -1)
      s = s.replace(place, 5, "");
    else
      ch = false;
  }
  if (s.length() == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}

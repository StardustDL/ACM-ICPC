/*
Moving Tables
分析：可以用贪心算法解出，但我还是用了别的方案（更easy）。原理如下：
      先创建一个函数f，输入的是任意房间号，输出的是走廊的位置。
	  比如1号房间和2号房间都对应位置1的走廊，3号房间和4号房间对应位置2的走廊，
	  一共有200个这样的位置。
	  用a[201]定义这些位置，其中某位置的值就是经历这个位置的次数。
	  如果从某一号房到另一号房，所经历的每个位置的次数都+1，最后再全体扫描下哪个位置经历次数最多，输出值便是这个位置的值*10。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define f(x) ((x&1)?((x+1)>>1):(x>>1))
int t,n,a,b,s[203];
int main(){
	cin>>t;
	while(t-->0){
		memset(s,0,sizeof(s));
		cin>>n;
		while(n-->0){
			cin>>a>>b;
			if(a>b)swap(a,b);
			a=f(a);b=f(b);
			for(int i=a;i<=b;i++)s[i]++;
		}
		for(int i=1;i<=200;i++)n=max(n,s[i]);
		cout<<n*10<<endl;
	}
}

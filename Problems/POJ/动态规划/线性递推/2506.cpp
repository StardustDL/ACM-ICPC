/*
Tiling
题意：有2×1和2×2两种规格的地板，现要拼2×n的形状，共有多少种情况
分析：假设我们已经铺好了2×（n-1）的情形，则要铺到2×n则只能用2×1的地板
	  假设我们已经铺好了2×（n-2）的情形，则要铺到2×n则可以选择1个2×2或两个2×1，故可能有三种铺法，其中一种是重复计数
	  a[i]=2*a[i-2]+a[i-1]
	  注意n可能为0 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=500;
char temp[MAXN+3];
struct bign{
	int v[MAXN+3],len;
	bign(){init();}
	void init(){len=1;memset(v,0,sizeof(v));}
	void set(int t){
		init();
		for(len=1;t;len++,t/=10)v[len-1]=t%10;
		adjust();
	}
	void adjust(){
		for(int i=0;i<len;i++){
			if(v[i]>9){
				v[i+1]+=v[i]/10;
				v[i]%=10;
			}
			if(v[len])len++;
		}
		while(!v[len-1]&&len>1)len--;
	}
	bign operator +(const bign &t)const{
		bign ans;
		ans.len=max(t.len,len);
		for(int i=0;i<ans.len;i++){
			ans.v[i]=t.v[i]+v[i];
		}
		ans.adjust();
		return ans;
	}
	void input(){
		init();
		scanf("%s",temp);
		len=strlen(temp);
		for(int i=len;i;i--){
			v[len-i]=temp[i-1]-'0';
		}
	}
	void output(){
		for(int i=len-1;i>=0;i--)putchar(v[i]+'0');
	}
};
bign Ans[251];int n;
int main(){
	Ans[0].set(1);
	Ans[1].set(1);
	for(int i=2;i<=250;i++)
		Ans[i]=Ans[i-1]+Ans[i-2]+Ans[i-2];
	while(~scanf("%d",&n))Ans[n].output(),puts("");
	return 0;
}


/*
[FJOI2007]轮状病毒
分析：VFK推出了一个递推式：f[1]=1,f[2]=5,f[n]=3*f[n-1]-f[n-2]+2，具体推导见博客 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
struct bign{
	int len,v[MAXN+3];
	
	bign(){len=1;memset(v,0,sizeof(v));}
	
	void adjust(){
		for(int i=0;i<len;i++)if(v[i]>9){v[i+1]+=v[i]/10,v[i]%=10;if(i==len-1)len++;}
		while(v[len-1]==0&&len>1)len--;
	}
	
	bign operator -(const bign &t)const{
		bign ans;
		int tmp=0;
		for(int i=0;i<len;i++){
			ans.v[i]=v[i]-tmp-t.v[i];
			if(ans.v[i]<0)ans.v[i]+=10,tmp=1;
			else tmp=0;
		}
		ans.len=len;
		ans.adjust();
		return ans; 
	}
	
	bign operator +(const int t)const{
		bign ans=*this;
		ans.v[0]+=t;
		ans.adjust();
		return ans; 
	}
	
	bign operator *(const int t)const{
		bign ans=*this;
		for(int i=0;i<ans.len;i++)ans.v[i]*=t;
		ans.adjust();
		return ans; 
	}
	void output(){
		for(int i=len-1;i>=0;i--)printf("%d",v[i]); 
	}
}cnt[MAXN+3];
int n;
int main(){
	cnt[1].v[0]=1;
	cnt[2].v[0]=5;
	scanf("%d",&n);
	for(int i=3;i<=n;i++){
		cnt[i]=cnt[i-1]*3-cnt[i-2]+2;
	}
	cnt[n].output();
	return 0;
}


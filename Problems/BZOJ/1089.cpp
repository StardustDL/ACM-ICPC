/*
[SCOI2003]严格n元树
分析：f[i]表示深度<=i的严格n元树的数量，f[i]=f[i-1]^n+1 (1是空树)
	  高精度 ，不压位就是慢啊,16ms vs 36ms 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int RAD=1000;
struct bign{
	int len,v[300+3];
	bign(){len=1;memset(v,0,sizeof(v));}
	int& operator [](int x){
		return v[x];
	}
	void adjust(){while(len>1&&v[len]==0)len--;}
	void simply(){
		for(int i=1;i<=len;i++){
			if(v[i]>=RAD){
				if(i==len){v[++len]+=v[i]/RAD;}
				else v[i+1]+=v[i]/RAD;
				v[i]%=RAD;
			}
		}
	}
	bign operator ^(int n)const{
		bign ans,t=*this;ans[1]=1;ans.len=1;
		while(n){
			if(n&1)ans=ans*t;
			t=t*t;
			n>>=1;
		}
		return ans;
	}
	bign operator *(const bign& t)const{
		bign ans;
		ans.len=len+t.len;
		for(int i=1;i<=len;i++){
			for(int j=1;j<=t.len;j++)
				ans[i+j-1]+=v[i]*t.v[j];
		}
		ans.simply();
		ans.adjust();
		return ans;
	}
	bign operator +(const int t)const{
		bign ans=*this;
		ans[1]+=t;
		ans.simply();
		return ans;
	}
	bign operator -(const bign& t)const{
		bign ans=*this;
		for(int i=1;i<=ans.len;i++){
			ans[i]-=t.v[i];
			if(ans[i]<0)ans[i]+=RAD,ans[i+1]--;
		}
		ans.adjust();
		return ans;
	}
	void output(){
		printf("%d",v[len]);
		for(int i=len-1;i>=1;i--){
			printf("%03d",v[i]);
		}
	}
};
bign f[20];
int n,d;
int main(){
	scanf("%d%d",&n,&d);
	if(d==0){printf("1\n");return 0;}
	f[0].len=1;f[0][1]=1;
	for(int i=1;i<=d;i++)f[i]=(f[i-1]^n)+1;
	(f[d]-f[d-1]).output();
	return 0;
}


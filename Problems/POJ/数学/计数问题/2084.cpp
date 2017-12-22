/*
Game of Connections
题意：一圆环上有2n个点，求两两连线且不交叉的方法数。
分析：catalan数
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
struct bign{
	int v[MAXN+3],len;
	
	bign(){init();}
	bign(int t){*this=t;}
	
	void init(){
		memset(v,0,sizeof(v));
		len=0;
	}
	
	void clear(){
		while(!v[len-1] && len>1)len--;
	}
	
	bign operator = (const bign &t){
		memcpy(v,t.v,(t.len+5)*sizeof(int));
		len=t.len;
		return *this;
	}
	
	bign operator = (int val){
		init();
		if(val==0)len=1;
		while(val){
			v[len++]=val%10;
			val/=10;
		}
		return *this;
	}
	
	bign operator * (const bign &t)const{
		bign ans;ans.len=len+t.len;
		for(int i=0;i<len;i++){
			for(int j=0;j<t.len;j++){
				ans.v[i+j]+=v[i]*t.v[j];
			}
		}
		ans.simply();
		ans.clear();
		return ans;
	}
	
	bign operator / (const int t)const{
		bign ans;ans.len=len;int x=0;
		for(int i=len-1;i>=0;i--){
			ans.v[i]=(x*10+v[i])/t;
			x=(x*10+v[i])%t; 
		}
		ans.clear();
		return ans;
	}
	void simply(){
		v[len+1]=0;
		for(int i=0;i<len;i++)
			if(v[i]>9)v[i+1]+=v[i]/10,v[i]%=10;
		if(v[len])len++;
	}
	void output(){for(int i=len-1;i>=0;i--)putchar(v[i]+'0');}
};
bign ans=1; 
int n;
int main(){
	while(scanf("%d",&n),~n){
		ans=1;
		for(int i=2;i<=n;i++){
			ans=ans*(4*i-2)/(i+1);
		}
		ans.output();puts("");
	}
	return 0;
}


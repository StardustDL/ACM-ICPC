#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
struct bign{
	int v[MAXN+3],len;
	bign(){init();}
	bign(int t){
		init();
		*this=t;
	}
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
	bign operator + (const bign &t)const{
		bign ans;ans.len=max(len,t.len);
		int lm=min(len,t.len);
		for(int i=0;i<lm;i++)ans.v[i]=v[i]+t.v[i];
		const int *s=(len<t.len?t.v:v);
		for(int i=lm;i<ans.len;i++)ans.v[i]=s[i];
		ans.simply();
		return ans;
	}
	bign operator * (const bign &t)const{
		bign ans;ans.len=len+t.len;
		for(int i=0;i<len;i++)
			for(int j=0;j<t.len;j++)
				ans.v[i+j]+=v[i]*t.v[j];
		ans.simply();
		ans.clear();
		return ans;
	}
	void simply(){
		v[len+1]=0;
		for(int i=0;i<len;i++){
			if(v[i]>=10){
				v[i+1]+=v[i]/10;
				v[i]%=10;
			}
		}
		if(v[len])len++;
	}
	void output(){
		for(int i=len-1;i>=0;i--)putchar(v[i]+'0');
	}
};
bign a,b;
int main(){
	int n;
	cin>>n;
	a=0;b=1;
	for(int i=1;i<=n;i++){
		b=b*bign(i);
		a=a+b;
	}
	a.output();
	return 0;
}


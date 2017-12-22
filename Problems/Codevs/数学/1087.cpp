/*

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=600,INF=0x3f3f3f3f;
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
	
	bign operator -- (int){
		if(v[0]){v[0]--;clear();}
		else{
			bign t;t=1;
			*this=*this-t;
		}
		return *this;
	}
	
	bign operator - (const bign &t)const{//要求大减小 
		bign ans=*this;
		for(int i=0;i<t.len;i++){
			if(ans.v[i]-t.v[i]<0){
				ans.v[i+1]--;
				ans.v[i]+=10;
			}
			ans.v[i]-=t.v[i];
		}
		ans.clear();
		return ans;
	}
	
	bign operator * (const bign &t)const{
		bign ans;ans.len=len+t.len;
		for(int i=0;i<len;i++){
			for(int j=0;j<t.len;j++){
				if(i+j<=500)ans.v[i+j]+=v[i]*t.v[j];
			}
		}
		ans.simply();
		ans.clear();
		return ans;
	}
	
	void mutiply10(int e){
		len+=e;
		for(int i=len-1;i>=e;i--){
			v[i]=v[i-e];
		}
		for(int i=0;i<e;i++)v[i]=0;
	}
	
	void simply(){
		if(len>501)len=501;
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
		int k=0;
		for(int i=499;i>=0;i--){
			putchar(v[i]+'0');
			if((++k)%50==0)puts("");
		}
	}
};
bign ans,a;
int p;
void ksm(){
	ans=1;a=2;
	while(p){
		if(p&1)ans=ans*a;
		a=a*a;
		p>>=1;
	}
	ans--;
}
int main(){
	scanf("%d",&p);
	printf("%d\n",((int)floor(1.0*p*log10(2.0)))+1);
	ksm();
	ans.output();
	return 0;
}


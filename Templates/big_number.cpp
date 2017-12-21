/*

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
const int R=1000;
struct bign{
	int len,d[MAXN+3];
	void set(int a){
		clear();len=0;
		while(a){
			d[len++]=a%R;
			a/=R;
		}
	}
	void clear(){
		len=1;memset(d,0,sizeof(d));
	}
	void output(){
		printf("%d",d[len-1]);
		for(int i=len-2;i>=0;i--)printf("%03d",d[i]);
	}
	void adjust(){
		for(int i=0;i<len;i++){
			if(d[i]>=R){
				d[i+1]+=d[i]/R;d[i]%=R;
				if(i+1==len)len++;
			}
			else if(d[i]<0){
				d[i+1]--;
				d[i]+=R;
			}
		}
		while(d[len-1]==0&&len>1)len--;//pay attention to this line
	}
	bool operator == (const bign &t)const{
		if(len!=t.len)return false;
		for(int i=0;i<len;i++)if(d[i]!=t.d[i])return false;
		return true;
	} 
	bool operator < (const bign &t)const{
		if(len!=t.len)return len<t.len;
		for(int i=len-1;i>=0;i--)if(d[i]<t.d[i])return true;
		return false;
	} 
	bign operator +(const bign &t)const{
		bign ans;ans.clear();
		ans.len=max(len,t.len);
		for(int i=0;i<ans.len;i++)ans.d[i]=d[i]+t.d[i];
		ans.adjust();
		return ans; 
	}
	bign operator -(const bign &t)const{
		bign ans;ans.clear();
		ans.len=max(len,t.len);
		for(int i=0;i<ans.len;i++)ans.d[i]=d[i]-t.d[i];
		ans.adjust();
		return ans;
	}
	bign operator *(const bign &t)const{
		bign ans;ans.clear();
		ans.len=len+t.len;
		for(int i=0;i<len;i++){
			for(int j=0;j<t.len;j++)ans.d[i+j]+=d[i]*t.d[j];
		}
		ans.adjust();
		return ans;
	}
}a,b;
int main(){
	int x,y;
	cin>>x>>y;
	a.set(x);b.set(y);
	(a*b).output();
	return 0;
}


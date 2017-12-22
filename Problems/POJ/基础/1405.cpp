/*
Heritage
题意：将一份财产分成n份，1/x1, 1/x2, 1/x3, ...,1/xn.使得x1>x2>x3>...>xn,让教堂（最后剩下的）分得的财产最少. 
分析：xn = x1 * x2 * ...*xn-1 + 1.
	  如果前k个分剩下1/c,因为1/c>1/(c+1)>1/(c+2)>...所以下一个拿1/(c+1),剩下1/(c * (c+1)). 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
char temp[MAXN+3];
struct bign{
	int v[MAXN+3],len;
	bign(){init();}
	void init(){len=1;memset(v,0,sizeof(v));}
	void set(int t){
		init();
		for(len=1;t;len++,t/=10)v[len-1]=t%10;
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
	void add(){
		v[0]++;
		adjust();
	}
	bign operator *(const bign &t)const{
		bign ans;
		ans.len=t.len+len;
		for(int i=0;i<len;i++){
			for(int j=0;j<t.len;j++){
				ans.v[i+j]+=t.v[j]*v[i];
			}
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
bign ans,last;int n;
int main(){
	ans.set(1);last.set(1);
	scanf("%d",&n);
	//puts("2");
	for(int i=1;i<=n;i++){
		ans=ans*last;//last=x(i-2)*x(i-3)*....
		last=ans;//last=x(i-1)*x(i-2)*...
		ans.add();//ans=xi
		(ans).output();puts("");
	}
	return 0;
}


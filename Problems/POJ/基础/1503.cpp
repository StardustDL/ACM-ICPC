/*
Integer Inquiry
分析：高精加 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
char temp[MAXN+3];
struct bign{
	int v[MAXN+3],len;
	bign(){init();}
	void init(){len=1;memset(v,0,sizeof(v));}
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
bool iszero(const bign &t){
	return t.len==1&&t.v[0]==0;
}
bign ans,t;int k;
int main(){
	do{
		t.input();//t.output();cout<<"!!!"<<endl;
		ans=ans+t;
		//cout<<t.len<<endl;
		//ans.output();cin>>k;
	}while(!iszero(t));
	ans.output();puts("");
	return 0;
}


/*
[Zjoi2012]数列(sequence)
分析：高精度+记忆化搜索，可以发现，每次n减小一半，这样最多logn层 
*/
#include<iostream>
#include<cstring>
#include<cstdio>
const int RAD=10000;
using namespace std;
int T;
struct data{
	int v[105],l;
	data(){v[1]=0;l=1;}
	void clear(){memset(v,0,sizeof(v));l=1;}
}n,p,q;
char ch[105];
void read(data &x){
	data a;
	scanf("%s",ch+1);
	a.l=strlen(ch+1);
	for(int i=1;i<=a.l;i++)a.v[i]=ch[a.l-i+1]-'0';
	for(int i=a.l+1;i<=a.l+4;i++)a.v[i]=0;
	x.l=(a.l-1)/4+1;
	for(int i=1;i<=x.l;i++){
		x.v[i]=0;
		for(int k=1;k<=4;k++)
			x.v[i]=x.v[i]*10+a.v[(i-1)*4+(5-k)];
	}
}
data operator+(data a,data b){
	if(a.l<b.l)swap(a,b);
	int t=b.l;
	for(int i=1;i<=t;i++)a.v[i]+=b.v[i];
	for(int i=1;i<=t;i++)
		if(a.v[i]>=RAD){
			if(i==a.l){
				a.v[i+1]=0;
				a.l++;
			}
			a.v[i+1]+=a.v[i]/RAD;
			t=max(t,i+1);
			a.v[i]%=RAD;
		}
	return a;
}
data operator+(data a,int p){
	data b;
	b.v[1]=p;b.l=1;
	return a+b;
} 
data operator/(data a,int p){
	for(int i=1;i<=a.l;i++){
		if(a.v[i]&1)a.v[i-1]+=RAD/p;
		a.v[i]/=p;  
	}
	while(!a.v[a.l]&&a.l)a.l--;
	return a;
}
void print(data a){
	printf("%d",a.v[a.l]);
	for(int i=a.l-1;i;i--)
		printf("%04d",a.v[i]);
	printf("\n");
}
void calc(data x){
	if(x.l==1&&x.v[1]==1){
		p=x;q.clear();return;
	}
	calc((x+1)/2);
	if(x.v[1]&1)p=p+q;
	else q=p+q;
}
int main(){
	scanf("%d",&T);
	while(T--){
		read(n);calc(n);
		print(p);
	}
	return 0;
}

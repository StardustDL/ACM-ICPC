/*
[JSOI2007]字符加密Cipher
分析：串长翻一倍，后缀数组扫一遍
	  注意不要因为数组开小了RE 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2*100000,INF=0x3f3f3f3f;
char str[MAXN+3];
int a[MAXN+3],wa[MAXN+3],wb[MAXN+3],wv[MAXN+3],wt[MAXN+3],sa[MAXN+3],len;
bool cmp(int *t,int a,int b,int l){
	return t[a]==t[b]&&t[a+l]==t[b+l];
}
void da(int *str,int *sa,int n,int m){
	int *x=wa,*y=wb,i,j,p,*t;
	for(i=0;i<m;i++)wt[i]=0;
	for(i=0;i<n;i++)wt[x[i]=str[i]]++;
	for(i=1;i<m;i++)wt[i]+=wt[i-1];
	for(i=n-1;i>=0;i--)sa[--wt[x[i]]]=i;
	for(j=1,p=1;p<n;j<<=1,m=p){
		for(p=0,i=n-j;i<n;i++)y[p++]=i;
		for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(i=0;i<m;i++)wt[i]=0;
		for(i=0;i<n;i++)wt[wv[i]=x[y[i]]]++;
		for(i=1;i<m;i++)wt[i]+=wt[i-1];
		for(i=n-1;i>=0;i--)sa[--wt[wv[i]]]=y[i];
		swap(x,y);
		for(p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
	}
}
void output(){
	for(int i=0;i<len;i++)
		if(sa[i]<=(len>>1)-1)putchar(str[sa[i]+(len>>1)-1]);
}
void input(){
	scanf("%s",str);
	len=strlen(str);
	for(int i=0;i<len;i++){str[i+len]=str[i];a[i]=a[i+len]=(int)str[i];}
	a[len<<=1]=0;
	len+=1;
}
int main(){
	input();
	da(a,sa,len,256);
	output();
	return 0;
}


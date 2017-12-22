/*
[Usaco2009 Open]Cow Line 直线上的牛
分析：模拟 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,l,r,tot;
int q[200005];
char a[5],b[5];
int main(){
	n=read();l=r=100000;
	for(int i=1,x;i<=n;i++){
		scanf("%s%s",a,b);
		if(a[0]=='D'){
			x=read();
			while(x--){
				if(b[0]=='L')l++;
				else r--;
			}
		}
		else {
			if(b[0]=='L')q[l--]=++tot;
			else q[++r]=++tot;
		}
	}
	for(int i=l+1;i<=r;i++)
		printf("%d\n",q[i]);
	return 0;
}

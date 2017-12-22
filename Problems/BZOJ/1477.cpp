/*
青蛙的约会
分析：扩展gcd 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef long long LL;
LL exgcd(LL a,LL b,LL &x,LL &y){
    LL r,t;
    if(b==0){x=1;y=0;return a;}
    r=exgcd(b,a%b,x,y);t=x;x=y; y=t-a/b*y;
    return r;
}
int main(){
    LL x,y,m,n,l,xx,yy,d,r;
    cin>>x>>y>>m>>n>>l;
    d=exgcd(n-m,l,xx,yy);
    if((x-y)%d!=0)cout<<"Impossible"<<endl;
    else{
		xx=xx*((x-y)/d);
		r=l/d;
		xx=(xx%r+r)%r;//求出最小非负整数解
		cout<<xx<<endl;
	}
    return 0;
}

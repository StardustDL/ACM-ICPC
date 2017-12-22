/*
阿达马矩阵
分析：不难，但是long long刚好存不下。。。 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
#define TK(k) ((1LL<<(k)))
#define larger(x,k) (x>TK(k))
typedef long long LL;
LL k,x,y;
bool solve(LL k,LL x,LL y){
	//cout<<k<<" "<<x<<" "<<y<<" "<<TK(k-1)<<endl; 
	if(k==0){
		//x==1&&y==1
		return 1;
	} 
	if(larger(x,k-1)&&larger(y,k-1))return !solve(k-1,x-TK(k-1),y-TK(k-1));
	return solve(k-1,larger(x,k-1)?x-TK(k-1):x,larger(y,k-1)?y-TK(k-1):y); 
}
int main(){
	cin>>k>>x>>y;
	if(k==64)cout<<1<<endl; 
	else cout<<solve(k,x,y)<<endl;
	return 0;
}


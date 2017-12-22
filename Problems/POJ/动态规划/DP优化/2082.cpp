/*
Terrible Sets
题意：最大连续矩形面积 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
struct block{
	int w,h;
	block(int w,int h):w(w),h(h){}
};
stack<block> S;
int ans=0,n,w,h;
int main(){
	while(scanf("%d",&n),~n){
		while(!S.empty())S.pop();ans=0;
		while(n--){
			scanf("%d%d",&w,&h);
			if(S.empty())S.push(block(w,h));
			else{
				if(h>=S.top().h)S.push(block(w,h));
				else{
					int sumw=0;
					while(!S.empty()&&h<S.top().h){
						sumw+=S.top().w;
						ans=max(ans,S.top().h*sumw);
						S.pop(); 
					}
					S.push(block(sumw+w,h));
				}
			}
		}
		int sumw=0;
		while(!S.empty()){
			sumw+=S.top().w;
			ans=max(ans,S.top().h*sumw);
			S.pop(); 
		}
		printf("%d\n",ans);
	}
	return 0;
}


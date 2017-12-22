/*
Largest Rectangle in a Histogram
题意：给出一个柱状图，各柱之间没有空隙。要求在这些柱覆盖的面积中画出一个最大的矩形（可跨越多个柱），求该矩形面积。
分析：用栈来维护一个严格升序序列，出栈时对元素的扩展面积进行计算，栈顶元素左右的扩展范围是，栈中的前一个元素的位置＋1到当前读入元素的位置－1。 
*/ 
#include<cstdio>
#include<stack>
using namespace std;
typedef long long ll;
const int MAXN=100000;
struct node{
	ll w,h;
	node(){
		w=1;h=0;
	}
};
stack<node> st;
int n;
node a[MAXN+3];
ll ans=0;
bool init(){
	scanf("%d",&n);
	if(n==0)return false;
	while(!st.empty())st.pop();
	for(int i=1;i<=n;i++){
		scanf("%ld",&a[i].h);
		a[i].w=1;
	}
	ans=0;
	return true;
}
void work(){
	ll k=0,s=0;
	for(int i=1;i<=n;i++){
		k=s=0;
		if(st.empty()||a[i].h>=st.top().h){
			st.push(a[i]);continue;
		}
		while((!st.empty())&&(st.top().h>a[i].h)){
			k+=st.top().w;
			s=k*st.top().h;
			if(s>ans)ans=s;
			st.pop();
		}
		a[i].w+=k;
		st.push(a[i]);
	}
	k=s=0;
	while(!st.empty()){
		k+=st.top().w;
		s=k*st.top().h;
		if(s>ans)ans=s;
		st.pop();
	}
}
int main(){
	while(init()){
		work();
		printf("%lld\n",ans);
	}
	return 0;
}

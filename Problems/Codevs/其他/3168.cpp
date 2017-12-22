/*
抄书问题 3
分析：由于这道题中只有抄书最多人对结果有影响，所以可以二分这个值，验证最少划分是否<=k，最后贪心地求方案即可
	  注意如果分组不足K个，要补成K个 
*/
#include<iostream>
using namespace std;
const int MAXM=1000000,MAXK=10000;
struct res{int s,t;}ans[MAXK+3];
int m,k,page[MAXM+3],s=0;
bool check(int ans){
	int t=page[1],cnt=0;
	for(int i=2;i<=m;i++){
		if(page[i]>ans)return false;
		if(t+page[i]<=ans)t+=page[i];
		else cnt++,t=page[i];
	}
	return ++cnt<=k;
}
int dichotomy(int l,int r){
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	return l;
}
int buildans(int maxpage){
	if(m==0)return 0;
	int t=page[m],cnt=0,l=m,i;
	for(i=m-1;i>=1;i--){
		if(k-(cnt+1)==i)break;
		if(t+page[i]<=maxpage)t+=page[i];
		else{
			ans[++cnt].s=i+1;
			ans[cnt].t=l;
			l=i;
			t=page[i];
		}
	}
	if(k-(cnt+1)==i){
		ans[++cnt].s=i+1;
		ans[cnt].t=l;
		while(i>=1){
			ans[++cnt].s=i;
			ans[cnt].t=i;
			i--;
		}
	}
	else{
		ans[++cnt].s=1;
		ans[cnt].t=l;
	}
	return cnt;
}
void output(int cnt){
	for(int i=cnt;i>=1;i--)
		cout<<ans[i].s<<" "<<ans[i].t<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>page[i];
		s+=page[i];
	}
	output(buildans(dichotomy(0,s)));
	return 0;
}


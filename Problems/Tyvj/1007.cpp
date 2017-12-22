#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000;
int m,n,l,k,d,row[MAXN+3],col[MAXN+3],rr[MAXN+3],rc[MAXN+3];
bool cmp1(const int i,const int j){
	return col[i]>col[j];
}
bool cmp2(const int i,const int j){
	return row[i]>row[j];
}
int main(){
	cin>>m>>n>>k>>l>>d;
	int x,y,p,q;
	for(int i=1;i<=d;i++){
		cin>>x>>y>>p>>q;
		//统计每行每列所分隔的对数 
		if(x==p){
			col[min(y,q)]++;
		}
		else if(y==q){
			row[min(x,p)]++;
		}
	}
	for(int i=1;i<=m;i++)rc[i]=i;
	for(int i=1;i<=n;i++)rr[i]=i;
	sort(rc+1,rc+m+1,cmp1);//排序 
	sort(rr+1,rr+n+1,cmp2);
	sort(rc+1,rc+l+1);
	sort(rr+1,rr+k+1);
	for(int i=1;i<=k;i++){
		cout<<rr[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=l;i++){
		cout<<rc[i]<<" ";
	}
	return 0;
}

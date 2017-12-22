/*
еевЫрн
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1000;
int m,n,k,l,d,r[MAXN+3],c[MAXN+3],rr[MAXN+3],rc[MAXN+3];
vector<int> ar,ac;
bool cmpr(const int i,const int j){
	return r[i]>r[j];
}
bool cmpc(const int i,const int j){
	return c[i]>c[j];
}
int main(){
	ios::sync_with_stdio(false);
	cin>>m>>n>>k>>l>>d;
	int w,x,y,z;
	for(int i=1;i<=m;i++)rr[i]=i;
	for(int i=1;i<=n;i++)rc[i]=i;
	while(d-->0){
		cin>>w>>x>>y>>z;
		if(w==y)c[min(x,z)]++;
		else if(x==z)r[min(w,y)]++;
	}
	sort(rr+1,rr+m+1,cmpr);
	sort(rc+1,rc+n+1,cmpc);
	for(int i=1;i<=k;i++){
		ar.push_back(rr[i]);
	}
	for(int i=1;i<=l;i++){
		ac.push_back(rc[i]);
	}
	sort(ar.begin(),ar.end());
	sort(ac.begin(),ac.end());
	for(int i=1;i<=k;i++)cout<<ar[i-1]<<" ";
	cout<<endl;
	for(int i=1;i<=l;i++)cout<<ac[i-1]<<" ";
	return 0; 
}

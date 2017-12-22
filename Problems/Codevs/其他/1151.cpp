/*
分数线划定
*/
#include<iostream>
#include<algorithm>
using namespace std;
int ks[5003],fs[5003],r[5003],n,m;
bool cmp(int i,int j){
	return (fs[i]>fs[j])||(fs[i]==fs[j])&&(ks[i]<ks[j]);
}
int main(){
	cin>>n>>m;
	m*=1.5;
	for(int i=1;i<=n;i++){
		cin>>ks[i]>>fs[i];
		r[i]=i;
	}
	sort(r+1,r+n+1,cmp);
	m=fs[r[m]];
	int t=1;
	while(fs[r[t]]>=m)t++;
	cout<<m<<" "<<t-1<<endl;
	for(int i=1;i<t;i++)
		cout<<ks[r[i]]<<" "<<fs[r[i]]<<endl;
	return 0;
}

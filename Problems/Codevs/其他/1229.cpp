/*
Êı×ÖÓÎÏ·
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int judge(int x,int k){
	int sum=0;
	sort(v.begin(),v.end());
	do{
		sum=0;
		for(int i=0;i<v.size();i++)
			sum=sum*10+v[i];
		if((sum+x)%k==0)return sum;
	}while(next_permutation(v.begin(),v.end()));
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m,x,k,t;
	cin>>n>>m;
	while(n-->0){
		cin>>x;
		v.push_back(x);
	}
	while(m-->0){
		cin>>x>>k;
		t=judge(x,k);
		if(t!=-1)cout<<t<<endl;
		else cout<<"None"<<endl;
	}
	return 0;
}

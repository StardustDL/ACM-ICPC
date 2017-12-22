/*
判断一个序列是否可图 
*/ 
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=10;
int d[MAXN+3],r[MAXN+3],ans[MAXN+3][MAXN+3];
bool cmp(const int i,const int j){
	return d[i]>=d[j];
}
int t,n;
void no(){
	cout<<"NO"<<endl<<endl;
}
void yes(){
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void test(){
	for(int tt=1;tt<=n;tt++){
				cout<<d[r[tt]]<<" ";
			}
			cout<<endl;
}
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		memset(d,0,sizeof(d));
		memset(r,0,sizeof(r));
		memset(ans,0,sizeof(ans));
		for(int j=1;j<=n;j++){
			cin>>d[j];
			r[j]=j;
		}
		int j=1;
		bool done=0;
		while(j<=n){
			sort(r+j,r+n+1,cmp);
			//test();
			int dgr=d[r[j]];
			if(dgr>n-j){
				//cout<<dgr<<" "<<n-j<<endl;
				no();done=1;break;
			}
			for(int k=j+1;k<=j+dgr;k++){
				if(--d[r[k]]<0){
					//cout<<"!!!"<<endl;
					done=1;no();break;
				}
				ans[r[j]][r[k]]=ans[r[k]][r[j]]=1;
			}
			if(done)break;
			j++;
		}
		if(done)continue;
		yes();
	}
	return 0;
}

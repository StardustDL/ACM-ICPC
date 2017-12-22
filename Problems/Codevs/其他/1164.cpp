/*
Í³¼ÆÊý×Ö
*/
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
map<int,int> m;
int n,t,a[10003],an=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(!m.count(t)){
			m[t]=1;
			a[++an]=t;
		}
		else m[t]++;
	}
	sort(a+1,a+an+1);
	for(int i=1;i<=an;i++)
		cout<<a[i]<<" "<<m[a[i]]<<endl;
	return 0;
}

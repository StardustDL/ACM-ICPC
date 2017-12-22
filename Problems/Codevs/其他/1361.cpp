/*
ÖªÊ¶ÅÅÃû
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct rk{
	int id,sco,ro[1001];
	bool operator < (const rk &t)const{
		return (sco>t.sco)||((sco==t.sco)&&(id<t.id));
	}
}rs[1001];
int wrong[1001];
int main()
{
	int id,n,m;
	cin>>id>>n>>m;
	for(int i=0;i<n;i++){
		rs[i].id = i+1;
		for(int j=0;j<m;j++){
			cin>>rs[i].ro[j];
			if(rs[i].ro[j]==0)wrong[j]++;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			rs[i].sco+=rs[i].ro[j]*wrong[j];
	sort(rs,rs+n);
	for(int i=0;i<n;i++)
		if(rs[i].id == id){
			cout<<i+1;
			break;
		}
	return 0;
}

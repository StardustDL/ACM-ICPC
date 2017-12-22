/*
»¨Éú²ÉÕª
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
struct field{
	int x,y,v;
	field(int x,int y,int v):x(x),y(y),v(v){} 
	bool operator <(const field &t)const{
		return v>t.v;
	}
};
inline int dist(field &a,field &b){
	//cout<<a.x<<" "<<b.x<<" "<<a.y<<" "<<b.y<<endl;
	return abs(a.x-b.x)+abs(a.y-b.y);
}
vector<field> v;
int n,m,k;
int main(){
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1,t;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&t);
			if(t)v.push_back(field(i,j,t));
		}
	} 
	sort(v.begin(),v.end());
	int t=0,i=0,ans=0;
	while(t<k&&i<v.size()){
		if(i==0){
			t+=v[i].x+1;
			if(t+v[i].x>k)break;
			ans+=v[i].v;
		}
		else{
			//cout<<dist(v[i],v[i-1])<<endl;
			t+=dist(v[i],v[i-1])+1;
			if(t+v[i].x>k)break;
			ans+=v[i].v;
		}
		//cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].v<<" "<<t<<endl;
		i++;
	}
	printf("%d\n",ans);
	return 0;
}


/*
×î½ü¾àÀë
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define sqr(x) ((x)*(x))
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
struct point{
	double x,y;
}ps[MAXN+3];
int n,a1,a2;
double mn=INT_MAX;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){cin>>ps[i].x>>ps[i].y;ps[i].x/=100;ps[i].y/=100;}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			double t=sqr(ps[i].x-ps[j].x)+sqr(ps[i].y-ps[j].y);
			if(t<mn){
				mn=t;
				a1=i,a2=j;
			}
		}
	}
	cout<<a1<<" "<<a2<<endl;
	return 0;
}


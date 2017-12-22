/*

*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
int midpos,n,a[MAXN+3];
bool check(int val){
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt+=n-(lower_bound(a+i,a+n,a[i]+val)-a);//get how many number >=a[i]+val 
	}//val is the (cnt)-th small in the array 
	return cnt>midpos;
}
int main(){
	while(~scanf("%d",&n)){
		midpos=n*(n-1)/4;
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		sort(a,a+n);
		int l=0,r=a[n-1]-a[0],ans=l;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}


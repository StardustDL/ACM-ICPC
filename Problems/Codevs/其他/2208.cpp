/*
矩形分割
分析：贪心即可，首先肯定先选大的切，这样大的不会更大，
	  然后如果竖着切，横向段数会+1，如果横着切，纵向段数会+1 
	  共计需要切n+m-2次 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2000;
int n,m,x=1,y=1,r[MAXN+3],c[MAXN+3],ans=0,len;
int main(){
	cin>>n>>m;
	for(int i=1;i<n;i++)cin>>r[i];
	for(int i=1;i<m;i++)cin>>c[i];
	sort(r+1,r+n);
	sort(c+1,c+m);
	len=n+m-2;//这里要先存下来，之后n,m会改变 
	for(int i=1;i<=len;i++){
		if(r[n-1]<c[m-1]){//竖着切 
			x++;ans+=y*c[--m];
		}
		else{
			y++;ans+=x*r[--n];
		}
	}
	cout<<ans;
	return 0;
} 

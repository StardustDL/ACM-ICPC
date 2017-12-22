/*
硬币
分析：类似完全背包的方法，注意初值和面值上界，此题要求必须装满，所以装之前要检查 
*/
#include<iostream>
using namespace std;
const int MAXW=103,MAXV=(MAXW/2)*50;
int w,n,v,mx,mn,mxv=0,ans=0;
bool opt[MAXW][MAXV+3];
int main(){
	ios::sync_with_stdio(false);
	cin>>w>>n;
	opt[0][0]=true;//计数问题一定要赋初值 
	while(n-->0){
		cin>>v>>mn>>mx;
		for(int i=mn;i<=mx;i++){//枚举质量 
			for(int j=i;j<=w;j++){//完全背包枚举质量 
				for(int k=0;k<=mxv;k++){//枚举面值，要从0开始 
					if(opt[j-i][k]){
						opt[j][k+v]=true;
						mxv=max(mxv,k+v); 
					}
				}
			}
		}
	}
	for(int i=0;i<=mxv;i++){
		ans+=opt[w][i];
	}
	cout<<ans;
	return 0;
}

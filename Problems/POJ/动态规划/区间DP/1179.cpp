/*
Polygon
题意：一个环中有n个点，每两个点之间有一条边，边的权值是一个字符（*，+）代表这前后的关系运算；求去掉任一条边，然后合并剩下的n - 1条边的能够计算得到的最大值； 
分析：读了很久题，但还是理解错了，不过其实就是能量项链的升级版（含加法），注意负负得正，可能更优，所以同时维护最小值 
	  状态：maDP[i][j]表示区间[j,j+i-1]的最大值，注意这里状态与以往不同，这样可以利用MOD代替之前的断环成链，但是不那么直观了，并且j的下标要从0开始 
	  转移方程：
	  	加法1：maDp[i][j] = max(maDp[i][j],maDp[k][j]+maDp[i-k][(k+j)%n]);
	 	加法2：miDp[i][j] = min(miDp[i][j],miDp[k][j]+miDp[i-k][(k+j)%n]);
		乘法1：maDp[i][j] = max(maDp[i][j],
    		                    maDp[k][j]*maDp[i-k][(k+j)%n],
                        	 	miDp[k][j]*miDp[i-k][(k+j)%n]);
		乘法2：miDp[i][j] = min(miDp[i][j],
                        		maDp[k][j]*maDp[i-k][(k+j)%n],
                        		miDp[k][j]*miDp[i-k][(k+j)%n],
                        		maDp[k][j]*miDp[i-k][(k+j)%n],
                        		miDp[k][j]*maDp[i-k][(k+j)%n]); 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector> 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=52;
int miDp[MAXN][MAXN],maDp[MAXN][MAXN],n,ans; 
char sym[MAXN];//记录符号 
vector<int> vec;//记录答案 
int main(){
	int num; 
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>sym[i]>>num;
        maDp[1][i]=miDp[1][i]=num;
    }
    for(int i=2;i<=n;i++)//枚举区间长度 
        for(int j=0;j<n;j++){//枚举区间起点 
            maDp[i][j]=-INF;
            miDp[i][j]=INF;
            for(int k=1;k<i;k++){//枚举划分点 
                if(sym[(k+j)%n]=='t'){
                    maDp[i][j]=max(maDp[i][j],
                        maDp[k][j]+maDp[i-k][(k+j)%n]);
                    miDp[i][j]=min(miDp[i][j],
                        miDp[k][j]+miDp[i-k][(k+j)%n]);
                }else{
                    maDp[i][j]=max(maDp[i][j],
                        max(maDp[k][j]*maDp[i-k][(k+j)%n],miDp[k][j]*miDp[i-k][(k+j)%n]));
                    miDp[i][j]=min(miDp[i][j],min(
                        min(maDp[k][j]*maDp[i-k][(k+j)%n],miDp[k][j]*miDp[i-k][(k+j)%n]),
                        min(maDp[k][j]*miDp[i-k][(k+j)%n],miDp[k][j]*maDp[i-k][(k+j)%n])));
                }
            }
        }
    ans=-INF;
    for(int i=0;i<n;i++){
        if(maDp[n][i]==ans)vec.push_back(i);
		else if(maDp[n][i]>ans){//生成答案，可能有多个位置都能得到最优解 
            ans=maDp[n][i];
            vec.clear();
            vec.push_back(i);
        }
    }
    printf("%d\n",ans);
    for(int i=0;i<vec.size();i++)printf("%d ",vec[i]+1);
    printf("\n");
    return 0;
}

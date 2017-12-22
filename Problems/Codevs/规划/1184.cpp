/*
瓷砖覆盖
分析：状态压缩DP 
	  用2进制的01表示不放还是放，第i行只和i-1行有关，枚举i-1行的每个状态，推出由此状态能达到的i行状态：
	  如果i-1行的出发状态某处未放，必然要在i行放一个竖的方块，所以对上一行状态按位取反之后的状态就是放置了竖方块的状态。
	  然后用dfs搜索在i行放横着的方块的所有可能，并且把这些状态累加上i-1的出发状态的方法数，如果该方法数为0，直接continue。
	  很巧妙的位运算技巧 
*/ 
#include<iostream>
#include<cstring>
using namespace std;
typedef int LL; 
const int MOD=100003;
int n,m;
LL dp[50000+3][1<<6+1];
void dfs(int row,int state,int pos,LL pre_num){//pos:横向瓷砖位置 
	if(pos==m){
		dp[row][state]=(dp[row][state]+pre_num)%MOD;
		return;
	}
	dfs(row,state,pos+1,pre_num);//不放
	if((pos<=m-2)&&!(state&(1<<pos))&&!(state&(1<<(pos+1))))//该列和下一列放置一块横向的瓷砖
		dfs(row,state|(1<<pos)|(1<<(pos+1)),pos+2,pre_num);
}
int main(){	
	while(cin>>n>>m){
		if(n<m){//较小的数进行状压 
			swap(n,m);
		}
		memset(dp,0,sizeof(dp));
		dfs(1,0,0,1);//初始化第一行
		for(int i=2;i<=n;i++) 
			for(int j=0;j<(1<<m);j++){
				if(dp[i-1][j]){
					//如果i-1行的出发状态某处未放，必然要在i行放一个竖的方块，所以对上一行状态按位取反之后的状态就是放置了竖方块的状态
					dfs(i,(~j)&((1<<m)-1),0,dp[i-1][j]);
				}
				else continue;
			}

		/** 注意并不是循环i 输出 dp[n][i]中的最大值 */
		cout<<dp[n][(1<<m)-1]; 
		break;
	}
	return 0;
}

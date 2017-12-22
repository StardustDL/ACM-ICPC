/*
Cow Relays
题意：问从S 到 T 经过边的个数恰为k的最短路是多少。
分析：Floyd配合快速幂，注意不是简单的矩阵乘，这是最短路问题
	  floyd是每次使用一个中间点k去更新i,j之间的距离，那么更新成功表示i,j之间恰有一个点k时的最短路，
	  	如果做N - 1次floyd那么不就是i,j之间借助N - 1 个点时的最短路了。
	  	floyd每次更新的都是本身，假如k=3时，dis[1][5]借助dis[1][3]和dis[3][5]成为最短路。
	  	不需要去知道1,3之间有多少个点，因为前面已经求出，只知道这一次求出的dis[1][5]多加了一个3这个点。
	  回到这题，floyd算法是对自身矩阵更新，而这道题却是更新到另一个矩阵上，所以不会出现刚更新过的值又来更新。更新k次即可 
	  1、N次floyd可以用倍增思想加速，就是自底向上的二分。类似求矩阵快速幂。
	  2、这里还有一点要注意，T的范围是(2~100),所以最多顶点只有200，而顶点标号的范围却(1 ≤ I1i ≤ 1,000; 1 ≤ I2i ≤ 1,000)。这样我们可以将编号离散化。
	  3、最后一点这个题的inf要开很大，可能会爆。把inf定义为-1。就没这个问题了。
*/
#include<iostream>
#include<cstring> 
using namespace std;
const int MAX=105;
const int NMAX=1005;
struct Matrix{
	int v[MAX][MAX];
    Matrix(){memset(v,-1,sizeof(v));}
};
int N=0,hash[NMAX];
Matrix mtMul(Matrix A,Matrix B){
    int i,j,k,tmp;
    Matrix C;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            for(k=0;k<N;k++){
                if(A.v[i][k]==-1 || B.v[k][j]==-1)continue;
                tmp=A.v[i][k]+B.v[k][j];
                if(C.v[i][j]==-1 || C.v[i][j]>tmp)C.v[i][j]=tmp;
            }
    return C;}
Matrix mtPow(Matrix A, int k){
    if(k==1)return A;
    Matrix B=mtPow(A,k/2);
    if(k&1)return mtMul(mtMul(B,B),A);
	else return mtMul(B,B);
}
int main(){
    int n,t,s,e,i;
    memset(hash,-1,sizeof(hash));
    cin>>n>>t>>s>>e;
    Matrix A;
    for(i=0;i<t;i++){
        int len,u,v;
        cin>>len>>u>>v;
        if(hash[u]==-1)hash[u]=N++;//编号简单离散下，这种方法应该是最简的吧。
        if(hash[v]==-1)hash[v]=N++;
        A.v[hash[u]][hash[v]]=len;
        A.v[hash[v]][hash[u]]=len;
    }
    A=mtPow(A,n);
    printf("%d\n",A.v[hash[s]][hash[e]]);
    return 0;
}

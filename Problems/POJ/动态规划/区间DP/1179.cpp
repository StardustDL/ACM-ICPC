/*
Polygon
���⣺һ��������n���㣬ÿ������֮����һ���ߣ��ߵ�Ȩֵ��һ���ַ���*��+��������ǰ��Ĺ�ϵ���㣻��ȥ����һ���ߣ�Ȼ��ϲ�ʣ�µ�n - 1���ߵ��ܹ�����õ������ֵ�� 
���������˺ܾ��⣬�����������ˣ�������ʵ�������������������棨���ӷ�����ע�⸺�����������ܸ��ţ�����ͬʱά����Сֵ 
	  ״̬��maDP[i][j]��ʾ����[j,j+i-1]�����ֵ��ע������״̬��������ͬ��������������MOD����֮ǰ�Ķϻ����������ǲ���ôֱ���ˣ�����j���±�Ҫ��0��ʼ 
	  ת�Ʒ��̣�
	  	�ӷ�1��maDp[i][j] = max(maDp[i][j],maDp[k][j]+maDp[i-k][(k+j)%n]);
	 	�ӷ�2��miDp[i][j] = min(miDp[i][j],miDp[k][j]+miDp[i-k][(k+j)%n]);
		�˷�1��maDp[i][j] = max(maDp[i][j],
    		                    maDp[k][j]*maDp[i-k][(k+j)%n],
                        	 	miDp[k][j]*miDp[i-k][(k+j)%n]);
		�˷�2��miDp[i][j] = min(miDp[i][j],
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
char sym[MAXN];//��¼���� 
vector<int> vec;//��¼�� 
int main(){
	int num; 
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>sym[i]>>num;
        maDp[1][i]=miDp[1][i]=num;
    }
    for(int i=2;i<=n;i++)//ö�����䳤�� 
        for(int j=0;j<n;j++){//ö��������� 
            maDp[i][j]=-INF;
            miDp[i][j]=INF;
            for(int k=1;k<i;k++){//ö�ٻ��ֵ� 
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
		else if(maDp[n][i]>ans){//���ɴ𰸣������ж��λ�ö��ܵõ����Ž� 
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

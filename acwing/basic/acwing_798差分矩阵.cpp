#include<iostream>
using namespace std;

const int N = 1010;
int b[N][N];
int a[N][N];
void insert(int x1,int y1,int x2,int y2,int c){
    b[x1][y1] += c;
    b[x2+1][y2+1] += c;
    b[x2+1][y1] -= c;
    b[x1][y2+1] -= c;
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    //输入
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            scanf("%d",&a[i][j]);
    //构造差分序列
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            // b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1] + a[i][j];
            insert(i,j,i,j,a[i][j]);
        }
    }
    while (q--)
    {
        
        int x1,x2,y1,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        //修改差分矩阵
        insert(x1,y1,x2,y2,c);
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            b[i][j] += b[i-1][j]+b[i][j-1]-b[i-1][j-1];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
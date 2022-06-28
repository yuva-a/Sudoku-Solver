#include<bits/stdc++.h>
using namespace std;

int check=0;
int a[9][9]={0};
int r[9][10]={0};
int c[9][10]={0};
int b[9][10]={0};

void solve(int,int);
void next(int,int);

int32_t main()
{

    {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    }
        

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            int x; cin>>x;
            a[i][j]=x;
            r[i][x]++;
            c[j][x]++;
            b[3*(i/3)+j/3][x]++;
        }
    }

    solve(0,0);

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            {cout<<a[i][j]<<" ";}
        cout<<endl;
    }
    
}

void solve(int x,int y)
{
    if(check==1)return;
    
    if(a[x][y]!=0)next(x,y);
    else 
    {
        for(int i=1;i<=9;i++)
        {
            if(r[x][i]!=0 || c[y][i]!=0 || b[3*(x/3)+y/3][i]!=0)continue;
            a[x][y]=i;
            r[x][i]=1;
            c[y][i]=1;
            b[3*(x/3)+y/3][i]=1;
            next(x,y);
            if(check==1)return;
            a[x][y]=0;
            r[x][i]=0;
            c[y][i]=0;
            b[3*(x/3)+y/3][i]=0;
        }
    }
}

void next(int x,int y)
{
    if(x==8 && y==8){check=1; return;}
    if(y==8){solve(x+1,0);}
    else
    {
        solve(x,y+1);
    }
}
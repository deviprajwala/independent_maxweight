#include<stdio.h>

void input(int matrix[25][25],int n,int w[25],int g[25]);
int max(int w[25],int n,int g[25]);
void del(int x,int g[25],int matrix[25][25],int n);
void printmax(int s[25],int j,int w[25]);
int check(int g[25],int n);

void main()
{
  int s[25],g[25],w[25],matrix[25][25],x,j,n,c;
  j=0;
  printf("enter the size of matrix\n");
  scanf("%d",&n);
  input(matrix,n,w,g);
  
  while(c!=1)
  {
    x=max(w,n,g);
    s[j]=x;
    j++;
    del(x-1,g,matrix,n); 
    c=check(g,n);  
  }
  printmax(s,j,w);
}

void input(int matrix[25][25],int n,int w[25],int g[25])
{
 int i,j;
 printf("enter the matrix elements\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
  scanf("%d",&matrix[i][j]);
  }
 }
 printf("enter the weight of matrix\n");
 for(j=0;j<n;j++)
  {
  scanf("%d",&w[j]);
  }
 printf("enter the nodes of graph\n");
 for(j=0;j<n;j++)
  {
  scanf("%d",&g[j]);
  }


}
int max(int w[25],int n,int g[25])
{
 int maxi,val,i;
 maxi=w[0];
 for(i=1;i<n;i++)
 {
  if(w[i]>maxi&&g[i]!=0)
  {
    maxi=w[i];
    val=i;
  }
 }
return val+1;
}

void del(int x,int g[25],int matrix[25][25],int n)
{
 int j,p;
 for(j=0;j<n;j++)
 {
  if(matrix[x][j]==1)
   {
     g[j]=0;
     g[x]=0;
     for(p=0;p<n;p++)
     {
     matrix[x][p]=0;
     matrix[j][p]=0;
     
     }
   }
 }  
}

void printmax(int s[25],int j,int w[25])
{
 int max,a,i;
 max=w[s[0]];
 for(i=1;i<j;i++)
 {
  if(w[s[i]]>max)
  {
   max=w[s[i]];
   a=s[i];
  }
 }
 printf("Weight is %d,Node is %d\n",max,a+1);
}
int check(int g[25],int n)
{
 int count=0,i;
 for(i=0;i<n;i++)
 {
  if(g[i]==0)
  {
    count++;
  }
 }
 if(count==n)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}

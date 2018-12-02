#include<stdio.h>
void print(int m,int n,int t,int l,int arr[t],int fill[m][n]){
  int i,j,x;
  printf("\n");
  for(i=0;i<=m;i++){
    for(j=0;j<n;j++){
      if(arr[i*(2*n+1)+j+1]==1)printf(".""\x1b[32m""______\t""\x1b[0m");
      else if(arr[i*(2*n+1)+j+1]==2)printf(".""\x1b[31m""______\t""\x1b[0m");
      else printf(". _%d_\t",i*(2*n+1)+j+1);
      if(j==n-1)printf(".\n");
    }
    if(i<m){
      for(int k=0;k<2;k++){for(j=0;j<=n;j++){
          if(arr[x=i*(2*n+1)+j+1+n]==1)printf("\x1b[32m""|""\x1b[0m");
          else if(arr[x=i*(2*n+1)+j+1+n]==2)printf("\x1b[31m""|""\x1b[0m");
          else printf("%d",x);
          if(j<n&&arr[x]!=0&&arr[x+1]!=0&&arr[x-n]!=0&&arr[x+n+1]!=0){
            if(l%2==0&&fill[i][j]==0||fill[i][j]==2){printf("\x1b[32m""Green""\x1b[0m");fill[i][j]=2;}
            else if(fill[i][j]==0||fill[i][j]==1){printf("\x1b[31m""Red""\x1b[0m");fill[i][j]=1;}
          }
          if(j<n)printf("\t");
          else printf("\n");
        }
      }
    }
  }
  printf("\n");
}
void play(int m,int n,int t,int arr[t],int fill[m][n]){
  int k=0,w;
  while(1){
    if(k%2)printf("\x1b[33m""It is red's turn\n""\x1b[0m");
    else printf("\x1b[33m""It is green's turn\n""\x1b[0m");
    printf("\x1b[33m""Enter position of (where)w:""\x1b[0m");
    scanf("%d",&w);
    if(arr[w]==0&&w<=t&&w>0){
      arr[w]=(k%2)?2:1;
      print(m,n,t,k,arr,fill);
      if(++k==t)break;
    }
    else printf("\x1b[31m""INVALID\n""\x1b[0m");
  }
}
void print_result(int m,int n,int t,int arr[t],int fill[m][n]){
  int i,j,r=0,g=0;
  for(i=0;i<m;i++)for(j=0;j<n;j++)
      if(fill[i][j]==1)r++;
      else if(fill[i][j]==2)g++;
  if(r>g)printf("\x1b[33m""Red wins\n""\x1b[0m");
  if(g>r)printf("\x1b[33m""Green wins\n""\x1b[0m");
  if(r==g)printf("\x1b[33m""Game draw\n""\x1b[0m");
}
int main(){
  int m,n,i,j;
  printf("\x1b[33m""Enter number of rows:""\x1b[0m");
  scanf("%d",&m);
  printf("\x1b[33m""Enter number of columns:""\x1b[0m");
  scanf("%d",&n);
  int t=m*(2*n+1)+n;
  int arr[t],fill[m][n];
  for(i=0;i<m;i++)for(j=0;j<n;j++)fill[i][j]=0;
  for(i=0;i<=t;i++)arr[i]=0;
  print(m,n,t,0,arr,fill);
  play(m,n,t,arr,fill);
  print_result(m,n,t,arr,fill);
  return 0;
}

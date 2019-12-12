#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int Partesion(int a[],int start,int end)
{
  int pivot=a[end],Pindex=start,i;
  for(i=start;i<=end-1;i++)
  {
    if(a[i]<=pivot)
    {
      swap(a[i],a[Pindex]);
      Pindex++;
    }
  }
  swap(a[end],a[Pindex]);
  return Pindex;
}
void Quick_Sort(int a[],int start,int end)
{
  if(start<end)
  {
    int pindex=Partesion(a,start,end);
    Quick_Sort(a,start,pindex-1);
    Quick_Sort(a,pindex+1,end);
  }
}
int main()
{
  int a[]={8,9,6,37,36,0,2,11,1},i,n;
  n=sizeof(a)/sizeof(a[0]);
  Quick_Sort(a,0,n-1);
  for(i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<endl;
}

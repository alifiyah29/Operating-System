    
#include<bits/stdc++.h>
using namespace std;
#define max 10
class BestFit
{
	public:
		int n,pro_size[max],block_size[5]={100,500,200,400,300},index[5]={1,2,3,4,5},temp;
		void getdata()
		{
			cout<<"Enter number of processes"<<endl;
			cin>>n;
			cout<<"Enter the size of processes"<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<"Process "<<i+1<<": ";
				cin>>pro_size[i];
			}
		}
		void calculation()
		{
			for(int i=0;i<=3;i++)
			{
				for(int j=0;j<=3-i;j++)
				{
					if(block_size[j]>block_size[j+1])
					{
						temp=block_size[j];
						block_size[j]=block_size[j+1];
						block_size[j+1]=temp;
					
						temp=index[j];
						index[j]=index[j+1];
						index[j+1]=temp;
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<5;j++)
				{	
					if((pro_size[i]<=block_size[j]) && (index[j]!=-1))
					{
						cout<<"Index of process in memory for process "<<i+1<<":"<<index[j]<<endl;
						index[j]=-1;
						break;	
					}
					if((j==4) && (pro_size[i]>block_size[j]))	
					cout<<"No memory is allocated to process "<<i+1<<endl;	
				}	
			}
		}
};
int main()
{
	BestFit obj;
	obj.getdata();
	cout<<"Memory slots :"<<endl;
	for(int i=0;i<5;i++)
	cout<<obj.block_size[i]<<",";
	cout<<endl;
	obj.calculation();
}

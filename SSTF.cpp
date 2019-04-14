#include<bits/stdc++.h>
using namespace std;
int main()
{
	int requests,head_pos,i,j,TotalDist=0,temp;
	int a[50],st[50],dist[50];
	
	cout<<"enter the no. of requests= ";
	cin>>requests;
	cout<<"Enter the position of head= ";
	cin>>head_pos;
	cout<<"enter the elements in queue:\n";
	for(i=0;i<requests;i++)
		cin>>a[i];
	 //distance of head from each element in queue
	for(i=0;i<requests;i++)
    	dist[i]=abs(head_pos-a[i]);
     //sort elements based on distance
     for(i=0;i<requests;i++){
     	for(j=i+1;j<requests;j++)
     		if(dist[i]>dist[j]){
     	 		temp=dist[i];
     	 		dist[i]=dist[j];
     	 		dist[j]=temp;
     	 	
     	 		temp=a[i];
     	 		a[i]=a[j];
     	 		a[j]=temp;
		  	}
	 	}
		for(i=1;i<requests;i++){
	 		TotalDist+=abs(head_pos-a[i]);
	 		head_pos=a[i];
	 	}
	 	cout<<"Total Distance= "<<TotalDist;
		return 0;	
}

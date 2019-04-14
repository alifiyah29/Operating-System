#include<bits/stdc++.h>
using namespace std;
int main(){
	int pages,frames,page[20],i,count=0;
    cout<<"Enter the No. of Pages= ";
    cin>>pages; 
    cout<<"Enter the Reference String:\n";
    for(i=0;i<pages;i++)
        cin>>page[i];
    cout<<"Enter the No of frames = ";
    cin>>frames;
    int frame[frames],frame_count[frames];
    for(i=0;i<frames;i++){
        frame[i]=-1; //Store the frames
        frame_count[i]=0; //Track when the page is last used
	    }
    i=0;
    while(i<pages){
        int j=0,flag=0;
        while(j<frames){
            if(page[i]==frame[j]){  //Checking whether page already exist in frames or not (Hit condition)
            flag=1;
            frame_count[j]=i+1;
            }
            j++;
        }   
 	    j=0;  
        if(flag==0){
            int min=0,k=0;
            while(k<frames-1){
	        if(frame_count[min]>frame_count[k+1]) //Calculating the page which is least recently used
                min=k+1;
                k++;
            }
            frame[min]=page[i]; //Replacing it
            frame_count[min]=i+1; //Increasing the time of the page
            count++;           //counting Page Fault
		    while(j<frames){
	           j++;
            }
	    }
	    i++; 
   }
   cout<<"Page Fault is = "<<count;
   return 0;
}       


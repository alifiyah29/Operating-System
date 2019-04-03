//Banker's Algorithm

#include<iostream>
#define m 100
using namespace std;

class BankersAlgorithm{
	public:
		int process,resource,allocation[m][m],max[m][m],available[m],need[m][m],finish[m],work[m];
		void getdata(){
			cout<<"Enter number of processes= ";
			cin>>process; //5
			cout<<"Enter number of resources= ";
			cin>>resource; //4
			// Allocation Matrix
			cout<<"Enter Allocation Matrix:\n";
			for(int i=0;i<process;i++){
				for(int j=0;j<resource;j++)
					cin>>allocation[i][j];
			}
			//Max Matrix
			cout<<"Enter Max Matrix:\n";
			for(int i=0;i<process;i++){
				for(int j=0;j<resource;j++)
					cin>>max[i][j];
			}
			//Availabile Resources
			cout<<"Enter Availability ";
			for(int j=0;j<resource;j++)
				cin>>available[j];
		}
		void bankAlgo(){
			//Initialise finish 0
			for(int i=0;i<process;i++)
				finish[i]=0;
			// Calculation of need Matrix
			for(int i=0;i<process;i++){
				for(int j=0;j<resource;j++){
					need[i][j]=max[i][j]-allocation[i][j];	
				}
			} 
			int counter=0;
    		for (int k=0;k<process;k++){ 
        		for(int i=0;i<process;i++){ 
            		if(finish[i]==0){ 
                		int flag=0; 
                		for (int j=0;j<m;j++){ 
                    		if(need[i][j]>available[j]) 
                        		flag=1; 
                    		break;
						} 
                		if (flag==0){ 
                			work[counter++]=i; 
                			for(int y=0;y<m;y++) 
                				available[y]+=allocation[i][y]; 
                    		finish[i]=1; 
               			} 
            		} 
        		} 
    		}	
		for(int i=0;i<process;i++){
			if(finish[i]==1)
				cout<<"Safe Sequence"<<endl;
			break;
			if(finish[i]!=0)	
				cout<<"Not a Safe Sequence"<<endl;
			break;	
		}			
	}
};

int main(){
	BankersAlgorithm obj;
	obj.getdata();
	obj.bankAlgo();
	return 0;
}

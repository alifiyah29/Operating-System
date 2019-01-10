#include<iostream>
#define max 100
using namespace std;
class Schedule{
	public:
	int n,i;
	double arr[max],exe[max],ct=0.0,tat=0.0,wt=0.0,atat=0.0,awt=0.0,stat,swt;
	void getdata(){
		cout<<"Enter number of process\n";
		cin>>n;
		cout<<"Enter arrival time\n";
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<"Enter bus/execution time\n";	
		for(int i=0;i<n;i++)	
		cin>>exe[i];
	}
	void time_cal(){
		for(int i=0;i<n;i++){
			if(ct>arr[i]){
			ct+=exe[i];
			tat=ct-arr[i];
			wt=tat-exe[i];
			cout<<"Turn around time "<<tat<<"       "<<"Waiting time "<<wt<<endl;		
		}
		else{
			ct=arr[i]+exe[i];
			tat=ct-arr[i];
			wt=tat-exe[i];
			cout<<"Turn around time "<<tat<<"       "<<"Waiting time "<<wt<<endl;			
		}
		stat+=tat;
		swt+=wt;
	}
	atat=stat/n;
	awt=swt/n;
	cout<<"\nAverage turn around time= "<<atat<<endl;
	cout<<"Average waiting time= "<<awt<<endl;
		}
};
int main(){
	Schedule obj;
	obj.getdata();
	obj.time_cal();
	return 0;
}

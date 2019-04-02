#include<iostream>
#define max 1000
using namespace std;
class FirstFit{
	public:
		int process,block,block_size[max],process_size[max];
		void getData(){
			cout<<"Enter number of blocks ";
			cin>>block;
			cout<<"Enter  Block Size"<<endl;
			for(int i=0;i<block;i++)
				cin>>block_size[i];
			cout<<"Enter number of process"<<endl;
			cin>>process;
			cout<<"Enter Process size"<<endl;
   			for(int i=0;i<process;i++)
				cin>>process_size[i];
		}
		void firstFit(){
			for(int i=0;i<process;i++){
				int flag=1;
	 			for(int j=0;j<block;j++){
	   				if(process_size[i]<=block_size[j]){
	   				flag=0;
	   				cout<<"Space allocated in Block number="<<j+1<<" process number="<<i+1<<endl;
					block_size[j]-=process_size[i];		
					break;
				}	
	  		}
	  		if(flag==1)
	  		cout<<"Process "<<i+1<<" is not allocatd"<<endl;
			}			
		}	
};
int main()
{
FirstFit obj;
obj.getData();
obj.firstFit();
return 0;		
}

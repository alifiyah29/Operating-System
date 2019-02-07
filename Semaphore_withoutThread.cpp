#include<iostream>
#define max 5
using namespace std;
class Semaphore{
	public:
		int S=1,E=5,F=0,a[max],item;
		
		int wait(int S){
			return(--S);
		}
		
		int signal(int S){
			return(++S);
		}
		
		void producer(){
				E=wait(E);//Entry
				S=wait(S);//Entry
				cout<<"Producing\n";
				a[F]=item;
				cout<<"Buffer utilized = "<<F+1<<endl;
				cout<<"Buffer left = "<<E<<endl;
				S=signal(S);//Exit
				F=signal(F);//Exit
		}
		
		void consumer(){
				F=wait(F);//Entry
				S=wait(S);//Entry
				cout<<"Consuming\n";
				item=a[E];
				cout<<"Buffer utilized = "<<F+1<<endl;
				cout<<"Buffer left = "<<E<<endl;				
				S=signal(S);//Exit
				S=signal(E);//Exit
		}
};
int main(){
	Semaphore obj;
	int choice;
	while(1){
		cout<<"Enter 1 for Producer\n";
		cout<<"Enter 2 for Consumer\n";
		cout<<"Enter 3 for Exit\n";
		cin>>choice;
		switch(choice){
			case 1:
				{
					if(obj.S==1&&(obj.E!=0))
						obj.producer();
					else
						cout<<"Buffer is full\n";	
					break;				
				}
			case 2:
				{
						if((obj.S==1)&&(obj.F!=0))
							obj.consumer();
						else
							cout<<"Buffer is empty\n";
						break;		
				}		
			case 3:
				{
					exit(0);
					break;
				}	
			}	
	}	
	return 0;
}

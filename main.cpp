	#include <iostream>

	using namespace std;


	int main()
	{
		float eqn[3][4];
		cout<<"------------------ Gauss Siedal Iteration method ----------------\n\n";

		for(int i=0;i<3;i++){
		cout <<"Enter the "<<(i+1)<<" th equation detail\n\n";
		cout  <<"X coefficient  = ";
		cin>>eqn[i][0];
		cout  <<"\nY coefficient  = ";
		cin>>eqn[i][1];
		cout  <<"\nZ coefficient  = ";
		cin>>eqn[i][2];
		cout<<"\nConstant value = ";
		cin>>eqn[i][3];cout<<endl;
		}
		int memo[3];
		//Checking and storing diagonal Dominate
		for(int i=0;i<3;i++){
        if(eqn[i][0]>eqn[i][1] && eqn[i][0]>eqn[i][2]){
            memo[0]=i;
        }
        else if(eqn[i][1]>eqn[i][0] && eqn[i][1]>eqn[i][2]){
            memo[1]=i;
        }
        else{memo[2]=i;}
		}
		//creating x , y, z iterator memo
		float memo_x[100],memo_y[100],memo_z[100];
		memo_x[0]=0;memo_y[0]=0;memo_z[0]=0;
		//coping old equation in new equation
		float new_eqn[3][4];
		for(int i=0;i<3;i++){
		if(memo[0]==i){new_eqn[0][0]=eqn[i][0];new_eqn[0][1]=eqn[i][1];new_eqn[0][2]=eqn[i][2];
		new_eqn[0][3]=eqn[i][3];}
		else if(memo[1]==i){new_eqn[1][0]=eqn[i][0];new_eqn[1][1]=eqn[i][1];
		new_eqn[1][2]=eqn[i][2];new_eqn[1][3]=eqn[i][3];}
		else{new_eqn[2][0]=eqn[i][0];new_eqn[2][1]=eqn[i][1];new_eqn[2][2]=eqn[i][2];
		new_eqn[2][3]=eqn[i][3];}
		}
		int j=0;
		for(j=1;;j++){
		memo_x[j]= (1/new_eqn[0][0])*(new_eqn[0][3]-new_eqn[0][1]*memo_y[j-1]-new_eqn[0][2]*memo_z[j-1]);
		memo_y[j]=(1/new_eqn[1][1])*(new_eqn[1][3]-new_eqn[1][0]*memo_x[j]-new_eqn[1][2]*memo_z[j-1]);
		memo_z[j]=(1/new_eqn[2][2])*(new_eqn[2][3]-new_eqn[2][0]*memo_x[j]-new_eqn[2][1]*memo_y[j]);
		if(memo_x[j]==int(memo_x[j]) && memo_y[j]==int(memo_y[j]) && memo_z[j]==int(memo_z[j])){
        break;
		}
		}
		cout<<"Thus we have \n X = ";
		cout<<memo_x[j]<<"\n Y = "<<memo_y[j]<<"\n Z = "<<memo_z[j]<<endl;
		return 0;
	}

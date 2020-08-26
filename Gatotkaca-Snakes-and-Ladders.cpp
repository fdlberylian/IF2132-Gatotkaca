// "Gatotkaca" Snakes and Ladders
// A C++ game built for completing Computer Programming course project, November 2014

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;

int A[10][10]; //Array Board
int p[2], temp[2]; char b[2]; string n[2]; //p=player position, temp=temporary position if the player hit snake/ladder b=player pawn, n=player name

void menu(int *input) //Main Menu Procedure
{

    cout << "Game Menu" << endl;
    cout << "1. Start" << endl;
    cout << "2. Exit" << endl;
    cout << endl;

    cout << "Choose menu: ";
    	cin >> *input;
    while(*input>2||*input<1)
    {
        cout << "Menu unavaiable! Please try again" << endl;
        cout << "Game Menu" << endl;
    	cout << "1. Start" << endl;
    	cout << "2. Exit" << endl;
    	cout << endl;

    	cout << "Choose menu: ";
    		cin >> *input;
    }
}

void colorize(unsigned short color){ //Coloring
     HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hCon,color);
}

void createboard() //Building the game board
{
    int count1=0,i,j;
    
    do{
    	cout << " --------";
    	count1++;
    }while(count1<10);
    
    cout << endl;
    
    //Initialization for numbers on the game board
    for(i=0;i<10;i++)
       {
    	for(j=0;j<10;j++)
            {
         	    if(i%2==0){
					A[i][j] = 100 - 10*i - j;
          		  }
          		if(i%2==1){
					A[i][j] = 91 - 10*i + j;
          		  }      	
		}
			}
  				
  			i=0;
			do{
				for(j=0;j<10;j++){	  			
            		if(i==9&&j!=9){
						cout << "|"; colorize(13); cout << A[i][j] << "       "; colorize(15);
            		}
            		if(i==0&&j==0){
						cout << "|"; colorize(13); cout << A[i][j] << "     "; colorize(15);       			
            		}
            		if(i==0&&j!=0){
						cout << "|"; colorize(13); cout << A[i][j] << "      "; colorize(15);          			
            		}
            		if(i==9&&j==9){
						cout << "|"; colorize(13); cout << A[i][j] << "      "; colorize(15);
					}
            		if(i==1||i==2||i==3||i==4||i==5||i==6||i==7||i==8){
						cout << "|"; colorize(13); cout << A[i][j] << "      "; colorize(15);
            		}
        		}
        		cout << "|" << endl;

            	for(j=0;j<10;j++){
  				  	cout << "|        ";
  				  }
  				cout << "|" << endl; 
  				
            	for(j=0;j<10;j++){
            		if(i==0){
            			if(j==2){          			
  				  			cout << "|S       ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==5||j==6||j==7||j==8||j==9){
   				  			cout << "|        "; 				  			
  				  		}
					}
            		if(i==1){
            			if(j==7){
  				  			cout << "|L       ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==5||j==6||j==2||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}
            		if(i==2){
            			if(j==2){          			
  				  			cout << "|S       ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==5||j==6||j==7||j==8||j==9){
   				  			cout << "|        "; 				  			
  				  		}
					}
            		if(i==3){
            			if(j==7){
  				  			cout << "|L       ";
  				  		}
            			if(j==5){
  				  			cout << "|L       ";
  				  		}  				  		
  				  		if(j==0||j==1||j==3||j==4||j==6||j==2||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}
            		if(i==5){
            			if(j==1){
  				  			cout << "|S       ";
  				  		}				  		
  				  		if(j==0||j==5||j==7||j==3||j==4||j==6||j==2||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}
            		if(i==6){
            			if(j==7){
  				  			cout << "|L       ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==5||j==6||j==2||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}
            		if(i==7){
            			if(j==5){
  				  			cout << "|L       ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==7||j==6||j==2||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}
            		if(i==9){
            			if(j==2){
  				  			cout << "|L       ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==5||j==6||j==7||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}
            		if(i==4){
            			if(j==6){
  				  			cout << "|S       ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==5||j==2||j==7||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}					
					if(i==8){
   				  			cout << "|        ";  						
					}																																																		
  				  }
  				cout << "|" << endl; 
				   	
            	for(j=0;j<10;j++){
            		if(i==0){
            			if(j==2){          			
  				  			cout << "|to 84   ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==5||j==6||j==7||j==8||j==9){
   				  			cout << "|        "; 				  			
  				  		}
					}
            		if(i==1){
            			if(j==7){
  				  			cout << "|to 94   ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==5||j==6||j==2||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}
            		if(i==2){
            			if(j==2){          			
  				  			cout << "|to 20   ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==5||j==6||j==7||j==8||j==9){
   				  			cout << "|        "; 				  			
  				  		}
					}
            		if(i==3){
            			if(j==7){
  				  			cout << "|to 60   ";
  				  		}
            			if(j==5){
  				  			cout << "|to 76   ";
  				  		}  				  		
  				  		if(j==0||j==1||j==3||j==4||j==6||j==2||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}
            		if(i==5){
            			if(j==1){
  				  			cout << "|to 20   ";
  				  		}				  		
  				  		if(j==0||j==5||j==7||j==3||j==4||j==6||j==2||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}
            		if(i==6){
            			if(j==7){
  				  			cout << "|to 35   ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==5||j==6||j==2||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}
            		if(i==7){
            			if(j==5){
  				  			cout << "|to 41   ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==7||j==6||j==2||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}
            		if(i==9){
            			if(j==2){
  				  			cout << "|to 6    ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==5||j==6||j==7||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}
            		if(i==4){
            			if(j==6){
  				  			cout << "|to 44   ";
  				  		}
  				  		if(j==0||j==1||j==3||j==4||j==5||j==2||j==7||j==8||j==9){
   				  			cout << "|        ";   				  			
  				  		}
					}					
					if(i==8){
   				  			cout << "|        ";  						
					}		
  				  }
  				cout << "|" << endl;
  				
            	for(j=0;j<10;j++){ 	  			
  				  	cout << "|        ";
  				}
  				cout << "|" << endl;  				

            	for(j=0;j<10;j++){
            		if(p[0]==A[i][j]){      		
  				  		cout << "|"; colorize(11); cout << b[0] << "       "; colorize(15);
  				 	 }
            		if(p[0]!=A[i][j]){      		
  				  		cout << "|        ";
  				 	 }  				 	 
  				  }
  				cout << "|" << endl;  
				  
            	for(j=0;j<10;j++){
            		if(p[1]==A[i][j]){      		
  				  		cout << "|"; colorize(14); cout << b[1] << "       "; colorize(15);
  				 	 }
            		if(p[1]!=A[i][j]){      		
  				  		cout << "|        ";
  				 	 }  				 	 
  				  }
  				cout << "|" << endl;  	
				  				               
                for(j=0;j<10;j++){
    				cout << " --------";
    			}
    			cout << endl;
    		i++;	
            }while(i<10);
        
        cout << "Legend: " << endl;
        cout << "S=Snake, L=Ladder, "; colorize(11); cout << b[0]; colorize(15); cout << "=Pawn " << n[0] << ", "; colorize(14); cout << b[1]; colorize(15); cout << "=Pawn " << n[1] << endl;

}

void movement() //Movement of pawn
{
	bool f,u,t;
	f=false; u=false; t=false;
	int i,num;
	char go;
	
	while(!f){
		i=0;
		while(i<2&&!f){
			cout << "Player " << n[i] << " please roll the dice" << endl;
			cout << "Roll the dice? (y/n)" << endl;
				cin >> go;
			if(go=='y'){
       			srand(time(0));
       			num = rand() % 6 + 1;
       		p[i]=p[i]+num;
       		temp[i]=p[i];
       		if(p[i]>100){
       			p[i]=200-p[i];
       		}
       		if(p[i]==3){
       			p[i]=6;
       			t=true;
       		}
       		if(p[i]==26){
       			p[i]=41;
       			t=true;
       		}
       		if(p[i]==33){
       			p[i]=35;
       			t=true;
       		}
       		if(p[i]==66){
       			p[i]=76;
       			t=true;
       		}
       		if(p[i]==88){
       			p[i]=94;
       			t=true;
       		}
       		if(p[i]==42){
       			p[i]=20;
       			u=true;
       		}
       		if(p[i]==54){
       			p[i]=44;
       			u=true;
       		}
       		if(p[i]==68){
       			p[i]=69;
       			u=true;
       		}
       		if(p[i]==78){
       			p[i]=20;
       			u=true;
       		}
       		if(p[i]==98){
       			p[i]=84;
       			u=true;
       		}			   			   			   			   			   			   			   			          		
			cout << endl;
			createboard();
			cout << "Roll result: " << num << endl;
			cout << n[i] << " moved from " << temp[i]-num << " to " << p[i] << endl;
			if(t){
				cout << "Congrats! You moved up the ladder to success!" << endl;
			}	
			if(u){
				cout << "You got bit by a snake... Keep going, don't give up!" << endl;
				}
			if(p[i]==100){
				cout << "P "; colorize(4); cout << "R "; colorize(5); cout << "O "; colorize(14); cout << "F "; colorize(2); cout << "I "; colorize(9); cout << "C "; colorize(13); cout << "I "; colorize(5); cout << "A "; colorize(15); cout << "T "; colorize(9); cout << "! We are proud of you, " << n[i];
				f=true;
				}
			}	
       		if(go=='n'){
       			createboard();
       			cout << "Very well. We skip over to your opponent." << endl;
       		}
       		cout << endl;
       		u=false; t=false;
			i++;
		}
	}
}

int main()
{
	int i,j;
	int temp[2];
	int input,players;
	p[0]=1; p[1]=1;
	char q;
	colorize(9);
    cout << "--==WELCOME TO GATOTKACA==--" << endl;
    cout << "PLAY TOGETHER WITH "; colorize(2); cout << "(JUST ONE OF) "; colorize(9); cout << "YOUR BEST FRIENDS" << endl;

start:
    menu(&input);
        colorize(15);
    if(input==1){	//Game initialization
    	cout << "Input player name 1: ";
    		cin >> n[0];
    	cout << "Input one letter as pawn for Player 1: ";
    		colorize(11);
			cin >> b[0]; 
			colorize(15);  		
    	cout << "Input player name 2: ";
    		cin >> n[1];
    	cout << "Input one letter as pawn for Player 2: ";
    		colorize(14);
    		cin >> b[1]; 
			colorize(15);   		
		cout << "Game start!!" << endl;
		cout << endl;
		cout << endl;
		
		createboard();
		movement();
		
		cout << endl;

    }
    else{	//Exiting the game
    	cout << "Are you sure you want to quit? (y/n) : ";
    		cin >> q;
    	if(q=='y') {
			return 0;
		}
    	else {
    		goto start;
    	}
    }
    
    cout << "THANK YOU FOR PLAYING GATOTKACA" << endl;
    cout << "--==HOPE YOU HAD A GOOD TIME==--" << endl;
    

}

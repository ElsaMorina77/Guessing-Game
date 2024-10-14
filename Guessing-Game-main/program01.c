#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

//declare functions here 
int fnRandom(int nMin, int nMax); //for the random the computer will be assigned to 
int fnCallUser(int nMin, int nMax); //to scan user input 
int fnLevel1(int nGuesses); 
int fnLevel2(int nGuesses1);
int fnLevel3(int nGuesses2);

int main(){
int nGuesses=3; //declare the guess number here 
int nGuesses1=0, nGuesses2=0,nGuesses3=0; //declare the variables that will save the returns of the functions 
int nLevel;
srand(time(0)); //randomization function so that the nums arent the same 



	//information for the user 
	printf("WELCOME TO THE GUESSING GAME!\n");
		nGuesses1 = fnLevel1(nGuesses); //variable to save the return of the guesses in level 1
		//printf("%d guesses\n",nGuesses1 ); //for me to see if the guesses match up, didnt want to delete them 
	if (nGuesses1>0){ // if the guesses in level 1 are greater than 0, we proceed to the next level 
		nGuesses2 = fnLevel2(nGuesses1); //save return of the level two, plus the execution of the level 2 fuction happens here 
		//printf("nGuesses2 is %d\n",nGuesses2 ); //for me to see if the guesses match up, didnt want to delete them 
		
	}
	if (nGuesses2>0) //if the guesses are greater than 0 then we proceed with level 3
	{
		nGuesses3 = fnLevel3(nGuesses2); //call the function for level 3 to save up the number of guesses in the 
		//printf("nGuesses3 is %d \n",nGuesses3 ); //for me to see if the guesses match up, didnt want to delete them 
	}
	//we can do the same for the other levels, just reuse the code change up a few things and re-add another if as the one above for level 3




}



int fnRandom(int nMin, int nMax){

    int nRand=rand()%(nMax -nMin+1)+nMin; //setting bounds for the rand 

     return nRand;

}

int fnCallUser(int nMin, int nMax){
	int nUser; //declare variable to return later 
	printf("Please enter your guess for the computer's secret number: \n");
	scanf("%d", &nUser);

	//checking if the number the user has inputed is within range else it will ask for another input 
	if(nUser<nMin || nUser>nMax){
		printf("The number you have entered is not within range please re-enter it: \n");
		scanf("%d", &nUser);

	}
	return nUser; 
	
}

int fnLevel1(int nGuesses){
	printf("This game is divided in 3 levels.\nYou are now in level one. Choose a number between 1 and 10. You have 3 guesses. Choose your guesses carefully, or you lose.\n");
	int nMax=10;
	int nMin=1;
	int nRandNumber=fnRandom(nMin, nMax); //get a random for the computer number  
	int nUser1= fnCallUser(nMin,nMax); //get the number from the user 
	while(nUser1!=nRandNumber){  //if the number of the user is not equal to the one of the computer enter the while loop 
		if(nGuesses==0){ //if the guesses are 0 then end the game, print the message 
				printf("You LOSE!!\n");
				break;
			}
		printf("Trying for %d \n",nUser1 ); //print message to the user 
		
		if(nUser1>nRandNumber){ //if the number the use has inputted is greater than the computers number then print message and check if the guesses are not 0, if not zero print the guesses to the user 
			printf("Your guess is greater than the computers guess. Try again!\n");
			nGuesses--; //decrease the guess number 
			if(nGuesses != 0){
				printf("You have %d guesses remaining!!! \n", nGuesses);
				nUser1=fnCallUser(nMin,nMax); // take another number from user 
			}
			

	}

		 

		else if(nUser1 < nRandNumber){ //else if the user number is smaller than the computers number 
			printf("Your guess is smaller than the computers guess. Try again!\n");
			nGuesses--; //decrease the guesses 
			if(nGuesses != 0){ // if the guesses are not 0 enter the if 
			printf("You have %d guesses remaining!!! \n", nGuesses); //print this 
			nUser1=fnCallUser(nMin,nMax); //call function, save to nUser1 
		}//end if 

			}//end else if 

		if (nUser1==nRandNumber){ //if nr from user is equal to the computers 
			printf("Great Job! The number is %d\n",nUser1 ); //print this 
			
			break;


	}// end if 

	}

		if(nGuesses==0){ //if the guesses are 0, they have lost the game, message is printed  
		printf("You Lost the Game :( \n");
	}
		else{ //else proceed to the next level 
		printf("You will proceed to the next Level.\n");
	}

		//printf("Computer's Number is:  %d\n",nRandNumber ); //for me to see and compare while writing the code 
		return nGuesses;
}

int fnLevel2(int nGuesses1){
	printf("You are now in LEVEL 2.\n");
	nGuesses1 = nGuesses1+5; //add the guesses as required 
	printf("You have %d lives for this level.\nChoose a number between 1 and 100.\n", nGuesses1);
	int nMax=100;
	int nMin=1;
	int nRandNumber=fnRandom(nMin, nMax); //call function for  nr of computer 
	int nUser1= fnCallUser(nMin,nMax); // call func for nr of user 
	while(nUser1!=nRandNumber){ //if the numbers are not same enter loop print message 

		if(nGuesses1==0){ //when the guesses are 0 break of of the while print message 
				printf("You LOSE!!\n");
				break;
			}
		printf("Trying for %d \n",nUser1 );
		
		if(nUser1>nRandNumber){ //if user nr is greater than the computer nr enter 
			printf("Your guess is greater than the computers guess. Try again!\n"); //print this 
			nGuesses1--; //decrement since wrong answer 
			if(nGuesses1 != 0){ //if the guesses arent 0 we print message and tell user to enter another nr. 
			printf("You have %d guesses remaining!!! \n", nGuesses1);
			nUser1=fnCallUser(nMin,nMax);
			}//end if 

	}//end if 

		else if(nUser1 < nRandNumber){ //same logic as above but for lower than
			printf("Your guess is smaller than the computers guess. Try again!\n");
			nGuesses1--;
			if(nGuesses1 != 0){
			printf("You have %d guesses remaining!!! \n", nGuesses1);
			nUser1=fnCallUser(nMin,nMax);
			}// end if 
		}//end else if 

		if(nUser1==nRandNumber){
			printf("Great Job! The number is %d\n",nUser1 );
			break;

		}//end if 

		
	}//end while 

		if(nGuesses1==0){ //if guesses 0, you lose the game 
			printf("You Lost the Game :( \n");
	}
		else{
			printf("You will proceed to the next Level.\n");
		}
			//printf("Computer's Number is:  %d\n",nRandNumber ); //for me to compare 

		return nGuesses1;
}


//same logic as the above functions 
int fnLevel3(int nGuesses2){
	printf("You are now in LEVEL 3.\n");
	nGuesses2 = nGuesses2+10;
	printf("You have %d lives for this level.\nChoose a number between 1 and 1000.\n", nGuesses2);
	int nMax=1000;
	int nMin=1;
	int nRandNumber=fnRandom(nMin, nMax);
	int nUser1= fnCallUser(nMin,nMax);
	while(nUser1!=nRandNumber){
		if(nGuesses2==0){
				printf("You LOSE!!\n");
				break;
			}//endif
		printf("Trying for %d \n",nUser1 );
		
		if(nUser1>nRandNumber){
			printf("Your guess is greater than the computers guess. Try again!\n");
			nGuesses2--;
		if (nGuesses2 != 0){
			printf("You have %d guesses remaining!!! \n", nGuesses2);
			nUser1=fnCallUser(nMin,nMax);
			
				}//endif2
	}//endif1
			

		else if(nUser1< nRandNumber){
			printf("Your guess is smaller than the computers guess. Try again!\n");
			nGuesses2--;
			if (nGuesses2 != 0){
			printf("You have %d guesses remaining!!! \n", nGuesses2);
			nUser1=fnCallUser(nMin,nMax);
		}


		}//endelse

		if (nUser1==nRandNumber){

			printf("Great Job! The number is %d\n",nUser1 );
			printf("CONGRATS! YOU HAVE WON THE GAME!!!!!\n");
	}//endif

	}//endwhile
		if(nGuesses2==0){
		printf("You Lost the Game :( \n");
	}//endif
		//printf("Computer's Number is:  %d\n",nRandNumber );//for me to compare while writing this 
		return nGuesses2;
}//endfunction














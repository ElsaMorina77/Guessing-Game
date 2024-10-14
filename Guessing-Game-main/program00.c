#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
//declare functions 
int fnRandom(int nMin, int nMax);
int fnCallSecret(int nMin, int nMax);
int fnCompareComp(int nMin, int nMax);
int fnCompareUser(int nMin, int nMax);

//MAIN
int main(){
int nMin, nMax;
srand(time(0)); //for the randomization 
printf("Please enter the range you want your number to be in:\n");
scanf("%d%d", &nMin, &nMax);
if(nMin>nMax){
	printf("Please enter the lower bound first then the upper bound!\n");
	scanf("%d%d", &nMin, &nMax);

}
	
	printf("WELCOME TO THE GUESSING GAME!\n");
	printf("COMPUTER VS USER\n");
	int nCompScore = fnCompareComp(nMin,nMax); //in order to get the scores 
	printf("USER VS COMPUTER TURN\n");
	int nUserScore= fnCompareUser(nMin,nMax); //in order to get the scores 
	//winner determiner 
	printf("The scores are: \nComputer Score: %d\nUser Score: %d ", nCompScore,nUserScore);
	if (nCompScore<nUserScore)
	{
		printf("\nTHE COMPUTER HAS WON THE GAME!!!\n");
	}
	else if (nUserScore<nCompScore)
	{
		printf("\nTHE USER HAS WON THE GAME!!!\n");
	}
	else{
		printf("\nGOOD GAME. SAME SCORES!!!\n");
	}

	

 return 0;   
}

//define functions here 

int fnRandom(int nMin, int nMax){

    int nRand=rand()%(nMax -nMin+1)+nMin;  

     return nRand;

}

int fnCallSecret(int nMin, int nMax){ //to get the secret number from the user 
	int nSecret;
	printf("Please enter your secret number\n");
	scanf("%d", &nSecret);

	if(nSecret<nMin || nSecret>nMax){ //to check if it is within range 
		printf("The Secret number you have entered is not within range please re-enter it: \n");
		scanf("%d", &nSecret);

	}
	return nSecret; 
			   
}

int fnCallUser(int nMin, int nMax){ //created function in order to get numbers from the user so that i dont have to rewrite everything all over 
	int nUser;
	printf("Please enter your guess for the computer's secret number: \n");
	scanf("%d", &nUser);


	if(nUser<nMin || nUser>nMax){ //to check if within range 
		printf("The number you have entered is not within range please re-enter it: \n");
		scanf("%d", &nUser);

	}
	return nUser;
	
}

int fnCompareComp(int nMin, int nMax){
	int nSecret1=fnCallSecret(nMin,nMax); //call number here, store it in variable to be used in function 
	int nRand1=fnRandom(nMin, nMax); //call rand here, store in var to be used in the function 
	int nGuesses=1;

	while (nRand1!=nSecret1){  //if the random number and secret number anre not the same we enter the while loop 
	printf("Trying for the number %d...\n", nRand1);
	
	if(nRand1<nSecret1){ //if rand is less than the secret number, we have to increase the lower bound 
		printf("The Secret number is greater than the Computers Guess! \n");
		nMin=nRand1++; //increasing the lower bound in order to get to the number 
		nGuesses++;
	}
	else{
		printf("The Secret number is smaller than the Computers Guess!\n");//if rand is more than the secret number, we have to decrease the upper bound 
	 	nMax=nRand1--; //decreasing the upper bound in order to get to the number
		nGuesses++;
	}
	

}
	//if the rand is equal to secret number, put in if loop 
	if(nRand1==nSecret1){
		printf("Congrats, the number is indeed %d \n",nRand1 );
	}
	 //nGuesses++; 
	 nRand1=fnRandom(nMin, nMax); //needed to reset the random number with the new lower and upper bounds 

	 return nGuesses;//needed to calculate the winner afterwards 
}





int fnCompareUser(int nMin, int nMax){
	int nComputerNum=fnRandom(nMin,nMax); //secret nr of computer 
	int nUserGuess=fnCallUser(nMin,nMax); //get nr from user 
	int nGuesses=1; //score 


	while(nUserGuess!=nComputerNum){
		printf("Trying for number %d... \n", nUserGuess);
		if(nUserGuess>nComputerNum){
			printf("Computer's number is smaller than the number you guessed. Try again! \n");
			nUserGuess=fnCallUser(nMin,nMax);//call to get number 
			nGuesses++;
			
		}
		else{
			printf("Computer's number is greater than the number you guessed. Try again! \n");
			nUserGuess=fnCallUser(nMin,nMax); //call to get number 
			nGuesses++;
		}
	}

	if(nUserGuess==nComputerNum){
		printf("Congrats, the number is indeed %d \n", nUserGuess);
	}

		//nGuesses++;
		return nGuesses;


}










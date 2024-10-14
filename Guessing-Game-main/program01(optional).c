#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
void startGame(int level, int totalPoints);
int getBetReturnRate(int rounds);
int compGuessGame(int secretNumber, int level, int totalPoints, int betPoints, int guessRounds);
int power(int a, int b);
int getBetReturnRate(int rounds);



int main() {
    srand(time(0));
    startGame(1, 100);
   
}
void startGame(int level, int totalPoints) {
    if(totalPoints <= 0) {
        printf("You have exhausted all of your points. Game Over! \n");
        return;
    }
    printf("=========== Starting level %d ===========\n", level);
    int secretNumber = (rand() % (power(10, level))) + 1;
    printf("Total points available: %d \n", totalPoints);
    printf("The secret number is a number between 1 and %d", power(10, level));
    printf("\n");
    printf("How many points do you want to bet this round? ");
    int betPoints;
    scanf("%d", &betPoints);
    while(!(betPoints >= 0 && betPoints <= totalPoints)) {
        printf("Invalid amount of points supplied, please provide again: ");
        scanf("%d", &betPoints);
    }
    printf("Within how many rounds do you think you can guess the number? ");
    int guessRounds;
    scanf("%d", &guessRounds);
    while(!(guessRounds >= 0 && guessRounds <= 10)) {
        printf("Please enter a positive integer smaller or equal to 10! ");
        scanf("%d", &guessRounds);
    }
    compGuessGame(secretNumber, level, totalPoints, betPoints, guessRounds);
}
//(rand() % (upper - lower + 1)) + lower
int compGuessGame(int secretNumber, int level, int totalPoints, int betPoints, int guessRounds) {
    int roundsRemaining = guessRounds;
    int userGuess;
    printf("Please enter your guess: ");
    scanf("%d", &userGuess);
    roundsRemaining--;
    while(userGuess!=secretNumber){
        if(roundsRemaining <= 0) {
            printf("The secret number was %d \n", secretNumber);
            printf("You have lost the round. \n");
            totalPoints -= betPoints;
            startGame(level, totalPoints);
         
        }
        if(userGuess>secretNumber){
            printf("The secret number is lower than the guess \n");
            printf("Please enter your guess: ");
            scanf("%d", &userGuess);
            roundsRemaining--;
        }
        else if(userGuess<secretNumber){
            printf("The secret number is higher than the guess \n");
            printf("Please enter your guess: ");
            scanf("%d", &userGuess);
            roundsRemaining--;
        }
    }
    printf("Congratulations! You won level %d \n", level);
    int roundWinnings = getBetReturnRate(guessRounds) * betPoints;
    totalPoints += roundWinnings;
    startGame(level + 1, totalPoints);
}
int power(int a, int b) {
    int result = a;
    while(b > 1) {
        result *= a;
        b--;
    }
    return result;
}
int getBetReturnRate(int rounds) {
    if(rounds >= 7 && rounds <= 10) {
        return 2;
    }else if(rounds >= 5 && rounds <= 6) {
        return 3;
    }else if(rounds == 4) {
        return 4;
    }else {
        return 5;
    }
}
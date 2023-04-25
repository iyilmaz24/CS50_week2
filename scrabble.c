#include <stdio.h>
#include <string.h>


// A simple program written in C that determines the winner of a short scrabble-like game. 
// Where two players each enter their word, and the higher scoring player wins.


// Points assigned to each letter of the alphabet, starting from "a" and going through to "z"
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char word[], int points[]);

int main(void)
{
    // where we will store the words we get from the players
    char word1[20], word2[20];

    // Get input words from both players
    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);

    // Score both words
    int score1 = compute_score(word1, POINTS);
    int score2 = compute_score(word2, POINTS);


    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }


}

// Computes and returns score for string
int compute_score(char word[], int points[])
{
    int score = 0; 

    for (int i = 1, word_length = strlen(word); i <= word_length; i++)
    {
        char letter = word[i - 1];

        // if the character is a "!" or a "?" we skip over it
        if (letter == 33 || letter == 63)
        {
            ;
        }
        // we add 32 to each character if it's ASCII value is less than 97 to convert it to it's lowercase equivalent
        else if (letter < 97)
        {
            letter += 32;

        }
        
        // we use this if statement to avoid calculating points for the "!" and "?" characters, and only calculate points for lowercase alphabet characters
        if (letter >= 97)
        {
            score += points[letter - 97];
        }

    }

    return score;

}




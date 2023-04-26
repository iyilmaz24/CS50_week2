#include <stdio.h>
#include <string.h>
#include <math.h>

// This program uses the Coleman-Liau index to rank text that it is given at a reading grade level. 

int main(void)
{

    // this array with the formatting in the scanf line below allows us to store multiple sentences in the same user_text array
    char user_text[500];
    printf("Insert line of text: ");
    scanf("%[^\n]%*c", user_text);

    // these are the variables we will use to store the calculations we make in the next for loop
    float letter_count = 0, word_count = 1, sentence_count = 0;

    // this for loop iterates through every position in the array and counts up sentences, words, and letters
    for (int i = 1, text_length = strlen(user_text); i <= text_length; i++)
    {

        if (user_text[i] == ' ')
        {
            word_count += 1;
        }
        else if (user_text[i] == '.' || user_text[i] == '?' || user_text[i] == '!')
        {
            sentence_count += 1;
        }
        else if (user_text[i] != '\0' || user_text[i] != ' ')
        {
            letter_count += 1;
        }

    }


    // the creatiion of this variable serves to store the result of the Coleman-Liau index when we plug in our calculated words, sentences, and letters into it
    int index = floor(((0.0588 * ((letter_count / word_count) * 100)) - (0.296 * ((sentence_count / word_count) * 100))) - 15.8);


    // here we will output the result of our calculated Coleman-Liau index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

}



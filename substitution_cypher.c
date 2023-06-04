#include <stdio.h>
#include <string.h>
#include <ctype.h>

// test input: abcdefghijklmnopqrstuvwxyz
// test input 2: zyxwvutsrqponmlkjihgfedcba

int main(int argc, char* argv[])
{
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("PLEASE ONLY PROVIDE A 26 CHAR LONG ENCRYPTION KEY AS THE INPUT\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (argv[1][i] < 65 || argv[1][i] > 90 & argv[1][i] < 97 || argv[1][i] > 122)
        {
            printf("PLEASE ONLY PROVIDE ALPHABETIC CHARACTERS USED ONLY ONCE EACH IN THE 26 CHAR LONG ENCRYPTION KEY\n");
            return 1;
        }
        int counter = 0;
        for (int  j = 0; j < 26; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                counter += 1;
            }
            if (counter > 1)
            {
                printf("PLEASE ONLY PROVIDE ALPHABETIC CHARACTERS USED ONLY ONCE EACH IN THE 26 CHAR LONG ENCRYPTION KEY\n");
                return 1;
            }
        }
    }

    // accept the input
    char input[0];
    printf("plaintext: ");
    scanf("%[^\n]s", input);


    // find length of the input
    int length = 0;
    while (input[length] != '\0')
    {
        length++;
    }


    // encrypt the input using the cypher key and store in output
    char output[10];
    for (int i = 0; i < length; i++)
    {
        if (input[i] >= 97 & input[i] <= 122)
        {
            // minus 97 if lower to  match encryption key
            char character;
            character = argv[1][(input[i] - 97)];

            if (character < 97)
            {
                character += 32;
                output[i] = character;
            }
            else
            {
                output[i] = character;
            }
        }

        else if (input[i] >= 65 & input[i] <= 90)
        {
            // minus 65 if upper to match encryption key
            char character;
            character = argv[1][(input[i] - 65)];

            if (character < 97)
            {
                output[i] = character;
            }
            else
            {
                character -= 32;
                output[i] = character;
            }

        }
        else
        {
            output[i] = input[i];
        }
    }


    // output the results
    printf("ciphertext: %s\n", output);

    return 0;
}




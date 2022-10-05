#include "headerA3.h"

int main()
{

    tweet* ourTweetList = NULL;


    while(1){
        printMenu();
        int optionSelected;
        printf("Choose a menu option: ");
        scanf("%d", &optionSelected);
        getc(stdin);

        switch(optionSelected){
        case 1:
            ourTweetList = createTweet(ourTweetList);
            break;
        case 2:
            displayTweets(ourTweetList);
            break;
        case 3:
            searchTweetsByKeyword(ourTweetList);
            break;
        case 4:
            countStopWords(ourTweetList);
            break;
        case 5:

            deleteTweet(&ourTweetList);
            break;
        case 6:
            saveTweetsToFile(ourTweetList);
            break;
        case 7:
            loadTweetsFromFile(&ourTweetList);
            break;

        case 8:
            exit(0);
        default:
            printf("Invalid Entry!\n");
        }


    }
    return 0;
}



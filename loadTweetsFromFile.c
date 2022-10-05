#include "headerA3.h"

void loadTweetsFromFile(tweet** tweetList){                     //loading tweets from file
    char fileName[50];
    printf("Enter a filename to load from: ");
    scanf("%s", fileName);                                             // asking the user for file name


    FILE* ourFile = fopen(fileName, "r");

    if(ourFile == NULL){                                              // if any error occurs
        printf("Couldn't open the requested file.\n");
        return;
    }

    int id;
    char idInString[51];
    char userName[51];
    char tweet[141];

    char* inputDestination = idInString;
    int inputIndex = 0;
    int commaCount = 0;

    char readingCharacter;
    while((readingCharacter = fgetc(ourFile))){                              //reading the file one character at a time
        
        if(readingCharacter == ',' && commaCount == 0){                      //if we encounter a comma, we update the destination from tweetId to username
            commaCount = 1;
            inputDestination[inputIndex] = '\0';

            id = atoi(idInString);
            inputDestination = userName;
            inputIndex = 0;
        }else if(readingCharacter == ',' && commaCount == 1){                //if we encounter the second comma, we update the destination from username to tweet.
            inputDestination[inputIndex] = '\0';
            commaCount = 2;
            inputDestination = tweet;
            inputIndex = 0;
        }else if(readingCharacter == '\n' || readingCharacter == EOF){            //if we encounter the newline or eof file, we create the tweet object, assign all the data we read above and add it to the tweetList.
            commaCount = 0;
            inputDestination[inputIndex] = '\0';
            inputDestination = idInString;
            inputIndex = 0;
            struct tweet* ourNewTweet = (struct tweet*)malloc(sizeof(struct tweet));

            ourNewTweet->id = id;
            strcpy(ourNewTweet->user, userName);
            strcpy(ourNewTweet->text, tweet);
            addNodeToList(tweetList, ourNewTweet);
            if(readingCharacter == EOF){
                break;
            }
        }
        else{                                                         //if we encounter any other character, we just add it to the destination
            inputDestination[inputIndex] = readingCharacter;
            inputIndex += 1;
        }
    }

    fclose(ourFile);
    printf("Tweets imported!\n");
}

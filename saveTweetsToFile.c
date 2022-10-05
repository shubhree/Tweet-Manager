#include "headerA3.h"


void saveTweetsToFile(tweet* tweetList){
    char fileName[50];
    printf("Enter the filename where you would like to store your tweets: ");
    scanf("%s", fileName);

    FILE* ourFile = fopen(fileName, "w");
    if(ourFile == NULL){
        printf("ERROR: Couldn't open file\n");
        return;
    }

    int first = 1;

    while(tweetList != NULL){
        if(first==0){
            fprintf(ourFile, "\n");
        }
        if(first == 1){
            first = 0;
        }
        fprintf(ourFile, "%d,%s,%s", tweetList->id, tweetList->user, tweetList->text);
        tweetList = tweetList->next;
    }
    printf("Output successful!\n");

    fclose(ourFile);
}

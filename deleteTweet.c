#include "headerA3.h"


void deleteTweet(tweet** tweetList){                         //deleting a tweet


    tweet* currentHead = *tweetList;
    int count = 0;


    while(currentHead != NULL){
        count += 1;
        currentHead = currentHead->next;
    }

    currentHead = *tweetList;

    printf("Currently there are %d tweets.\n", count);            //first printing the total number of tweets

    printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", count);        //asking user to delete which tweet
    int tweetToDelete;
    scanf("%d", &tweetToDelete);

    int traverseCount = 0;
    int deletedId = 0;

    if(tweetToDelete == 1){                                       //for removing the first tweet
        deletedId = currentHead->id;
        currentHead = currentHead->next;
        *tweetList = currentHead;
    }else{                                                        //for removing any other
        while(currentHead != NULL){
        traverseCount += 1;
            if(traverseCount + 1 == tweetToDelete){
                deletedId = currentHead->next->id;
                currentHead->next = currentHead->next->next;
                break;
            }
            currentHead = currentHead->next;
        }
    }

    printf("Tweet %d deleted. There are now %d tweets left.\n", deletedId, count-1);  //printing the nth tweet deleted and total tweets left
}


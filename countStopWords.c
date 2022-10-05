#include "headerA3.h"


void countStopWords(tweet* tweetList){               // to count the stop words 

    int totalStopWords = 0;
    int totalTweets = 0;


    while(tweetList != NULL){                        // while loop for traversing the list
        totalTweets += 1;
        char* tweet = tweetList->text;
        int tweetLength = strlen(tweet);

        int startOfWord = 0;
        int endOfWord = 0;
        int index = 0;

        while(index < tweetLength){
            if(!(tweet[index]>='a' && tweet[index]<='z') && !(tweet[index]>='A' && tweet[index]<='Z')){
                if((tweet[index-1]>='a' && tweet[index-1]<='z') || (tweet[index-1]>='A' && tweet[index-1]<='Z')){
                    endOfWord = index - 1;
                    if(isAStopWord(tweet, startOfWord, endOfWord)){         //passing to another function to call stop words
                        totalStopWords += 1;
                    }
                    startOfWord = endOfWord + 1;


                }
            }
            index += 1;
        }

        tweetList = tweetList->next;


    }
    printf("Across %d tweets, %d stop words were found\n", totalTweets, totalStopWords);          //printing the stop words
}




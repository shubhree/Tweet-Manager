#include "headerA3.h"


void displayTweets(tweet* tweetList){                           //for displaying the tweet
    while(tweetList != NULL){                                    
        printf("%d: Created by %s: %s\n", tweetList->id, tweetList->user, tweetList->text);
        tweetList = tweetList->next;
    }
}

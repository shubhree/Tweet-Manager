#include "headerA3.h"


tweet* createTweet(tweet* tweetList){                            //creating a new tweet
    tweet* ourNewTweet = (tweet*)malloc(sizeof(tweet));           // dynamically allocating the memory block for tweet
    printf("Enter a username: ");
    scanf("%s", ourNewTweet->user);
    getc(stdin);
    int userNameLength = strlen(ourNewTweet->user);
    if(userNameLength > 50){
        printf("Error: Entered username is too long.\n");              //checking the length of username
        return NULL;
    }


    printf("Enter the user\'s tweet: ");                              
    
	fgets(keyword, 200, stdin);


    int tweetLength = strlen(ourNewTweet->text) - 1;
    if(tweetLength > 140){                                          ////checking the length of tweet
        printf("Error: Entered Tweet is too long.\n");
        return NULL;
    }

	ourNewTweet->text[tweetLength] = '\0';

    int userId = tweetLength;

    int i;

    for(i = 0; i < userNameLength; i ++){                     //traversing the username character by character to calculate userid

        userId += ourNewTweet->user[i];
    }

    ourNewTweet->id = userId;

    printf("Your computer-generated userid is %d.\n", userId);        //printing the calculated userid

    addNodeToList(&tweetList, ourNewTweet);

    return tweetList;

};



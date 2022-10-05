#include "headerA3.h"
#include<string.h>


void searchTweetsByKeyword(tweet* tweetList){
    char keyword[151];
    printf("Enter a keyword to search: ");
   // getline(keyword);
   // fgets(keyword, stdin);
   //fgets(keyword, 200, stdin);
   scanf("%s",keyword);
    strlwr(keyword);
//    while(head != NULL){
//        if(strstr(head->text, keyword) != NULL){
//            printf("%s", strstr(head->text, keyword));
//            printf("Match found for \'%s\': %s wrote: \"%s\"\n", keyword, head->user, head->text);
//        }
//        head = head->next;
//    }

    while(tweetList != NULL){

        char* tweet = tweetList->text;
        int tweetLength = strlen(tweet);

        int startOfWord = 0;
        int endOfWord = 0;
        int index = 0;

        while(index < tweetLength){
            if(!(tweet[index]>='a' && tweet[index]<='z') && !(tweet[index]>='A' && tweet[index]<='Z')){
                if((tweet[index-1]>='a' && tweet[index-1]<='z') || (tweet[index-1]>='A' && tweet[index-1]<='Z')){
                    endOfWord = index - 1;
                    if(matchingTheWord(tweet, startOfWord, endOfWord, keyword) == 1){
                        printf("Match found for \'%s\': %s wrote: \"%s\"\n", keyword, tweetList->user, tweetList->text);
                        break;
                    }
                    startOfWord = endOfWord + 1;


                }
            }
            index += 1;
        }

        tweetList = tweetList->next;


    }
}

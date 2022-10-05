#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tweet {
 int id;
 char user [51];
 char text [141];
 struct tweet *next;
}tweet;

// menu functions

void displayTweets( tweet* head);
tweet* createTweet(tweet* head);
void searchTweetsByKeyword(tweet* head);
void countStopWords(tweet* head);
void deleteTweet( tweet** head);
void saveTweetsToFile( tweet* head);
void loadTweetsFromFile(tweet** head);

// Helper functions
void printMenu();
int isAStopWord(char* tweet, int startOfWord, int endOfWord);
void addNodeToList(tweet**tweetList, tweet * node);
int matchingTheWord(char* tweet, int startOfWord, int endOfWord, char keyword[]);


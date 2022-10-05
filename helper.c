#include "headerA3.h"
#include<string.h>
#include<ctype.h>

void printMenu(){                                //printing the menu
    printf("1. Create a new tweet\n");
    printf("2. Display tweets\n");
    printf("3. Search a tweet (by keyword)\n");
    printf("4. Find how many words are \"stop words\"\n");
    printf("5. Delete the nth tweet\n");
    printf("6. Save tweets to a file\n");
    printf("7. Load tweets from a file\n");
    printf("8. Exit\n");
}

char *strlwr(char *str)                                    //converts a string into a lowercase string
{
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return str;
}

void addNodeToList(tweet**tweetList,tweet * node){            //it adds a new node into the tweetlist

    tweet* head = *tweetList;
    node->next = NULL;
    if(head == NULL){
        *tweetList = node;
    }else{
        while(head->next != NULL){
            head = head->next;
        }
        head->next = node;
    }
}

int isAStopWord(char* tweet, int startOfWord, int endOfWord){               //checks if the passed word is a stop word or not
    char stopWords[25][10] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its",
    "of","on","that","the","to","was","were","will","with"};
    int lengthOfWord = (endOfWord - startOfWord) + 1;
    char currentWord[lengthOfWord + 1];
    int i = 0;
    int currentWordIndex = 0;
    for(i = 0; i < lengthOfWord; i ++){
        char currentChar = tweet[startOfWord + i];
        if((currentChar>='a' && currentChar<='z') || (currentChar>='A' && currentChar<='Z')){
            currentWord[currentWordIndex] = currentChar;
            currentWordIndex += 1;
        }
    }
    currentWord[currentWordIndex] = '\0';

    strlwr(currentWord);

    for(i = 0; i < 25; i ++){
        if(strcmp(currentWord, stopWords[i]) == 0){
            return 1;
        }
    }
    return 0;
}

int matchingTheWord(char* tweet, int startOfWord, int endOfWord, char keyword[]){            //it is responsible for checking if two words are same(case-insensitive).
    int lengthOfWord = (endOfWord - startOfWord) + 1;
    char currentWord[lengthOfWord + 1];
    int i = 0;
    int currentWordIndex = 0;
    for(i = 0; i < lengthOfWord; i ++){
        char currentChar = tweet[startOfWord + i];
        if((currentChar>='a' && currentChar<='z') || (currentChar>='A' && currentChar<='Z')){
            currentWord[currentWordIndex] = currentChar;
            currentWordIndex += 1;
        }
    }
    currentWord[currentWordIndex] = '\0';
    
    strlwr(currentWord);

    if(strcmp(currentWord, keyword) == 0){
        return 1;
    }
    return 0;
}

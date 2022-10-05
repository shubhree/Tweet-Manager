CC=gcc
CFLAGS=-Wall -std=c99

a3 : main.o createTweet.o helper.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o
	$(CC) main.o createTweet.o helper.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o -o a3
main.o : main.c
	$(CC) $(CFLAGS) -c main.c
createTweet.o : createTweet.c
	$(CC) $(CFLAGS) -c createTweet.c
displayTweets.o : displayTweets.c
	$(CC) $(CFLAGS) -c displayTweets.c
searchTweetsByKeyword.o : searchTweetsByKeyword.c
	$(CC) $(CFLAGS) -c searchTweetsByKeyword.c
countStopWords.o : countStopWords.c
	$(CC) $(CFLAGS) -c countStopWords.c
deleteTweet.o : deleteTweet.c
	$(CC) $(CFLAGS) -c deleteTweet.c
saveTweetsToFile.o : saveTweetsToFile.c
	$(CC) $(CFLAGS) -c saveTweetsToFile.c
loadTweetsFromFile.o : loadTweetsFromFile.c
	$(CC) $(CFLAGS) -c loadTweetsFromFile.c
helper.o : helper.c
	$(CC) $(CFLAGS) -c helper.c
clean :
	rm *.o a3
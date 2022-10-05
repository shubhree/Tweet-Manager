Name : Shubhreet Singh Dang
Username : shubhree 

Assignment :
Assignment #3: Dynamic Data structures (linked lists) - Tweet Manager

Course: CIS *2500

Date of last revision: 21st March, 2021

In order to compile and run,  makefile is used.
Compile : make
Run : ./a3

Completed Components:
1. Create a new tweet : Asks the user to enter his usename and tweet. And then it appends the tweet to the tweetlist. 
    It also does some error checking regarding the lengths of the inputs.
2. Display tweets :  Iterates over the currently saved tweets and prints them onto the console.
3. Search a tweet (by keyword) : It searches for a particular given word in each tweet and then displays the tweet.
4. Find how many words are “stop words” : It counts total number of stop words across all the tweets.
5. Delete the nth tweet : Iterates over the list and deletes the nth tweet. I also updates the list head if first node is deleted.
6. Save tweets to a file : Iterates over the tweetList and saves all the tweetids, usernames and 
    tweets to a csv(comma separated file) onto the secondary storage device.
7. Load tweets from a file :  Asks user for a file name and then loads all the tweet data from that file. 
    It throws an error if the file couldn't be opened.

Limitation : 
Time complexity of searching and counting stop words is high. It can take a while if we have a huge amount of data.

Improvements : 
Instead of using a csv file, in future we can use a database to store the data in an organized way. 
Also, we can build up a user authentication system to take it to next level.





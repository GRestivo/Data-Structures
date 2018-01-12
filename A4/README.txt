Author: Gordon Restivo
Student #: 0971067
Last date modified: 11/14/2017

PLEASE NOTE: The remove rule function/command does not work, however it can still check to see if the rule to delete
			 does not exist and print an error message accordingly


Discription of program:

This program reads in a file from the command line, a file that holds a rules. The rules are added into a Binary Search
Tree .A line in the file contains a key word followed by a response on the next line. A rule is composed of a keyword 
and a reponse plus several ratings on the importantce of the rule.
After every rule from the file has been read in the user will be given a command list containing
6 options. Those options are:

1) Allows the user to add a new rule, only if it does not already exist 
2) Allows the user to delete a rule, only if it exists
3) Allows the user to print all rules to the screen
4) Allows the user to modify the ratings of an existing rule
5) Allows the user to have a conversation with an AI bot. The bots reponds to user questions by using the responses in
   the Binary search tree.
6) Quits the program



Assumptions:
1. AI responses dont need to be coherent
2. Algorithm for importance is sufficient


To run main:
1. Type in make
2. type "./bin/runMe 'filename.txt'" (without a valid file the program will be terminated)

To run testMain:
1.Type in make
2.type "./bin/runTests"

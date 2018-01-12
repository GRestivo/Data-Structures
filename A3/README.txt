Author: Gordon Restivo
Student #: 0971067
Last date modified: 11/14/2017

PLEASE NOTE: For function 4 the output is in the form 'key:word' because in my program the key and row index are the same,
so to reduce output redundency the index column has been removed


Discription of program:

This program reads in a file from the command line, a file that holds a list of words, 1 per line, and inserts each word
into a hash table based up a key returned from a hashing function. The key is givin based of the first letter of the 
current word being read in. After every word from the file has been read in the user is should a command list containing
5 options. Those options are:

1) Allows the user to add a new word to the dictionary. If the word does not already exist in the hash table it will
   be inserted into the proper position based on the key returned from running the word through the hash function
2) Allows the user to delete an existing word from the dictionary. If the word exists in the hash table it will be
   removed
3) Allows the to input a file name containing more words, 1 word per line. If the file name given does not exist in the
   directory they are given a warning message and must continue to enter file names until they produce one that exists
   The words are then compared to the hash table dictionary. If the new word is not in the dicionary it is printed to 
   the screen. The number of incorrect and correctly spelt words are also displayed.
4) Prints all current words in the hash table to the screen in the form 'key/index:word'
5) Quits the program


Collision resolution used: 
	
	The collision used for this hash table is the seperate chaining technique. Every row in the hash table array holds a
	pointer to a linked list that is created and allocated upon creating the hash table. The linked list uses the linked
	list API from assignments 1 and 2 to function. The decision making process behind this was not a long one, it only
	seemed logical to use a seperate chaining collision function because I already had a complete Linked List API, thus 
	reducing the total code needed for the hash table API as most functions could be turned into wrapper functions, with
	only a few API functions needing additional code.


Assumptions:
1. Original words read into the hash table are real words and are spelt correctly
2. Files given are in the correct format
3. User inputted words are real and spelt correctly
4. Words are spelt incorrectly solely because they were not found in the dictionary


To run main:
1. Type in make
2. type "./bin/runMe 'filename.txt'" (without a valid file the program will be terminated)

To run testMain:
1.Type in make
2.type "./bin/runTests"

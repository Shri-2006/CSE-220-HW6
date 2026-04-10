## Shriyans Singh 114807762
# HW6


Each edge case that I handled was regarding the arguments given

First check MISSING_ARGUMENT where there was not enough arguments in the command (7)
Second was checking for DUPLICATE_ARGUMENT, where there was more than one flag of the same type
Third and Fourth were checking the files to ensure the input could be opened and the output could be written, else INPUT_FILE_MISSING or OUTPUT_FILE_UNWRITEABLE would occur.
Fifth and sixth were checking for specific argument missing, s,r (S_ARGUMENT_MISSING or R_ARGUMENT_MISSING)
7th and eighth were checking for invalid L L_ARGUMENT_INVALID or invalid w WILDCARD_INVALID
9th was just checking a normal test case.

This program takes an input file, replace a specific match in the string searched with a replacement inside a certain range of lines and then puts the output in a output file.

s is search, r is replace , l start,end is start and end of lines, and w is wildcard mode which will match words that start or end with a speciifc pattern.
First checking for errors occurs in the order listed by the assignment that is still attached in the zip. The checks are done using getopt (taught mainly through geeksforgeeks for me). There is a regular search and replace (like google docs ctrl f actually) or wildcard which simply requires a pattern at the start or end to be the same. 

To run this you can run 
make
make test 
//(assuming that the program you want to run is in the tests folder).


Personal note: This took forever. I wrote it out so many times on the paper, then the linux environment kept having different answers than the codespace environment.... im very tired. 

Personal Note 2: instructions on readme that I missed out on first time:
https://piazza.com/class/mjipk4yk7d76zn/post/232

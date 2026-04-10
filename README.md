## Shriyans Singh 114807762



Each edge case that I handled was regarding the arguments given

First check MISSING_ARGUMENT where there was not enough arguments in the command (7)
Second was checking for DUPLICATE_ARGUMENT, where there was more than one flag of the same type
Third and Fourth were checking the files to ensure the input could be opened and the output could be written, else INPUT_FILE_MISSING or OUTPUT_FILE_UNWRITEABLE would occur.
Fifth and sixth were checking for specific argument missing, s,r (S_ARGUMENT_MISSING or R_ARGUMENT_MISSING)
7th and eighth were checking for invalid L L_ARGUMENT_INVALID or invalid w WILDCARD_INVALID
9th was just checking a normal test case.











Personal note: This took forever. I wrote it out so many times on the paper, then the linux environment kept having different answers than the codespace environment.... im very tired. 
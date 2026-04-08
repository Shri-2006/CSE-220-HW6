#include "hw6.h"
//Shriyans Singh 114807762

int main(int argc, char *argv[]) {
    //if not enough arguments provided return missing argument from header file
    if(argc<7){
        return MISSING_ARGUMENT;
    }
    //Using Max_search_len from header file to store the search string+1 because it also needs to include the null terminator
    char s_Search[MAX_SEARCH_LEN+1];
    char r_Replace[MAX_SEARCH_LEN+1];
    bool wildcard=false;
    //EOF = -1, which would be an extremely large number, and startIndex starts at 1 according to bullet 4 of overview
    int startIndex=1;
    int endIndex=9999;
    bool s_Exists=false;
    bool r_Exists=false;
    bool l_Exists=false;
    bool w_Exists=false;

    //Loops through arguments and checks if it should return DUPLICATED_ARGUMENTS
    





    return 0;
}

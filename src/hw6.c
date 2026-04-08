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

    //Loops through arguments and checks if it should return DUPLICATED_ARGUMENTS, based on the geeksforgeeks loop for guidance
    int opt;
    while((opt=getopt(argc,argv,"s:r:wl:"))!=-1){
        switch(opt){
    //if found now, but not found yet make it true and save what comes after the variable, otherwise if found more than once return DUPLICATED_ARGUMENTS

            case 's':
                if (s_Exists==true){
                    return DUPLICATED_ARGUMENTS;
                
                }
                else{
                    s_Exists=true;
                    strcpy(s_Search,optarg);
                    break;
                }
            case 'r':
                if(r_Exists==false){
                    r_Exists=true;
                    strcpy(r_Replace,optarg);

                    break;
                }
                else{
                    return DUPLICATED_ARGUMENTS;
                }
            case 'w':
                if(w_Exists==false){
                    w_Exists=true;
                    wildcard=true;
                    break;
                }
                else{
                    return DUPLICATED_ARGUMENTS;
                }
            case 'l':
                if(l_Exists==false){
                    l_Exists=true;
                    break;
                }
                else{
                    return DUPLICATED_ARGUMENTS;
                }

        }
    }





    return 0;
}

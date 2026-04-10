#include "hw6.h"
//Shriyans Singh 114807762
    //part 1 is error code check
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
    //to allow for proper order of error checks:
    bool L_Error=false;
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

                    char l_Copy[100];
                    strcpy(l_Copy,optarg);
                    char *first=strtok(l_Copy,",");
                    char *sec=strtok(NULL,",");
                    //strtol takes string, end char, and type of number (binary, octal, decimal, hexa)
                    if(first==NULL||strtol(first,NULL,10)==0){
                        L_Error=true;
                        break;
                    }
                    else if(sec==NULL ||strtol(sec,NULL,10)==0){
                        L_Error=true;
                        break;
                    }
                    
                    startIndex=strtol(first,NULL,10);
                    endIndex=strtol(sec,NULL,10);
                    if(startIndex>endIndex){
                        L_Error=true;
                        break;
                    }
                    break;                    
                }
                else{
                    return DUPLICATED_ARGUMENTS;
                }

        }
    }
    FILE *input=fopen(argv[argc-2],"r");
    if(input==NULL) {
        return INPUT_FILE_MISSING;
    }
    
    FILE *output=fopen(argv[argc-1],"w");
    if(output==NULL){
        return OUTPUT_FILE_UNWRITABLE;
    }
    
    //R error check
    if(s_Exists!=true){
        return S_ARGUMENT_MISSING;
    }
    else if(r_Exists!=true){
        return R_ARGUMENT_MISSING;
    }
    //L error decider
    if(L_Error==true){
        return L_ARGUMENT_INVALID;
    }
    //wiLDCARD ERROR CHECK

    if(wildcard==true){
        char *w_Check=strchr(s_Search,'*');
        if(w_Check==NULL){
            return WILDCARD_INVALID;
        }
        else if(strchr(w_Check+1,'*')!=NULL){
            return WILDCARD_INVALID;
        }
        else if(s_Search[0]!='*'&&s_Search[strlen(s_Search)-1]!='*'){
            return WILDCARD_INVALID;
        }
    }

    //part3
    char matcher[MAX_SEARCH_LEN+1];
    bool beginMatch=false;

    if(s_Search[strlen(s_Search)-1]=='*'){
        strcpy(matcher,s_Search);
        matcher[strlen(matcher)-1]='\0';
        beginMatch=true;
    }
    else{
        strcpy(matcher,(s_Search+1));
    }


        //PART 2, search and replace
    int linePos=1;
    char currentLine[MAX_LINE];
    while(fgets(currentLine,MAX_LINE,input)!=NULL){
        //if within the lines to edit it matches rewrite, else just go on
        if(linePos>=startIndex&&linePos<=endIndex){
            if(wildcard==true){
                char *currentPos=currentLine;
                while(*currentPos!='\0'){
                    //find start and end of word
                    if(!isspace(*currentPos)&&!ispunct(*currentPos)){
                        char *startWord=currentPos;
                        while(*currentPos!='\0'&&(!isspace(*currentPos)&&(!ispunct(*currentPos)))){
                            currentPos++;
                        }
                        char *endofWord=currentPos;
                        int length=endofWord-startWord;
                        int matcher_len=strlen(matcher);
                        bool matched=false;
                        //check from start
                        if(beginMatch&&length>=matcher_len){
                            matched=(strncmp(startWord,matcher,matcher_len)==0);
                        }
                        //check from end
                        else if(!beginMatch&& length>=matcher_len){
                            matched=(strncmp((endofWord-matcher_len),matcher,matcher_len)==0);
                        }
                        //replace words
                        if(matched==true){
                            fputs(r_Replace,output);
                        }
                        else{
                            fwrite(startWord,1,length,output);
                        }
                    }
                    else{
                        //if space/punct simply put it back in string
                        fputc(*currentPos,output);
                        currentPos++;
                    }
                }
            }
            else{
                char *match=strstr(currentLine,s_Search);
                char *currentPos=currentLine;
                while(match!= NULL){
                    fwrite(currentPos,1,(match-currentPos),output);
                    fputs( r_Replace,output);
                    //update currentpos to after what has been checked
                    currentPos=match+ strlen(s_Search);
                    match =strstr(currentPos,s_Search);
                }
                //write the output after the final match
                fputs(currentPos,output);
            }
            
        }
        else{
                fputs(currentLine,output);
            }
        linePos++;
    }



    return 0;
}

//Shriyans Singh 114807762


#include "unit_tests.h"
#include "hw6.h"
 

static char args[ARGS_TEXT_LEN];


//TESTS TIME
//first test:MISSING_ARGUMENT

Test(base_invalid_args, missing_arg_shri, .description="Checks for not enough arguments in the command") {
    char *test_name = "missing_arg_shri";
   // prep_files("unix.txt", test_name);    
    sprintf(args, "-s helloworld %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, test_name, TEST_OUTPUT_DIR, test_name);
    int status = run_using_system_no_valgrind(test_name, args);
    expect_error_exit(status,MISSING_ARGUMENT);
}

//second test DUPLICATE_ARGUMENT

Test(base_invalid_args, duplicate_arg_shri, .description="Checks for too many arguments in the command") {
    char *test_name = "duplicate_arg_shri";
    prep_files("unix.txt", test_name);    
    sprintf(args, "-s  helloworld -s -r %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, test_name, TEST_OUTPUT_DIR, test_name);
    int status = run_using_system_no_valgrind(test_name, args);
    expect_error_exit(status,DUPLICATE_ARGUMENT);
}

//third test: INPUT_FILE_MISSING
Test(base_invalid_args, input_file_arg_shri, .description="there is an missing input file") {
    char *test_name = "input_file_arg_shri";
    sprintf(args, "-s helloworld -r end /%s.in.txt %s/%s.out.txt", test_name, TEST_OUTPUT_DIR, test_name);
    int status = run_using_system_no_valgrind(test_name, args);
    expect_error_exit(status, INPUT_FILE_MISSING);
}

//fourth test: OUTPUT_FILE_UNRITABLE

Test(base_invalid_args, output_file_unwrite_arg_shri, .description="Output file is unwritable and results in error") {
    char *test_name = "output_file_unwrite_arg_shri"; 
    prep_files("unix.txt", test_name);    
    sprintf(args, "-s hello -r world %s/%s.in.txt /%s.out.txt", TEST_INPUT_DIR, test_name, test_name);
    int status = run_using_system_no_valgrind(test_name, args);
    expect_error_exit(status, OUTPUT_FILE_UNWRITABLE);
}

//S ARGUMENT MISSING test
Test(base_invalid_args, S_ARGUMENT_MISSING_SHRI, .description="the s option isn't included.") {
    char *test_name = "S_ARGUMENT_MISSING_SHRI";
    prep_files("unix.txt", test_name);    
    sprintf(args, "-l 1,10 -w -r hellow %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, test_name, TEST_OUTPUT_DIR, test_name);
    int status = run_using_system_no_valgrind(test_name, args);
    expect_error_exit(status, S_ARGUMENT_MISSING);
}

//R ARGUMNT MISSING Test
Test(base_invalid_args, R_ARGUMENT_MISSING_SHRI, .description="R argument is not there") {
    char *test_name = "R_ARGUMENT_MISSING_SHRI";
    prep_files("unix.txt", test_name);    
    sprintf(args, "-s hi -r -g shri -l 4,13 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, test_name, TEST_OUTPUT_DIR, test_name);
    int status = run_using_system_no_valgrind(test_name, args);
    expect_error_exit(status, R_ARGUMENT_MISSING);
}

//L_ARGUMENT_INVALID Test
Test(base_invalid_args, L_ARGUMENT_INVALID_SHRI, .description="l argument is invalid because start is larger than end") {
    char *test_name = "L_ARGUMENT_INVALID_SHRI";
    prep_files("unix.txt", test_name);    
    sprintf(args, "-s hello -r world -l -1,-5 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, test_name, TEST_OUTPUT_DIR, test_name);
    int status =run_using_system_no_valgrind(test_name, args);
    expect_error_exit(status, L_ARGUMENT_INVALID);
}
//WILDCARD_INVALID test
Test(base_invalid_args, WILDCARD_INVALID_SHRI, .description="wildcard is invalid because of no *") {
    char *test_name = "WILDCARD_INVALID_SHRI";
    prep_files("unix.txt", test_name);    
    sprintf(args, "-s hello -r world -w %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, test_name, TEST_OUTPUT_DIR, test_name);
    int status=run_using_system_no_valgrind(test_name, args);
    expect_error_exit(status, WILDCARD_INVALID);
}

//Finally a test that should just simply pass
Test(base_invalid_args,SUCCESS_TRY_Shri, .description="This is entirely valid test, should work fine*"){
    char *test_name="SUCCESS_TRY_Shri";
    prep_files("unix.txt", test_name);  
    sprintf(args, "-s hello -r world -l 1,5 %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, test_name, TEST_OUTPUT_DIR, test_name);
    int status=run_using_system_no_valgrind(test_name,args);
    expect_normal_exit(status);

}
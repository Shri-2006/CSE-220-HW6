//Shriyans Singh 114807762


#include "unit_tests.h"
#include "hw6.h"
 

TestSuite(base_output, .timeout=TEST_TIMEOUT, .disabled=false); // output file
TestSuite(base_valgrind, .timeout=TEST_TIMEOUT, .disabled=false); // valgrind result

TestSuite(base_invalid_args, .timeout=TEST_TIMEOUT); // return code to OS

static char args[ARGS_TEXT_LEN];


//TESTS TIME
Test(base_invalid_args, missing_arg_shri, .description="Checks for not enough arguments in the command") {
    char *test_name = "missing_arg_shri";
    prep_files("unix.txt", test_name);    
    sprintf(args, "-s the WOLFIE %s/%s.in.txt %s/%s.out.txt", TEST_INPUT_DIR, test_name, TEST_OUTPUT_DIR, test_name);
    run_using_system_no_valgrind(test_name, args);
    expect_outfile_matches(test_name);
}

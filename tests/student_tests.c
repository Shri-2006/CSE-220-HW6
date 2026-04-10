//Shriyans Singh 114807762


#include "unit_tests.h"
#include "hw6.h"
 
static char test_log_outfile[100];

int run_using_system(char *test_name, char *args) {
    char *executable = "./bin/hw6";
    assert(access(executable, F_OK) == 0);

    char cmd[500];
    sprintf(test_log_outfile, "%s/%s.log", TEST_OUTPUT_DIR, test_name);
#if defined(__linux__)
    sprintf(cmd, "ulimit -f 300; ulimit -t 5; valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --error-exitcode=37 ./bin/hw6 %s >> %s 2>&1",
	    args, test_log_outfile);
#else
    cr_log_warn("Skipping valgrind tests. Run tests on Linux or GitHub for full output.\n");
#endif
    return system(cmd);
}

int run_using_system_no_valgrind(char *test_name, char *args) {
    char executable[100];
    sprintf(executable, "./bin/hw6");
    assert(access(executable, F_OK) == 0);

    char cmd[500];
    sprintf(test_log_outfile, "%s/%s.log", TEST_OUTPUT_DIR, test_name);
    sprintf(cmd, "ulimit -f 300; ulimit -t 5; ./bin/hw6 %s >> %s 2>&1", args, test_log_outfile);
    return system(cmd);
}

void expect_outfile_matches(char *test_name) {
    char cmd[500];
    sprintf(cmd, "diff %s/%s.out.txt %s/%s.out.txt >> %s", TEST_EXPECTED_DIR, test_name, TEST_OUTPUT_DIR, test_name,
        test_log_outfile);
    int err = system(cmd);
    cr_expect_eq(err, 0, "The output was not what was expected (diff exited with status %d).\n", WEXITSTATUS(err));
}

void expect_normal_exit(int status) {
    cr_expect_eq(status, 0, "The program did not exit normally (status = %d).\n", status);
}

void expect_error_exit(int actual_status, int expected_status) {
    cr_expect_eq(WEXITSTATUS(actual_status), expected_status,
		 "The program exited with status %d instead of %d.\n", WEXITSTATUS(actual_status), expected_status);
}

void expect_no_valgrind_errors(int status) {
    cr_expect_neq(WEXITSTATUS(status), 37, "Valgrind reported errors -- see %s", test_log_outfile);
}

void prep_files(char *orig_file, char *input_file) {
    char cmd[200];
    sprintf(cmd, "cp %s/%s %s/%s.in.txt", TEST_ORIG_DIR, orig_file, TEST_INPUT_DIR, input_file);
    system(cmd);
}

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

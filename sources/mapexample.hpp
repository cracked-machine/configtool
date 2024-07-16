#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <argp.h>
#include <fstream>

const char *argp_program_version = "argp-ex3 1.0";
const char *argp_program_bug_address = "<bug-gnu-utils@gnu.org>";

/* Program documentation. */
static char doc[] = "Argp example #3 -- a program with options and arguments using argp";

/* A description of the arguments we accept. */
static char args_doc[] = "ARG1 ARG2";

/* The options we understand. */
static struct argp_option options[] = {
    {"key",     'k', "KEY",      0,  "Read or (if -v is used) write to key" },
    {"value",     'v', "VALUE",      0,  "Value to write to a key" },
    {"output",   'o', "FILE", 0,
    "Output to FILE instead of standard output" },
    { 0 }
};

/* Used by main to communicate with parse_opt. */
struct arguments
{
    std::string output_file;
    std::string key;
    std::string value;
};
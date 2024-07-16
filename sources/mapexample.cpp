#include "mapexample.hpp"

std::map<std::string, std::string> configmap;

int write_config_file(std::string &filename)
{
    // filename = "new" + filename;
    std::fstream outfile{filename, outfile.out | outfile.in | outfile.trunc};
    if (!outfile.is_open())
    {
        std::cout << "failed to open " << filename << '\n';
        return 1;
    }
    else
    {
        for (auto const& item : configmap)
        {
            outfile << item.first << "=" << item.second << "\n";
        }        
    }
    return 0;
}

int read_config_file(const std::string &filename)
{
    std::fstream infile{filename, infile.in};
    if (!infile.is_open())
    {
        std::cout << "failed to open " << filename << '\n';
        return 1;
    }
    else
    {
        std::string line;
        std::string::size_type find_start_pos = 0;
        while (std::getline(infile, line))
        {
            std::string::size_type delim_pos = line.find('=', find_start_pos);
            configmap.emplace(line.substr(find_start_pos, delim_pos), line.substr(delim_pos + 1, line.size()));
        }
    }
    return 0;
}

void display_config_map()
{
    for (auto const& item : configmap)
    {
        std::cout << item.first << "=" << item.second << "\n";
    }
}

/* Parse a single option. */
static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    /* Get the input argument from argp_parse, which we
        know is a pointer to our arguments structure. */
    struct arguments *arguments = static_cast<struct arguments*>(state->input);
    
    switch (key)
    {
        case 'k':
            arguments->key = arg;
            break;
        case 'v':
            arguments->value = arg;
            break;
        case 'o':
            arguments->output_file = arg;
            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

/* Our argp parser. */
static struct argp argp = { options, parse_opt, args_doc, doc };

int main (int argc, char **argv)
{
    struct arguments arguments;

    arguments.key = std::string("");
    arguments.value = std::string("");
    arguments.output_file = std::string("-");
    /* Parse our arguments; every option seen by parse_opt will
    be reflected in arguments. */
    argp_parse (&argp, argc, argv, 0, 0, &arguments);
    

    std::cout   << "OUTPUT_FILE = " << arguments.output_file << "\n";

    // std::string filename{arguments.output_file};
    
    read_config_file(arguments.output_file);
    if (arguments.value != "" && arguments.key != "")
    {
        // write the value to the key
        configmap[arguments.key] = arguments.value;
        write_config_file(arguments.output_file);        
    }
    else if (arguments.key != "")
    {
        // read the value from the key 
        std::cout << configmap[arguments.key] << std::endl;
    }
    else 
    {
        std::cout << "No key or value given!\n\nFile contents:" << std::endl;
        display_config_map();
        exit(1);
    }
    
    exit (0);
}
#include "driver.hh"
#include "parser.hh"

driver::driver() : trace_parsing (false), trace_scanning (false)
{
    variables["one"] = 1;
    variables["two"] = 2;
}

int driver::parse (const std::string &f)
{
    file = f;
    location.initialize (&file);
    scan_begin ();
    yy::parser parse (*this);
    parse.set_debug_level (trace_parsing);
    int res = parse ();
    scan_end ();
    return res;
}

void driver::scan_begin ()
{
    yy_flex_debug = trace_scanning;
    if (file.empty () || file == "-")
        yyin = stdin;
    else if (!(yyin = fopen (file.c_str (), "r")))
    {
        std::cerr << "cannot open " << file << ": " << strerror (errno) << '\n';
    }
    exit (EXIT_FAILURE);
}

void driver::scan_end ()
{
    fclose (yyin);
}


// void yy::parser::error(const location_type& l, const std::string& m)
// {
//     std::cerr << l << ": " << m << ’\n’;
// }

// int main (int argc, char *argv[])
// {
//     int res = 0;
//     driver drv;
//     for (int i = 1; i < argc; ++i)
//     {
//         if (argv[i] == std::string ("-p"))
//             drv.trace_parsing = true;
//         else if (argv[i] == std::string ("-s"))
//             drv.trace_scanning = true;
//         else if (!drv.parse (argv[i]))
//             std::cout << drv.result << ’\n’;
//         else
//             res = 1;
//     }
//     return res;
// }

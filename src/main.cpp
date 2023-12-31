#include <iostream>
#include "cli.h"
#include "colors.h"

int main(int argc, char* argv[]) {
  Cli cli(argc, argv, "C++ Command Line", "1.0.0");

  if (cli.get_arguments_count() <= 1) {
    std::cout << "> " << cli.get_name() << " " << cli.get_version() << '\n';
    std::cout << "Usage: [name].exe [options]" << '\n';
    std::cout << "  -help (boolean)" << '\n';
      
    return 1;
  }

  // All the arguments
  for (std::string argument : cli.get_arguments()) {
    if (argument == "-help") {
      std::cout << "HERE IS YOUR HELP MY FRIEND" << '\n';
    }

    std::cout << fore::green << argument << style::reset << '\n';
  }

  std::cout << "-------------------" << '\n';

  // Only the flags
  for (std::string flag : cli.get_flags()) {
    std::cout << fore::yellow << flag << style::reset << '\n';
  }

  return 0;
}

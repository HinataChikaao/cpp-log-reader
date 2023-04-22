#include <iostream>

#include "../objects/InputCommand.hpp"
#include "../exceptions/exceptions.hpp"

int main(int argc, const char **argv) {

    try {

        InputCommand inputCommand(argc, argv);

        std::string source = inputCommand.getSource();
        std::string dest = inputCommand.getDest();

        std::cout << "source is: " << source << END_LINE;
        std::cout << "dest is: " << dest << END_LINE;


    } catch (InputCommandException &ice) {
        std::cerr << ice.what() << END_LINE;
    }


    std::cout << "\nThe End ..." << std::endl;
    return EXIT_SUCCESS;
}
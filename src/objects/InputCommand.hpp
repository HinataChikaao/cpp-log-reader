
#ifndef INPUT_COMMAND
#define INPUT_COMMAND

#ifndef STD_HEADER_STRING
#define STD_HEADER_STRING

#include <string>

#endif /* STD_HEADER_STRING */


#ifndef LOG_HEADER_EXCEPTION
#define LOG_HEADER_EXCEPTION

#include "../exceptions/exceptions.hpp"

#endif /* LOG_HEADER_EXCEPTION */

#ifndef LOG_HEADER_RESOURCE
#define LOG_HEADER_RESOURCE

#include "../resource/logresource.hpp"

#endif /* LOG_HEADER_RESOURCE */

#ifndef STD_HEADER_ALGORITHM
#define STD_HEADER_ALGORITHM

#include <algorithm>

#endif /* STD_HEADER_ALGORITHM */


#define SOURCE  ("--log-source")
#define DEST  ("--log-dest")


class InputCommand {

private:
    std::string source{};
    std::string dest{};

    void init(int _argc, const char **_argv);

public:
    InputCommand() = delete;

    InputCommand(const InputCommand &inputCommand) = delete;

    InputCommand(int _argc, const char **_argv);

    virtual ~InputCommand();

    std::string &getSource();

    std::string &getDest();

};

InputCommand::InputCommand(const int _argc, const char **_argv) {

    init(_argc, _argv);
}

std::string &InputCommand::getSource() {
    return this->source;
}

std::string &InputCommand::getDest() {



    return this->dest;
}

void InputCommand::init(const int _argc, const char **_argv) {
    std::string param_one{_argv[LOG_READER_ONE]};
    std::string param_two{_argv[LOG_READER_TWO]};

    bool check_one = (_argc != LOG_READER_THREE);
    bool check_two = (param_one == param_two);
    bool check_three = ((param_one != LOG_READER_SOURCE) && (param_one != LOG_READER_DEST));
    bool check_five = ((param_one != LOG_READER_SOURCE) && (param_one != LOG_READER_DEST));
    bool check_six = std::count(param_one.begin(), param_one.end(), ':') == LOG_READER_ONE;
    bool check_seven = std::count(param_two.begin(), param_two.end(), ':') == LOG_READER_ONE;

    if (check_one || check_two || check_three || check_five || check_six || check_seven)
        throw InputCommandException(LOG_READER_INVALID_COMMANDS);

    this->source = param_one.starts_with(LOG_READER_SOURCE) ? param_one : param_two;
    this->dest = param_one.starts_with(LOG_READER_DEST) ? param_one : param_two;

}

InputCommand::~InputCommand() = default;


#endif /* INPUT_COMMAND */
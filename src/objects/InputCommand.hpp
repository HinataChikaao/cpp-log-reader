
#include <string>
#include "../exceptions/exceptions.hpp"
#include "../resource/log_resource.hpp"
#include "stringutils.hpp"


#ifndef INPUT_COMMAND
#define INPUT_COMMAND

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

    std::string getSource();

    std::string getDest();

};

InputCommand::InputCommand(const int _argc, const char **_argv) {
    init(_argc, _argv);
}

std::string InputCommand::getSource() {
    return StringUtils::getCommValue(this->source, LOG_READER_DELIMITER);
}

std::string InputCommand::getDest() {
    return StringUtils::getCommValue(this->dest, LOG_READER_DELIMITER);
}

void InputCommand::init(const int _argc, const char **_argv) {

    std::string param_one{_argv[LOG_READER_ONE]};
    std::string param_two{_argv[LOG_READER_TWO]};

    bool check_one = (_argc != LOG_READER_THREE);
    bool check_two = (param_one == param_two);
    bool check_three = ((param_one != LOG_READER_SOURCE) && (param_one != LOG_READER_DEST));
    bool check_five = ((param_one != LOG_READER_SOURCE) && (param_one != LOG_READER_DEST));
    bool check_six = StringUtils::char_count(param_one, LOG_READER_DELIMITER) == LOG_READER_ONE;
    bool check_seven = StringUtils::char_count(param_two, LOG_READER_DELIMITER) == LOG_READER_ONE;

    if (check_one || check_two || check_three || check_five || check_six || check_seven)
        throw InputCommandException(LOG_READER_INVALID_COMMANDS);

    this->source = param_one.starts_with(LOG_READER_SOURCE) ? param_one : param_two;
    this->dest = param_one.starts_with(LOG_READER_DEST) ? param_one : param_two;

}

InputCommand::~InputCommand() = default;


#endif /* INPUT_COMMAND */
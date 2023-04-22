
#include <string>
#include "../exceptions/exceptions.hpp"
#include "../resource/logresource.hpp"
#include "src/utils/stringutils.hpp"


#ifndef INPUT_COMMAND
#define INPUT_COMMAND

class commandvalidation {

private:
    std::string source{};
    std::string dest{};

    void init(int _argc, const char **_argv);

public:
    commandvalidation() = delete;

    commandvalidation(const commandvalidation &inputCommand) = delete;

    commandvalidation(int _argc, const char **_argv);

    virtual ~commandvalidation();

    std::string getSource();

    std::string getDest();

};

commandvalidation::commandvalidation(const int _argc, const char **_argv) {
    init(_argc, _argv);
}

std::string commandvalidation::getSource() {
    return StringUtils::getCommValue(this->source, LOG_READER_DELIMITER);
}

std::string commandvalidation::getDest() {
    return StringUtils::getCommValue(this->dest, LOG_READER_DELIMITER);
}

void commandvalidation::init(const int _argc, const char **_argv) {

    if (_argc != LOG_READER_THREE)
        throw InputCommandException(LOG_READER_INVALID_COMMANDS);

    std::string param_one{_argv[LOG_READER_ONE]};
    std::string param_two{_argv[LOG_READER_TWO]};

    StringUtils::logger("part one ...");

    bool check_two = (param_one != param_two);
    bool check_three = ((param_one != LOG_READER_SOURCE) && (param_one != LOG_READER_DEST));
    bool check_five = ((param_one != LOG_READER_SOURCE) && (param_one != LOG_READER_DEST));
    bool check_six = StringUtils::char_count(param_one, LOG_READER_DELIMITER) == LOG_READER_ONE;
    bool check_seven = StringUtils::char_count(param_two, LOG_READER_DELIMITER) == LOG_READER_ONE;

    StringUtils::logger("part two ...");

    if (!(check_two && check_three && check_five && check_six && check_seven))
        throw InputCommandException(LOG_READER_INVALID_COMMANDS);

    StringUtils::logger("part three ...");

    this->source = param_one.starts_with(LOG_READER_SOURCE) ? param_one : param_two;
    this->dest = param_one.starts_with(LOG_READER_DEST) ? param_one : param_two;

    StringUtils::logger("part four ...");
}

commandvalidation::~commandvalidation() = default;


#endif /* INPUT_COMMAND */
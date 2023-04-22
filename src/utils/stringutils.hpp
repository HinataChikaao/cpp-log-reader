#include <string>
#include <algorithm>


#ifndef LOG_HEADER_STRING_UTILS
#define LOG_HEADER_STRING_UTILS


class StringUtils {

public:
    static long char_count(const std::string &str, char delim);

    static std::string getCommValue(const std::string &command, char delim);

    static void logger(const std::string &message);


};

long StringUtils::char_count(const std::string &str, char delim) {
    return std::count(str.begin(), str.end(), delim);
}

std::string StringUtils::getCommValue(const std::string &command, const char delim) {
    size_t pos = command.find(delim);
    return command.substr(pos + 1);
}

void StringUtils::logger(const std::string &message) {

    std::cerr << __DATE__ << " "
              << __TIME__ << " "
              << message << END_LINE;
}


#endif /* LOG_HEADER_STRING_UTILS */
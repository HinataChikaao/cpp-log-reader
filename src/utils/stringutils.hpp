#include <string>
#include <algorithm>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string.hpp>


#ifndef LOG_HEADER_STRING_UTILS
#define LOG_HEADER_STRING_UTILS


class StringUtils {

public:

    static long char_count(const std::string &str, char delim);

    static std::string getCommValue(const std::string &command, char delim);

    static void logger(const std::string &message);

    static bool has_token(std::string &line, std::string &token);


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

bool StringUtils::has_token(std::string &line, std::string &token) {

    boost::algorithm::trim(token);
    boost::algorithm::trim(line);

    boost::algorithm::to_lower(token);
    boost::algorithm::to_lower(line);

    std::string result{};
    size_t pos;
    while ((pos = line.find(LOG_READER_AND)) != std::string::npos) {
        result = line.substr(LOG_READER_ZERO, pos);
        if (!(result.contains(token))) return false;
        line.erase(0, pos + LOG_READER_TWO);
    }

    return result.contains(token);
}


#endif /* LOG_HEADER_STRING_UTILS */
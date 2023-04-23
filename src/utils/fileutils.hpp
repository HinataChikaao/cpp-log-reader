#include <filesystem>
#include <nlohmann/json.hpp>
#include <fstream>

#ifndef LOG_HEADER_FILE_UTILS
#define LOG_HEADER_FILE_UTILS

class FileUtils {

public:

    static bool check_file_exist(const std::filesystem::path &file_name);

    static bool check_file_exist(const std::string &file_name);

    static std::filesystem::directory_iterator get_file_list(const std::filesystem::path &file_name);

    static std::filesystem::directory_iterator get_file_list(const std::string &file_name);

    static nlohmann::json read_config_file(const std::filesystem::path &file_name, std::string &category);

    static nlohmann::json read_config_file(const std::string &file_name, std::string &category);


};

bool FileUtils::check_file_exist(const std::filesystem::path &file_name) {
    return std::filesystem::exists(file_name);
}

bool FileUtils::check_file_exist(const std::string &file_name) {
    return std::filesystem::exists(file_name);
}

std::filesystem::directory_iterator FileUtils::get_file_list(const std::filesystem::path &file_name) {
    return std::filesystem::directory_iterator(file_name);
}

std::filesystem::directory_iterator FileUtils::get_file_list(const std::string &file_name) {
    return std::filesystem::directory_iterator(file_name);
}

nlohmann::json FileUtils::read_config_file(const std::filesystem::path &file_name, std::string &category) {
    std::ifstream in_file(file_name);
    nlohmann::json data = nlohmann::json::parse(in_file);
    return data.at(category);
}

nlohmann::json FileUtils::read_config_file(const std::string &file_name, std::string &category) {
    std::ifstream in_file(file_name);
    nlohmann::json data = nlohmann::json::parse(in_file);
    return data.at(category);
}


#endif /* LOG_HEADER_FILE_UTILS */
#ifndef LOG_EXCEPTIONS
#define LOG_EXCEPTIONS

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#ifndef HEADER_STRING
#define HEADER_STRING

#include <string>

#endif /* HEADER_STRING */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#ifndef HEADER_EXCEPTION
#define HEADER_EXCEPTION

#include <exception>

#endif /* HEADER_EXCEPTION */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

class InputCommandException : std::exception {

private:
    std::string message{};

public:

    explicit InputCommandException(const char *message);

    explicit InputCommandException(const std::string &message);

    InputCommandException() = delete;

    InputCommandException(const InputCommandException &inputCommandException) = delete;

    ~InputCommandException() override = default;

    [[nodiscard]] const char *what() const noexcept override;
};

const char *InputCommandException::what() const noexcept {
    return this->message.c_str();
}

InputCommandException::InputCommandException(const char *_message) {
    this->message = std::string{_message};
}

InputCommandException::InputCommandException(const std::string &_message) {
    this->message = _message;
}


#endif /* LOG_EXCEPTIONS */

#include <string>
#include <exception>

#ifndef LOG_EXCEPTIONS
#define LOG_EXCEPTIONS

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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

class SourceNotFoundException : std::exception {

private:
    std::string message{};

public:

    explicit SourceNotFoundException(const char *message);

    explicit SourceNotFoundException(const std::string &message);

    SourceNotFoundException() = delete;

    SourceNotFoundException(const SourceNotFoundException &sourceNotExistException) = delete;

    ~SourceNotFoundException() override = default;

    [[nodiscard]] const char *what() const noexcept override;
};

SourceNotFoundException::SourceNotFoundException(const char *message) {
    this->message = std::string{message};
}

SourceNotFoundException::SourceNotFoundException(const std::string &message) {
    this->message = message;
}

const char *SourceNotFoundException::what() const noexcept {
    return this->message.c_str();
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

class DestinationNotFoundException : std::exception {

private:
    std::string message{};

public:

    explicit DestinationNotFoundException(const char *message);

    explicit DestinationNotFoundException(const std::string &message);

    DestinationNotFoundException() = delete;

    DestinationNotFoundException(const SourceNotFoundException &sourceNotExistException) = delete;

    ~DestinationNotFoundException() override = default;

    [[nodiscard]] const char *what() const noexcept override;
};

DestinationNotFoundException::DestinationNotFoundException(const char *message) {
    this->message = std::string{message};
}

DestinationNotFoundException::DestinationNotFoundException(const std::string &message) {
    this->message = message;
}

const char *DestinationNotFoundException::what() const noexcept {
    return this->message.c_str();
}


#endif /* LOG_EXCEPTIONS */




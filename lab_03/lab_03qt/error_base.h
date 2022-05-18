#ifndef ERROR_BASE_H
#define ERROR_BASE_H

#include <exception>
#include <string>

class BaseError : public std::exception
{
public:
    explicit BaseError(
            const std::string &filename,
            const std::string &classname,
            const int line,
            const char *time,
            const std::string &info)
    {
        msg = "In: " + filename +
                "\n inside: " + classname +
                "\n at line: " + std::to_string(line) +
                "\n at: " + time +
                "\n occured: " + info;

    }

    const char *what() const noexcept override
    {
        return msg.c_str();
    }
private:
    std::string msg;
};

#endif // ERROR_BASE_H

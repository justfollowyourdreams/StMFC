#ifndef STM_FC_EXCEPTIONS_HPP
#define STM_FC_EXCEPTIONS_HPP

#include <exception>
#include <string>

class NotStereoException : public std::exception {
public:
    inline const char *what() { return "Provided file is not a stereo."; };
};

class FileNotCreatedException : public std::exception {
private:
    std::string message;
public:
    explicit FileNotCreatedException(const std::string &filename) {
        message = "File \"" + filename + "\" can not be created.";
    };

    inline const char *what() { return message.c_str(); };
};

class FileNotOpenedException : public std::exception {
private:
    std::string message;
public:
    explicit FileNotOpenedException(const std::string &filename) {
        message = "File \"" + filename + "\" can not be opened.";
    };

    inline const char *what() { return message.c_str(); };
};


#endif //STM_FC_EXCEPTIONS_HPP

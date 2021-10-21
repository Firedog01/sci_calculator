#ifndef STRING_HANDLING
#define STRING_HANDLING

#include <string>

struct string_handling {
    static const char CONST_C = '_';
    static const char FUNC_C = '?';
    static void remove_spaces(std::string& str);
    static std::string get_num(std::string str, int& i);
    static std::string get_embedded(std::string str, int& i);
    static std::string get_name(std::string str, int& i);
    static bool check_name_character(char c);
    static bool check_after_operator_character(char c);
    static bool check_operator(char c);
};

#endif
#ifndef MATH_NODE
#define MATH_NODE
/* flags
 * 0b0000000x - minus flag      -
 * 0b000000x0 - division flag   /
 * 0b00000x00 - power flag      ^
 * 0b00xxx000 - val flags:
 *     000    - int
 *     001    - embedded
 *     010    - variable
 *     011    - constant
 *     100    - function
 *     111    - undefined
 */

#include "../includes.h"
#include "../component/str_hdl.h"
#include <cmath>
#include <cstdint>
#include <string>
#include <utility>
#include <iostream>

class math_node {
private:
    node_ptr plus_node;
    node_ptr mul_node;
    uint8_t flags;

    void set_flag(bool val, int disp);
    virtual dong get_val();
    virtual std::string disp_val();
protected:
    void set_type(uint8_t val);
public:
    math_node(bool min, bool div, bool pow);

    node_ptr get_plus_node();
    void set_plus_node(node_ptr node);
    node_ptr get_mul_node();
    void set_mul_node(node_ptr node);

    bool is_min() const;
    void set_min(bool val);
    bool is_div() const;
    void set_div(bool val);
    bool is_pow() const;
    void set_pow(bool val);
    std::string get_type() const;

    dong enumerate();
    std::string display(); 
};
#endif


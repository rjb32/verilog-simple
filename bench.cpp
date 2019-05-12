#include <iostream>
#include <verilated.h>
#include <assert.h>
#include <memory>

#include "Vmax4.h"

template <typename T>
void userIn(const char * var_name, T & var)
{
    unsigned tmp;
    std::cout << var_name << " = ";
    std::cin >> tmp;
    assert(tmp >= 0 && tmp <= 1);
    var = tmp;
}

void userOut(const char * var_name, unsigned value)
{
    std::cout << var_name << " = " << value << '\n';
}

int main(int argc, char ** argv)
{
    /* Initialize Verilator variables */
    Verilated::commandArgs(argc, argv);

    /* Create top module instance */
    auto top = std::make_unique<Vmax4>();

    while(!Verilated::gotFinish())
    {
        /* Input */
        userIn("x0", top->x0);
        userIn("x1", top->x1);
        userIn("x2", top->x2);
        userIn("x3", top->x3);
        std::cout << '\n';

        /* top evaluation */
        top->eval();
        
        /* Output */
        userOut("y0", top->y0);
        userOut("y1", top->y1);
        userOut("y2", top->y2);
        userOut("y3", top->y3);
        std::cout << '\n';
    }

    top->final();

    return 0;
}


# verilog-simple

This is an example of a simple Verilog module with a C++ test bench using 
[Verilator](https://www.veripool.org/wiki/verilator).

The Verilog module `max4` implemented in `max4.v` gives the rightmost set bit 
on 4 bits.
The `max4` module has 4 inputs `(x0,x1,x2,x3)` and 4 outputs `(y0,y1,y2,y3)`.

The C++ test bench implemented in `bench.cpp` can be used to test the 
`max4` module.
Verilator is used to compile the Verilog module to C++, and also to
build and link the C++ test bench. Files produced by Verilator are generated
in a `build` directory by default.

The `Makefile` can be customized to be used in other projects.

## Build

Build the Verilog module and test bench:
```bash
make
```

Run the test bench simulation:
```bash
make sim
```

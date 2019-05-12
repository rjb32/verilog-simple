
module max4 (
    x0,
    x1,
    x2,
    x3,
    y0,
    y1,
    y2,
    y3
);

// Inputs
input wire x0;
input wire x1;
input wire x2;
input wire x3;

// Outputs
output wire y0;
output wire y1;
output wire y2;
output wire y3;

// Local variables
wire excl3;
wire excl2;
wire excl1;

assign y3 = x3;

assign excl3 = ~x3;
assign y2 = x2 & excl3;

assign excl2 = excl3 & ~x2;
assign y1 = x1 & excl2;

assign excl1 = excl2 & ~x1;
assign y0 = x0 & excl1;

endmodule

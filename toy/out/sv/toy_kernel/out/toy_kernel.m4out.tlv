\TLV_version [\source toy_kernel.tlv] 1d --fmtFlatSignals --bestsv --noline: tl-x.org
\SV

// TODO: Structure this for Makerchip editing, (like Mandelbrot).

module toy_kernel #(
    parameter integer C_DATA_WIDTH = 512 // Data width of both input and output data
)
(
    input wire                       clk,
    input wire                       reset,
   
    output wire                      in_ready,
    input wire                       in_avail,
    input wire  [C_DATA_WIDTH-1:0]   in_data,
    
    input wire                       out_ready,
    output wire                      out_avail,
    output wire [C_DATA_WIDTH-1:0]   out_data,
    input wire                       rand,
    output wire                      op
   );
\TLV
   |calc
      @1
         $reset = *reset;
         
         
         // YOUR CODE HERE
         $val1[31:0] = >>2$output;
         $val2[31:0] = $rand[3:0];
         //counter
         $counter = $reset?0:(>>1$counter+1);
         $valid = $reset || $counter;
      ?$valid
         @1
            $sum[31:0] = $val1[31:0] + $val2[31:0];
            $diff[31:0] = $val1[31:0] - $val2[31:0];
            $mult[31:0] = $val1[31:0] * $val2[31:0];
            $quot[31:0] = $val1[31:0] / $val2[31:0];
            
         @2
            $mem[31:0] = 
               $reset ? 0:
               ($op[2:0]==3'b101)
                  ? >>2$mem[31:0] : >>2$output;
               
            
            $output[31:0] = 
               $reset ? 0:
               ($op[2:0]==3'b000)
                  ? $sum[31:0] :
               ($op[2:0]==3'b001)
                  ? $diff[31:0] :
               ($op[2:0]==3'b010)
                  ? $mult[31:0] :
               ($op[2:0]==3'b011)
                  ? $quot[31:0] :
               ($op[2:0]==3'b100)
                  ? >>2$mem[31:0] : $val1[31:0];
            `BOGUS_USE($op $rand)

\SV
endmodule

//_\TLV_version 1d: tl-x.org, generated by SandPiper(TM) 1.9-2018/02/11-beta
`include "sp_default.vh" //_\SV

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
`include "toy_kernel_gen.sv"
generate //_\TLV
   //_|calc
      //_@1
         assign CALC_reset_a1 = reset;
         
         
         // YOUR CODE HERE
         assign CALC_val1_a1[31:0] = CALC_output_a3;
         assign CALC_val2_a1[31:0] = CALC_rand_a1[3:0];
         //counter
         assign CALC_counter_a1 = CALC_reset_a1?0:(CALC_counter_a2+1);
         assign CALC_valid_a1 = CALC_reset_a1 || CALC_counter_a1;
      //_?$valid
         //_@1
            assign CALC_sum_a1[31:0] = CALC_val1_a1[31:0] + CALC_val2_a1[31:0];
            assign CALC_diff_a1[31:0] = CALC_val1_a1[31:0] - CALC_val2_a1[31:0];
            assign CALC_mult_a1[31:0] = CALC_val1_a1[31:0] * CALC_val2_a1[31:0];
            assign CALC_quot_a1[31:0] = CALC_val1_a1[31:0] / CALC_val2_a1[31:0];
            
         //_@2
            assign CALC_mem_a2[31:0] = 
               CALC_reset_a2 ? 0:
               (CALC_op_a2[2:0]==3'b101)
                  ? CALC_mem_a4[31:0] : CALC_output_a4;
               
            
            assign CALC_output_a2[31:0] = 
               CALC_reset_a2 ? 0:
               (CALC_op_a2[2:0]==3'b000)
                  ? CALC_sum_a2[31:0] :
               (CALC_op_a2[2:0]==3'b001)
                  ? CALC_diff_a2[31:0] :
               (CALC_op_a2[2:0]==3'b010)
                  ? CALC_mult_a2[31:0] :
               (CALC_op_a2[2:0]==3'b011)
                  ? CALC_quot_a2[31:0] :
               (CALC_op_a2[2:0]==3'b100)
                  ? CALC_mem_a4[31:0] : CALC_val1_a2[31:0];
            `BOGUS_USE(CALC_op_a2 CALC_rand_a2)
endgenerate

//_\SV
endmodule
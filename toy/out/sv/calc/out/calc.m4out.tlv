\TLV_version [\source calc.tlv] 1d: tl-x.org
\SV
   // This code can be found in: https://github.com/stevehoover/RISC-V_MYTH_Workshop
   
   // Included URL: "https://raw.githubusercontent.com/stevehoover/RISC-V_MYTH_Workshop/9c5b893e6e8b317e9c9b1c0158d2cd07c65f1378/tlv_lib/calculator_shell_lib.tlv"

\SV
   module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */   // (Expanded in Nav-TLV pane.)

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
                  
            

      // Macro instantiations for calculator visualization(disabled by default).
      // Uncomment to enable visualisation, and also,
      // NOTE: If visualization is enabled, $op must be defined to the proper width using the expression below.
      //       (Any signals other than $rand1, $rand2 that are not explicitly assigned will result in strange errors.)
      //       You can, however, safely use these specific random signals as described in the videos:
      //  o $rand1[3:0]
      //  o $rand2[3:0]
      //  o $op[x:0]
      
   //m4+cal_viz(@3) // Arg: Pipeline stage represented by viz, should be atleast equal to last stage of CALCULATOR logic.

   
   // Assert these to end simulation (before Makerchip cycle limit).
   *passed = *cyc_cnt > 40;
   *failed = 1'b0;
   

\SV
   endmodule


/*
BSD 3-Clause License

Copyright (c) 2018, Steven F. Hoover
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
**
** The main application that is needed to communicate with the hardware and the
** python server.
**
** It accepts socket communications to transmit data and commands.
** The access to the hardware resources is possible through the use of a library
** "kernel.c" which contains all the functions that are needed to utilize the FPGA device.
**
** There is a set of functions that handle the communication through the socket.
**
** Author: Alessandro Comodi, Politecnico di Milano
**
*/


#include <cstdlib>


void HostApp::fakeKernel(size_t bytes_in, void * in_buffer, size_t bytes_out, void * out_buffer) {
  if (bytes_out != bytes_in) {
    cerr_line() << "VAdd fakeServer expects bytes_out (" << bytes_out << ") == bytes_in (" << bytes_in << "). Exiting." << endl;
    exit(1);
  }
  if (bytes_in & 0x3) {
    cerr_line() << "VAdd fakeKernel expects uint32's, but received " << bytes_in << " bytes." << endl;
  }
  
  for (int i = 0, uint32 * in = (uint32 *)in_buffer, uint32 * out = (uint32 *)out_buffer; i < bytes_in >> 2; i++, in++, out++) {
    *out = *in + 1;
  }
}

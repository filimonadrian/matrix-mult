#!/bin/bash

module load compilers/gnu-5.4.0

make

# ./tema2_neopt /export/asc/tema2/input
./tema2_opt_m /export/asc/tema2/input
# ./tema2_blas /export/asc/tema2/input

make clean


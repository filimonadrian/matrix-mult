#!/bin/bash

rm out1 out2 out3
rm run_tema2.sh.*

qsub -cwd -q ibm-nehalem.q run_tema2.sh
# qsub -cwd -q ibm-nehalem.q cachegrind.sh

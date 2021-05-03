valgrind --tool=cachegrind \
         --branch-sim=yes \
         --verbose \
         --log-file=opt.cache \
 	 ./tema2_opt_m /export/asc/tema2/input_valgrind

valgrind --tool=cachegrind \
         --branch-sim=yes \
         --verbose \
         --log-file=neopt.cache \
 	 ./tema2_neopt /export/asc/tema2/input_valgrind

valgrind --tool=cachegrind \
         --branch-sim=yes \
         --verbose \
         --log-file=blas.cache \
 	 ./tema2_blas /export/asc/tema2/input_valgrind

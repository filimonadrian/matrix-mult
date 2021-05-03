valgrind --tool=memcheck
         --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=opt.memory \
 	 ./tema2_opt_m /export/asc/tema2/input_valgrind

valgrind --tool=memcheck
         --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=neopt.memory \
 	 ./tema2_neopt /export/asc/tema2/input_valgrind

valgrind --tool=memcheck
         --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=blas.memory \
 	 ./tema2_blas /export/asc/tema2/input_valgrind

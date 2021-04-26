#include <stdio.h>
 #include <stdlib.h>
 // API MPI
#include <mpi.h>
#include <ctime>

int main(int argc, char** argv) {

  // Inicializa o MPI
   MPI_Init(NULL, NULL);

   // numero total de processos
   int world_size;
   MPI_Comm_size(MPI_COMM_WORLD, &world_size);

   // ID (rank) do processo
   int world_rank;
   MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

   // cronometro
   time_t init = time (NULL);

   // semente do gerador randômico
   srand (init + world_rank);

   double x = 1.0+ double(rand () % 100)+double(rand()%9999)/10000;

   printf ("%d: %f\n", world_rank, x);

       double y;
       MPI_Reduce (&x, &y, 1, MPI_DOUBLE,   MPI_MAX, 0, MPI_COMM_WORLD);

      if (world_rank == 0)
         printf ("Maximo entre os numeros = %f\n",  y);
      // Finaliza o MPI
      MPI_Finalize();

      return 0;
     }
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main(int argc, char **argv)
{
	int total_sum = 0;
	MPI_Init(&argc, &argv);
	int s, r, sum;
	MPI_Status stats;
	MPI_Comm_size(MPI_COMM_WORLD, &s);
	MPI_Comm_rank(MPI_COMM_WORLD, &r);

	if (r == 0) {
		srand(r);
		sum = rand() % 100 + 1;
		printf("%d\n", sum);
		total_sum += sum;
		for (int i = 1; i < s; i++)
		{
			MPI_Recv(&sum, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &stats);
			total_sum += sum;
		}
		printf("Total sum:\t %d\n", total_sum);
	}



	else
	{
		srand(r);
		sum = rand() % 100 + 1;
		printf("%d\n",sum);
		MPI_Send(&sum, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);

	}

	MPI_Finalize();

	return 0;
}

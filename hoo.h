# include <cstdlib>
# include <iostream>
# include <iomanip>

using namespace std;

# include "mpi.h"

int main ( int argc, char *argv[] );

//**********************************************************************

int main ( int argc, char *argv[] )

//**********************************************************************
//
//  Purpose:
//
//    HOO is a simple MPI test program.
//
//  Discussion:
//
//    Each process prints out a "Hello, world!" message.
//
//    The master process also prints out a short message.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 August 2013
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gropp, Lusk, Skjellum,
//    Using MPI,
//    Portable Parallel Programming with the Message-Passing Interface,
//    Second Edition,
//    MIT Press, 1999.
//
{
  int num_procs;
  int world_id;
//
//  Initialize MPI.
//
  MPI::Init ( argc, argv );
//
//  Get the number of processes.
//
  num_procs = MPI::COMM_WORLD.Get_size ( );
//
//  Get the individual process ID.
//
  world_id = MPI::COMM_WORLD.Get_rank ( );
//
//  Process 0 prints an introductory message.
//
  if ( world_id == 0 ) 
  {
    cout << "\n";
    cout << "HOO - Master process:\n";
    cout << "  C++ version\n";
    cout << "  An MPI test program.\n";
    cout << "  The number of processes is " << num_procs << "\n";
    cout << "\n";
  }
//
//  Every process prints a hello.
//
  cout << "  Process " << world_id << " says 'Hello, world!'\n";
//
//  Shut down MPI.
//
  MPI::Finalize ( );
//
//  Terminate.
//
  if ( world_id == 0 )
  {
    cout << "\n";
    cout << "HOO - Master process:\n";
    cout << "  Normal end of execution.'\n";
  }
  return 0;
}
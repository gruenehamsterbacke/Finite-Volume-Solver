# Finite Volume Solver

The aim is to develop a Finite-Volume-Solver in C++. 

## Roadmap:

(0) Basic tools (like import data files etc.)

(1) Implement a class of solvers for linear systems of equations (later: include LAPACK to efficiently solve the equations)

(2) Implement a Finite-Volume-Solver for a simple PDEs (steady) for a simple geometry (mesh) 

(3) Implement time-discretization schemes 

(4) Develop a toolbox for mesh generation 

(5) Develop a toolbox for post-processing 

(7) Add a graphical interface

## Solver for linear systems

Gauss elimination (including a pivot row change): limitations: in general slow and rounding errors can become significant

Jacobi and Gauss Seidel: iterative methods, limitations: The Jacobi and Gauss–Seidel methods for solving a linear system converge if the matrix is strictly (or irreducibly) diagonally dominant (ref wikipedia: https://en.wikipedia.org/wiki/Diagonally_dominant_matrix), maybe implement partial pivoting (??)

more methods are coming soon...

define and document test cases for each solver

## Finite Volume Solver

insert PDE with appropriate boundary conditions, insert mesh, calculate fluxes etc.


## Manual




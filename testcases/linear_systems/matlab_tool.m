% MATLAB Script to export the testcases for the linear system to (a) a
% string (b) to a text file

clear all; 
clc;
close all;

%% csv import tool
% reads a *.csv data file into matlab and provides a C code for the array

%adjust folder
i=6;

% ggf. Bedingung abfangen, falls Datei nicht gefunden wird;

if (i<10)
filename_matrix=['testcase0',num2str(i),'_matrix.csv'];
filename_vector=['testcase0',num2str(i),'_vector.csv'];
filename_solution=['testcase0',num2str(i),'_solution.csv'];
else
filename_matrix=['testcase',num2str(i),'_matrix.csv'];
filename_vector=['testcase',num2str(i),'_vector.csv'];
filename_solution=['testcase',num2str(i),'_solution.csv'];
end

A = dlmread(filename_matrix,';');
b = dlmread(filename_vector,';');
phi = dlmread(filename_solution,';');

% convert matrix to C code

dim=size(A,1);

part1=['double ','A','[',num2str(dim),']','[',num2str(dim),']={']

for i=1:1:dim;
    
    part2='{';
    for j=1:1:dim
        part2=[part2,num2str(A(i,j))];
        if (j < dim)
            part2=[part2,','];
        end
    end
    part2=[part2,'}'];
    part1=[part1,part2];
        if (i < dim)
            part1=[part1,','];
        end
end
part1=[part1,'};']

    
    part1=['double b[',num2str(dim),']={'];
    part2=['double solution_exact[',num2str(dim),']={'];
for i=1:1:dim
    part1=[part1,num2str(b(i))];
    part2=[part2,num2str(phi(i))];
        
        if (i < dim)
            part1=[part1,','];
            part2=[part2,','];
        end
end
    part1=[part1,'};']
    part2=[part2,'};']


%check
phi_check=linsolve(A,b);
phi-phi_check
    


%% Convert matrix and arrays to LaTeX Code

latex_matrix=['\left( \begin{matrix}'];

for i=1:1:dim
    for j=1:1:dim
        latex_matrix=[latex_matrix,num2str(A(i,j))];
            if (j < dim)
                latex_matrix=[latex_matrix,'&'];
            end
    end
    
    if (i < dim)
        latex_matrix=[latex_matrix,'\\'];
    end
    
end

latex_matrix=[latex_matrix,'\end{matrix} \right)']


    
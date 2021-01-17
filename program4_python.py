import numpy as np
import time
import random

def multiplyOptimized(matrix1, matrix2, result, nrows1, ncols2, ncols1):
    for i in range(0, nrows1):
        iRowA = matrix1[i]
        iRowC = result[i]
        for k in range(0, ncols1):
            kRowB = matrix2[k]
            ikA = iRowA[k]
            for j in range(0, ncols2):
                iRowC[j] += ikA * kRowB[j]


if __name__ == '__main__':
    print('<----Dimension of Matrix 1---->\n')
nrows1 = int(input('Number of rows : '))
ncols1 = int(input('Number of columns : '))
print('\n<----Dimension of Matrix 2---->\n')
print(f'Number of rows (set by default equal to ncols of matrix 1): {ncols1}')
nrows2 = ncols1
ncols2 = int(input('Number of columns : '))

# Initializing matrix 1 and matrix 2
matrix1 = [random.choices(range(0, 100), k=ncols1) for _ in range(nrows1)]
matrix2 = [random.choices(range(0, 100), k=ncols2) for _ in range(nrows2)]
result = [random.choices(range(0,1), k=ncols2) for _ in range(nrows1)]

print(f'\n<-----Matrix 1----->\n\n{matrix1}')
print(f'\n<-----Matrix 2----->\n\n{matrix2}')
start = time.time()
multiplyOptimized(matrix1, matrix2, result, nrows1, ncols2, ncols1)
end = time.time()
start2 = time.time()
np.matmul(matrix1, matrix2)
end2 = time.time()
print(f'\n<-----Result----->\n\n{result}')
print(f"Runtime of the multiplication with self defined algo is {end - start}")
print(f"Runtime of the program is {end2- start2}")

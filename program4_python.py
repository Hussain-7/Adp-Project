import numpy as np
import time

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
matrix1 = np.random.randint(100, size=(nrows1, ncols1))
matrix2 = np.random.randint(100, size=(nrows2, ncols2))
result = np.zeros((nrows1, ncols2), dtype=int)
print(f'\n<-----Matrix 1----->\n\n{matrix1}')
print(f'\n<-----Matrix 2----->\n\n{matrix2}')
start = time.time()
multiplyOptimized(matrix1, matrix2, result, nrows1, ncols2, ncols1)
end = time.time()
print(f'\n<-----Result----->\n\n{result}')
print(f"Runtime of the program is {end - start}")

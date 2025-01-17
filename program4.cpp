#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

// This function multiplies
// mat1[][] and mat2[][], and
// stores the result in res[][]
void multiply(int **mat1,
			int **mat2,
			int **res,int nrow1,int ncols2,int ncols1)
{
	int i, j, k;
	for (i = 0; i < nrow1; i++) {
		for (j = 0; j < ncols2; j++) {
			res[i][j] = 0;
			for (k = 0; k < ncols1; k++)
				res[i][j] += mat1[i][k] * mat2[k][j];
		}
	}
}
void multiplyOptimized(int **mat1,
			int **mat2,
			int **res,int nrows1,int ncols2,int ncols1)
{
	for (int i = 0; i < nrows1; i++) {
    int* iRowA = mat1[i];
    int* iRowC = res[i];
    for (int k = 0; k < ncols1; k++) {
        int* kRowB = mat2[k];
        double ikA = iRowA[k];
        for (int j = 0; j < ncols2; j++) {
            iRowC[j] += ikA * kRowB[j];
        }
    }
}
}

void initializeMatrix(int **matrix, int nrows, int ncols){
 for (int i = 0; i < nrows; i++)
        for (int j = 0; j < ncols; j++)
           matrix[i][j]  = rand() % 100;
}
void printMatrix(int **matrix, int nrows, int ncols){
for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
            cout << matrix[i][j]  << " ";
 
        cout<<endl;
    }
}

int main()
{
    int ncols1,nrows1,ncols2,nrows2;
    int count;
    cout<<"<----Dimension of Matrix 1---->\n"<<endl;
    cout<<"Number of rows : ";
    cin>>nrows1;
    cout<<"Number of columns : ";
    cin>>ncols1;

    cout<<"\n<----Dimension of Matrix 2---->\n"<<endl;
    /*Not taking input for nrows of 2nd array since to multiply two matrixes no columns
       of first matrix must be equal to number of rows of second hence assuming them equal */
    cout<<"Number of rows (set by default equal to ncols of matrix 1): "<<ncols1<<endl;
    nrows2=ncols1;
    cout<<"Number of columns : ";
    cin>>ncols2;

    //defining matrix 1 dynamically
     int** matrix1 = new int*[nrows1];
     for (int i = 0; i < nrows1; i++)
        matrix1[i] = new int[ncols1];

    //defining matrix 2 dynamically
    int** matrix2 = new int*[nrows2];
     for (int i = 0; i < nrows2; i++)
        matrix2[i] = new int[ncols2];

    //defining result matrix dynamically
    int** result = new int*[nrows1];
     for (int i = 0; i < nrows1; i++)
        result[i] = new int[ncols2];
    
    cout<<"\n<----Matrix 1---->\n"<<endl;
    initializeMatrix(matrix1,nrows1,ncols1);
    printMatrix(matrix1,nrows1,ncols1);
    cout<<"\n<----Matrix 2---->\n"<<endl;
    initializeMatrix(matrix2,nrows2,ncols2);
    printMatrix(matrix2,nrows2,ncols2);


    time_t start = time(NULL);
	multiply(matrix1, matrix2, result,nrows1,ncols2,ncols1);
    time_t end = time(NULL);
    double execution_time = 0.0;
    execution_time=end-start;
    printf("\n\nTime elpased is in seconds: %f\n\n", execution_time);


    time_t start2 = time(NULL);
	multiplyOptimized(matrix1, matrix2, result,nrows1,ncols2,ncols1);
    time_t end2 = time(NULL);
    double execution_time2 = 0.0;
    execution_time=end2-start2;
    printf("\n\nTime elpased is in seconds: %f\n\n", execution_time2);
	// cout << "\n<----Result Matrix---->\n\n";
    // printMatrix(result,nrows1,ncols2);

	return 0;
}


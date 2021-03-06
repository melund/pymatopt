#include "mex.h"
#include "util.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    int nc;
    double* data;
    /* Function signature for the function handle */
    double* (*fun)(double*);
    /* Get the actual function handle back */
    fun = (double* (*)(double*)) *((mwSize*) mxGetData(prhs[0]));
    /* Call the C function through the handle and set the data*/
    data = fun(mxGetPr(prhs[2]));
    /* how much data to expect */
    nc = (int) mxGetScalar(prhs[1]);
    plhs[0] = makeArray(data,1,nc);
}
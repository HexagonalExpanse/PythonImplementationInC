#include <Python.h>
#include <vector>
#include <numeric>  
#include <cmath>    

//based on Matt Fowler implementation and RealPython Tutorial

double mean_func(const std::vector<double>& input){
    double sum = std::accumulate(input.begin(), input.end(), 0.0);
    double mean = sum / input.size();

    return mean;
}

//using function by Matt Fowler
double std_dev_func(const std::vector<double>& input){
    double squareSum = std::inner_product(input.begin(), input.end(), input.begin(), 0.0);

    double mean_val = mean_func(input);
    return sqrt(squareSum / input.size() - mean_val * mean_val); //in actual project, make students use the function they created.
}

//using Matt Fowler's code idea to parse, need to make guide
//for students in future when actually teaching it
static PyObject *mean(PyObject *self, PyObject* args){
    PyObject *input;
    if (!PyArg_ParseTuple(args, "O", &input)) { 
        return NULL;
    }

    if (!PyTuple_Check(input)) {
        PyErr_SetString(PyExc_TypeError, "Expected a tuple");
        return NULL;
    }


    int size = PyTuple_Size(input);

    std::vector<double> list;
    list.resize(size);

    for(int i = 0; i < size; i++){
        list[i] = PyFloat_AS_DOUBLE(PyTuple_GetItem(input, i));
    }

    double data_out = mean_func(list);

    return PyFloat_FromDouble(data_out);
}

static PyObject *std_dev(PyObject *self, PyObject* args){
    PyObject *input;
    if (!PyArg_ParseTuple(args, "O", &input)) {
        return NULL;
    }

    if (!PyTuple_Check(input)) {
        PyErr_SetString(PyExc_TypeError, "Expected a tuple");
        return NULL;
    }
    
    int size = PyTuple_Size(input);

    std::vector<double> list;
    list.resize(size);

    for(int i = 0; i < size; i++){
        list[i] = PyFloat_AS_DOUBLE(PyTuple_GetItem(input, i));
    }

    double data_out = std_dev_func(list);

    return PyFloat_FromDouble(data_out);
}


//Method table
static PyMethodDef MathMethods[] = {
    {"mean", mean, METH_VARARGS, "Calculate mean of a list"},
    {"std_dev", std_dev, METH_VARARGS, "Calculate standard deviation of a list"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef MathMethod = {
    PyModuleDef_HEAD_INIT,
    "MathMethod",
    "Python interface for the C++ Math Calculations",
    -1,
    MathMethods
};

PyMODINIT_FUNC PyInit_MathMethod(void) {
    return PyModule_Create(&MathMethod);
}
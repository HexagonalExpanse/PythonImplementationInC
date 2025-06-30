from . import MathMethod

class EmptyArray(Exception):
    pass

class NonArray(Exception):
    pass

class NonNumeric(Exception):
    pass


def mean(input):
    if not isinstance (input, (list, tuple)):
        raise NonArray("Input is not an array")

    input = tuple(input)

    if len(input) == 0:
        raise EmptyArray("Array is empty")

    if not all(isinstance(item, (int, float)) for item in input):
        raise NonNumeric("Input array has non numeric values")
    
    if not all(isinstance(item, (float)) for item in input):
        input = [float(i) for i in input]

    return MathMethod.mean(input)


def std_dev(input):
    if not isinstance (input, (list, tuple)):
        raise NonArray("Input is not an array")

    input = tuple(input)

    if len(input) == 0:
        raise EmptyArray("Array is empty")

    if not all(isinstance(item, (int, float)) for item in input):
        raise NonNumeric("Input array has non numeric values")
    
    if not all(isinstance(item, (float)) for item in input):
        input = [float(i) for i in input]

    return MathMethod.std_dev(input)
    

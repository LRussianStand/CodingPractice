"""
minst_loader
------------
A library to load the MNIST image data. for details of the data structures that are
returned, see the doc strings for " load_data" and " load_data_wrapper", in practice
, "load_data_wrapper" is the function usually called by our neural network code
"""

import pickle
import gzip

import numpy as np
def load_data():
    """
    Return the MNIST data as a tuple containing the training data, the validation data, and the
    test data.
    The "training_data" us returned as a tuple with two entries. the first entry contains the actual
    training images. This is a numpy ndarray with 50000 entries. Each entry is, in turn, a numpy ndarray
    with 784 values, representing the 28*28 = 784 pixles in a single MNIST image

    The second entry in the "training_data" tuple is a numpy ndarray containing 50000 entries. Those entries
    are just the digit value(0 .. 9) for the corresponding images contained in the first entry of the tuple

    the "validation_data" and "test_data" are similar , expect each contain only 10000 images

    This is a nice data format, but for use in neural networks it is helpful to modify the format
    of the "training_data" a little. That is done in the wrapper function "load_data_wrapple", see
    below
    :return:
    """
    f = gzip.open('D:/Neural network/data/mnist.pkl.gz', 'rb')
    training_data, validation_data, test_data = pickle.load(f, encoding='bytes')
    f.close()
    return training_data, validation_data, test_data

def load_data_wrapper():
    """Return a tuple containing ``(training_data, validation_data,
    test_data)``. Based on ``load_data``, but the format is more
    convenient for use in our implementation of neural networks.
    In particular, ``training_data`` is a list containing 50,000
    2-tuples ``(x, y)``. ``x`` is a 784-dimensional numpy.ndarray
    containing the input image. ``y`` is a 10-dimensional
    numpy.ndarray representing the unit vector corresponding to the
    correct digit for ``x``.
    ``validation_data`` and ``test_data`` are lists containing 10,000
    2-tuples ``(x, y)``. In each case, ``x`` is a 784-dimensional
    numpy.ndarry containing the input image, and ``y`` is the
    corresponding classification, i.e., the digit values (integers)
    corresponding to ``x``.
    Obviously, this means we're using slightly different formats for
    the training data and the validation / test data. These formats
    turn out to be the most convenient for use in our neural network
    code."""
    tr_d, va_d, te_d = load_data()
    training_inputs = [np.reshape(x, (784, 1)) for x in tr_d[0]]
    training_results = [vectorized_result(y) for y in tr_d[1]]
    training_data = list(zip(training_inputs, training_results))
    validation_inputs = [np.reshape(x, (784, 1)) for x in va_d[0]]
    validation_data = list(zip(validation_inputs, va_d[1]))
    test_inputs = [np.reshape(x, (784, 1)) for x in te_d[0]]
    test_data = list(zip(test_inputs, te_d[1]))
    return training_data, validation_data, test_data

def vectorized_result(j):
    e = np.zeros((10, 1))
    e[j] = 1.0
    return e
"""
A module to implement the stochastic gradient descent learning algorithm for
a feedforward neural network. Gradient are calculated using backpropagation.
Note that  I have focus on makeing the code simple, easilly readable, and easyily
modifiable. It is not optimized, and omits mant desirable features.
"""

import numpy as np
import random
# import json
class Network(object):

    def __init__(self, sizes):
        """
        The list "size" contains the number of neurons in the respective layers of the network.
        For example, if the list was[2 , 3 ,4] the it would be a three-layer network , with the
        first layer containing 2 neurons, the second layer 3 neurons, and the third layer 1 neuron
        The biases and weight for the network are initialized randomly,, using a Gaussian distribution
        with mean 0, and variance 1. Note that the first layer is assumed be be an input layer, and by
        convention we won't set ant biases for those neurons, since biases are only ever used in computing
        the outputs from later layers
        :param sizes:
        """
        self.num_layers = len(sizes) #the number of layer in  network
        self.sizes = sizes
        #使⽤Numpy 的np.random.randn 函数来⽣成均值为0，标准差为1 的⾼斯分布
        self.biases = [np.random.randn(y, 1) for y in sizes[1:]]
        self.weights = [np.random.randn(y, x)
                        for x, y in zip(sizes[:-1], sizes[1:])]
    def feedforward(self, a):
        """return the output if the network id "a" is input"""
        for b, w in zip(self.biases, self.weights):
            a = sigmoid(np.dot(w, a) + b)
        return a

    def SGD(self, training_data, epochs, min_batch_size, eta, test_data=None, filename='accuracy'):
        """Train the neural network using min_batch_size stochastic
        gradient descent. the "training_data" is a list of tuples "(x , y)"
        representing the training inputs and the desired outputs. the other non-
        optional parameter are self-explanatory. If "test_data" is provided then the
        network will evaluated against the test data after each epoch. and partial progress
        printed out. This is useful for tracking progress. but slows things down substantially"""
        if test_data:
            n_test = len(test_data)
        n = len(training_data)
        evaluation_accuracy = []
        for j in range(epochs):
            random.shuffle(training_data)
            min_batches = [
                training_data[k: k+min_batch_size]
                for k in range(0, n, min_batch_size)
            ]
            for min_batch in min_batches:
                self.update_mini_batch(min_batch, eta)
            accuracy = self.evaluate(test_data)
            evaluation_accuracy.append(accuracy)
            if test_data:
                print("Epoch {0}:{1}/{2}".format(j, accuracy, n_test))
            else:
                print("Epoch {0} complete.".format(j))
        return evaluation_accuracy

    def update_mini_batch(self, mini_batch, eta):
        """Update the network's weight and biases by applying gradient descent
        using backpropagation to a single mini batch . The "min_batch" is a list
        of tuples "(x , y)", and "eta" is the learning rate """
        nabla_b = [np.zeros(b.shape) for b in self.biases]
        nabla_w = [np.zeros(w.shape) for w in self.weights]

        for x, y in mini_batch:
            delta_nabla_b, delta_babla_w = self.backprop(x, y)
            nabla_b = [nb + dnb for nb, dnb in zip(nabla_b, delta_nabla_b)]
            nabla_w = [nw + dnw for nw, dnw in zip(nabla_w, delta_babla_w)]
        self.weights = [w - eta * nw
                        for w, nw in zip(self.weights, nabla_w)]
        self.biases = [b - eta * nb
                       for b, nb in zip(self.biases, nabla_b)]

    def backprop(self, x, y):
        """Return a tuple "(nabla_b , nabla_w)" representing the gradient
         for the cost function c_x. "nabla_b" and "nabla_w" are layer-by-layer
          list of numpy arrays, similar to "self.biases" and "self.weight". """
        nabla_b = [np.zeros(b.shape) for b in self.biases]
        nabla_w =[np.zeros(w.shape) for w in self.weights]
        #feedforward
        activation = x
        activations = [x]#list to store all the activations, layer by layer
        zs = []# list to store all the z vectors, layer by layer
        for b, w in zip(self.biases, self.weights):
            z = np.dot(w, activation) + b
            zs.append(z)
            activation = sigmoid(z)
            activations.append(activation)
        #backword pass
        delta = self.cost_derivative(activations[-1], y) * sigmoid_prime(zs[-1])
        nabla_b[-1] = delta
        nabla_w[-1] = np.dot(delta, activations[-2].transpose())

        # Note that the variable l in the loop below is used a
        #little differently to the notation in chapter 2 of the book. Here
        #l = 1 means the last layer of neurons, l = 2 is the second-layer, and so on
        #It is a renumbering of the scheme in the book, used here to take advantage of the fact
        #that python cam us negative indices in lists

        for l in range(2, self.num_layers):
            z = zs[-l]
            sp = sigmoid_prime(z)
            delta = np.dot(self.weights[-l+1].transpose(), delta) * sp
            nabla_b[-l] = delta
            nabla_w[-l] = np.dot(delta, activations[-l-1].transpose())

        return nabla_b, nabla_w

    def evaluate(self, test_data):
        """
        return the number of test inputs for which the neural network
        outputs the correct result. Note that the neural network's output
        is assumed to be the index of whichever neuron in the final layer has the highest activation.
        :param test_data:
        :return:
        """
        test_results = [(np.argmax(self.feedforward(x)), y)
                       for(x, y) in test_data]
        return sum(int(x == y) for (x, y) in test_results)

    def cost_derivative(self, output_activations, y):
        """
        return the vector of partial derivatives \partial c_x / \partial
        a for the output activations.
        :param output_activations:
        :param y:
        :return:
        """
        return output_activations - y


 #### Miscellaneous function
def sigmoid(z):
    # the sigmoid function
    return 1.0 / (1.0 + np.exp(-z))

def sigmoid_prime(z):
    """Derivative of the sigmoid function"""
    return sigmoid(z)*(1-sigmoid(z))
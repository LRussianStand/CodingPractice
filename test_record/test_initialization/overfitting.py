"""
encropy
~~~~~~~~~~~
Plot graphs to illustrate the problem of encropy.
"""
# Standard library
import json
import random

# My library
from test_record import Neural_Network_CrossEntropy, mnist_loader

# Third-party libraries
import matplotlib.pyplot as plt
import numpy as np

def main(filename, num_epochs, filename_old,
         training_cost_xmin=0,
         test_accuracy_xmin=0,
         test_cost_xmin=0,
         training_accuracy_xmin=0,
         training_set_size=1000,
         lmbda=0.0):
    """``filename`` is the name of the file where the results will be
       stored.  ``num_epochs`` is the number of epochs to train for.
       ``training_set_size`` is the number of images to train on.
       ``lmbda`` is the regularization parameter.  The other parameters
       set the epochs at which to start plotting on the x axis.
    """
    # run_network(filename, filename_old, num_epochs, training_set_size, lmbda)
    make_plots(filename, num_epochs, filename_old,
               training_cost_xmin,
               test_accuracy_xmin,
               test_cost_xmin,
               training_accuracy_xmin,
               training_set_size)


def run_network(filename, filename_old, num_epochs=20, training_set_size=5000, lmbda=5.0):
    """Train the network for ``num_epochs`` on ``training_set_size``
    images, and store the results in ``filename``.  Those results can
    later be used by ``make_plots``.  Note that the results are stored
    to disk in large part because it's convenient not to have to
    ``run_network`` each time we want to make a plot (it's slow).
    """
    # Make results more easily reproducible

    random.seed(12345678)
    np.random.seed(12345678)
    training_data, validation_data, test_data = mnist_loader.load_data_wrapper()
    net = Neural_Network_CrossEntropy.Network([784, 30, 10], cost=Neural_Network_CrossEntropy.CrossEntropyCost())
    test_cost, test_accuracy, training_cost, training_accuracy \
        = net.SGD(training_data[:training_set_size], num_epochs, 10, 0.5,
                  evaluation_data=test_data, lmbda=lmbda,
                  monitor_evaluation_cost=True,
                  monitor_evaluation_accuracy=True,
                  monitor_training_cost=True,
                  monitor_training_accuracy=True)
    f = open(filename, "w")
    json.dump([test_cost, test_accuracy, training_cost, training_accuracy], f)
    f.close()

    net_old = Neural_Network_CrossEntropy.Network([784, 30, 10], cost=Neural_Network_CrossEntropy.CrossEntropyCost())
    net_old.large_weight_initializer()
    test_old_cost, test_old_accuracy, training_old_cost, training_old_accuracy \
        = net_old.SGD(training_data[:training_set_size], num_epochs, 10, 0.5,
                  evaluation_data=test_data, lmbda=0.0,
                  monitor_evaluation_cost=True,
                  monitor_evaluation_accuracy=True,
                  monitor_training_cost=True,
                  monitor_training_accuracy=True)
    f = open(filename_old, "w")
    json.dump([test_old_cost, test_old_accuracy, training_old_cost, training_old_accuracy], f)
    f.close()


def make_plots(filename='reg_new', num_epochs=20, filename_old='reg_new',
               training_cost_xmin=0,
               test_accuracy_xmin=0,
               test_cost_xmin=0,
               training_accuracy_xmin=0,
               training_set_size=5000):
    """Load the results from ``filename``, and generate the corresponding
       plots. """
    f = open(filename, "r")
    test_cost, test_accuracy, training_cost, training_accuracy = json.load(f)
    f.close()
    f = open(filename_old, "r")
    test_old_cost, test_old_accuracy, training_old_cost, training_old_accuracy = json.load(f)
    f.close()
    plot_compare_training_cost(training_cost, training_old_cost, num_epochs, training_cost_xmin)
    plot_compare_test_accuracy(test_accuracy, test_old_accuracy, num_epochs, test_accuracy_xmin)
    plot_compare_test_cost(test_cost, test_old_cost, num_epochs, test_cost_xmin)
    plot_compare_training_accuracy(training_accuracy, training_old_accuracy, num_epochs,
                           training_accuracy_xmin,
                           training_set_size)
    plot_overlay(test_accuracy, training_accuracy, num_epochs
                 , min(test_accuracy_xmin, training_accuracy_xmin),
                 training_set_size, filename=filename)
    plot_overlay(test_old_accuracy, training_old_accuracy, num_epochs
                 , min(test_accuracy_xmin, training_accuracy_xmin),
                 training_set_size, filename=filename_old)



def plot_compare_training_cost(training_cost, training_old_cost, num_epochs, training_cost_xmin):
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot(np.arange(training_cost_xmin, num_epochs),
            training_cost[training_cost_xmin:num_epochs],
            color='#2A6EA6',
            label='Cost on the  BP(initial) training data')
    ax.plot(np.arange(training_cost_xmin, num_epochs),
            training_old_cost[training_cost_xmin:num_epochs],
            color='#FFA933',
            label='Cost on the  BP training data')
    ax.set_xlim([training_cost_xmin, num_epochs])
    ax.grid(True)
    ax.set_xlabel("Epoch")
    ax.set_title('Cost on the training data')
    plt.legend(loc="NorthEast")
    plt.show()

def plot_compare_training_accuracy(training_accuracy, training_old_accuracy, num_epochs,
                           training_accuracy_xmin, training_set_size):
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot(np.arange(training_accuracy_xmin, num_epochs),
            [accuracy*100.0/training_set_size
             for accuracy in training_accuracy[training_accuracy_xmin:num_epochs]],
            color='#2A6EA6',
            label="Accuracy on the  BP(initial) training data")
    ax.plot(np.arange(training_accuracy_xmin, num_epochs),
            [accuracy*100.0/training_set_size
             for accuracy in training_old_accuracy[training_accuracy_xmin:num_epochs]],
            color='#FFA933',
            label="Accuracy on the  BP training data")
    ax.set_xlim([training_accuracy_xmin, num_epochs])
    ax.grid(True)
    ax.set_xlabel('Epoch')
    ax.set_title('Accuracy (%) on the training data')
    plt.legend(loc="SouthEast")
    plt.show()

def plot_compare_test_accuracy(test_accuracy, test_old_accuracy, num_epochs, test_accuracy_xmin):
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot(np.arange(test_accuracy_xmin, num_epochs),
            [accuracy/100
             for accuracy in test_accuracy[test_accuracy_xmin:num_epochs]],
            color='#2A6EA6',
            label="Accuracy on the  BP(initial) test data")
    ax.plot(np.arange(test_accuracy_xmin, num_epochs),
            [accuracy/100
            for accuracy in test_old_accuracy[test_accuracy_xmin:num_epochs]],
            color='#FFA933',
            label="Accuracy on the  BP test data")
    ax.set_xlim([training_accuracy_xmin, num_epochs])
    ax.grid(True)
    ax.set_xlabel('Epochs')
    ax.set_title('Accuracy (%) on the test data')
    plt.legend(loc="SouthEast")
    plt.show()

def plot_compare_test_cost(test_cost, test_old_cost, num_epochs, test_cost_xmin):
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot(np.arange(test_cost_xmin, num_epochs),
            test_cost[test_cost_xmin:num_epochs],
            color='#2A6EA6',
            label="Cost on the  BP(initial) test data")
    ax.plot(np.arange(test_cost_xmin, num_epochs),
            test_old_cost[test_cost_xmin:num_epochs],
            color='#FFA933',
            label="Cost on the  BP test data")
    ax.set_xlim([test_cost_xmin, num_epochs])
    ax.grid(True)
    ax.set_xlabel('Epoch')
    ax.set_title('Cost on the test data')
    plt.legend(loc="NorthEast")
    plt.show()
def plot_overlay(test_accuracy, training_accuracy, num_epochs, xmin,
                 training_set_size, filename):
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot(np.arange(xmin, num_epochs),
            [accuracy / 100.0 for accuracy in test_accuracy],
            color='#2A6EA6',
            label="Accuracy on the test data- " + filename)
    ax.plot(np.arange(xmin, num_epochs),
            [accuracy * 100.0 / training_set_size
             for accuracy in training_accuracy],
            color='#FFA933',
            label="Accuracy on the training data- " + filename)
    ax.grid(True)
    ax.set_xlim([xmin, num_epochs])
    ax.set_xlabel('Epoch')
    ax.set_ylim([60, 100])
    plt.legend(loc="lower right")
    plt.show()
if __name__ == "__main__":
    filename = input("Enter a file name(suggest initial_new): ")
    filename_old = input("Enter a file name(suggest initial_old): ")
    num_epochs = int(input(
        "Enter the number of epochs to run for(suggest 30): "))
    training_cost_xmin = int(input(
        "training_cost_xmin (suggest 0): "))
    test_accuracy_xmin = int(input(
        "test_accuracy_xmin (suggest 0): "))
    test_cost_xmin = int(input(
        "test_cost_xmin (suggest 0): "))
    training_accuracy_xmin = int(input(
        "training_accuracy_xmin (suggest 0): "))
    training_set_size = int(input(
        "Training set size (suggest 1000): "))
    lmbda = float(input(
        "Enter the regularization parameter, lambda(regularization) (suggest: 0.0): "))
    main(filename=filename, filename_old=filename_old, num_epochs=num_epochs,
         test_accuracy_xmin=test_accuracy_xmin, lmbda=lmbda, training_set_size=training_set_size)
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
import Nerual_Network

# Third-party libraries
import matplotlib.pyplot as plt
import numpy as np

def main(filename, num_epochs,
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
    # run_network_second(filename, num_epochs, training_set_size, lmbda)
    make_plots_second(filename, num_epochs,
               test_accuracy_xmin,
               )


def run_network_second(filename, num_epochs, training_set_size=1000, lmbda=0.0):
    # Make results more easily reproducible
    random.seed(12345678)
    np.random.seed(12345678)
    training_data, validation_data, test_data = mnist_loader.load_data_wrapper()
    net_old = Nerual_Network.Network([784, 30, 10])
    net_new = Neural_Network_CrossEntropy.Network([784, 30, 10], cost=Neural_Network_CrossEntropy.CrossEntropyCost())
    net_new.large_weight_initializer()
    accuracy_old = net_old.SGD(training_data[:training_set_size], num_epochs, 10, 0.5, test_data=test_data)
    test_cost, accuracy_new, training_cost, training_accuracy \
        = net_new.SGD(training_data[:training_set_size], num_epochs, 10, 0.5,
                  evaluation_data=test_data,
                  lmbda=lmbda,
                  monitor_evaluation_cost=True,
                  monitor_evaluation_accuracy=True,
                  monitor_training_cost=True,
                  monitor_training_accuracy=True)
    f = open(filename, "w")
    json.dump([accuracy_old, accuracy_new], f)
    f.close()

def make_plots_second(filename, num_epochs,
               test_accuracy_xmin=0):
    """Load the results from ``filename``, and generate the corresponding
       plots. """
    f = open(filename, "r")
    accuracy_old, accuracy_new = json.load(f)
    f.close()
    plot_compare(accuracy_old, accuracy_new, num_epochs, test_accuracy_xmin)


def plot_compare(accuracy_old, accuracy_new, num_epochs, xmin):
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot(np.arange(xmin, num_epochs),
            [accuracy / 100.0 for accuracy in accuracy_old],
            color='#2A6EA6',
            label="Accuracy on the BP test data")
    ax.plot(np.arange(xmin, num_epochs),
            [accuracy / 100.0 for accuracy in accuracy_new],
            color='#FFA933',
            label="Accuracy on the encropy BP test data")
    ax.grid(True)
    ax.set_xlim([xmin, num_epochs])
    ax.set_xlabel('Epoch')
    ax.set_ylim([0, 100])
    plt.legend(loc="lower right")
    plt.show()

if __name__ == "__main__":
    filename = input("Enter a file name(suggest compareEncropy): ")
    num_epochs = int(input(
        "Enter the number of epochs to run for(suggest 30): "))
    test_accuracy_xmin = int(input(
        "test_accuracy_xmin (suggest 0): "))
    main(filename, num_epochs,test_accuracy_xmin)
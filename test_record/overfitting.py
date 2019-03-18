"""
encropy
~~~~~~~~~~~
Plot graphs to illustrate the problem of encropy.
"""
# Standard library
import json
import random
import tensorflow_BP_dynamicRate
import BP_tensorflow

# Third-party libraries
import matplotlib.pyplot as plt
import numpy as np

def main(filename, filename_old):
    """``filename`` is the name of the file where the results will be
       stored.  ``num_epochs`` is the number of epochs to train for.
       ``training_set_size`` is the number of images to train on.
       ``lmbda`` is the regularization parameter.  The other parameters
       set the epochs at which to start plotting on the x axis.
    """
    #训练数据进入到文件中
    tensorflow_BP_dynamicRate.tensorflow_bp_dynamic(filename)
    BP_tensorflow.tensorflow_bp(filename_old)
    make_plots(filename, filename_old=filename_old)

def make_plots(filename, num_epochs=30, filename_old=' '):
    """Load the results from ``filename``, and generate the corresponding
       plots. """
    f = open(filename, "r")
    training_accuracy, test_accuracy = json.load(f)
    f.close()
    f = open(filename_old, "r")
    training_old_accuracy, test_old_accuracy = json.load(f)
    f.close()
    plot_overlay(test_accuracy, training_accuracy, num_epochs, 0,
                  filename=filename_old)
    plot_overlay(test_old_accuracy, training_old_accuracy, num_epochs, 0,
                  filename=filename)
    plot_overlay(test_old_accuracy, test_accuracy, num_epochs, 0, filename_old + filename)

def plot_overlay(test_accuracy, training_accuracy, num_epochs, xmin, filename):
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot(np.arange(xmin, num_epochs),
            [accuracy for accuracy in test_accuracy],
            color='#2A6EA6',
            label="Accuracy on the  test data- " + filename)
    ax.plot(np.arange(xmin, num_epochs),
            [accuracy for accuracy in training_accuracy],
            color='#FFA933',
            label="Accuracy on the train data- " + filename)
    ax.grid(True)
    ax.set_xlim([xmin, num_epochs])
    ax.set_xlabel('Epoch')
    ax.set_ylim([90, 100])
    plt.legend(loc="lower right")
    plt.show()
if __name__ == "__main__":
    filename = input("Enter a file name(suggest bp_dy): ")
    filename_old = input("Enter a file name(suggest bp): ")
    main(filename=filename, filename_old=filename_old)
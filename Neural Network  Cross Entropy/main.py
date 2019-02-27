import mnist_loader
import Neural_Network_CrossEntropy
training_data, validation_data, test_data = mnist_loader.load_data_wrapper()
net = Neural_Network_CrossEntropy.Network([784, 100, 10],
                                          cost=Neural_Network_CrossEntropy.CrossEntropyCost)
net.large_weight_initializer()
# net.SGD(training_data[:1000], 400, 10, 0.5, evaluation_data=test_data,lmbda=0.5, monitor_training_cost=True,
#         monitor_evaluation_accuracy=True, monitor_training_accuracy=True, monitor_evaluation_cost=True)
net.SGD(training_data, 60, 10, 0.1, evaluation_data=test_data, lmbda=5.0, monitor_training_cost=True,
        monitor_evaluation_accuracy=True, monitor_training_accuracy=True, monitor_evaluation_cost=True )
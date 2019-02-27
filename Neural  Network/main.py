import mnist_loader
import Nerual_Network

training_data, validation_data, test_data = mnist_loader.load_data_wrapper()
net = Nerual_Network.Network([784, 100, 10])
net.SGD(training_data[:1000], 20, 10, 0.5, test_data=test_data)
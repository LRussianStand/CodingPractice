import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data
import math
import json

def tensorflow_bp(filename):
    mnist = input_data.read_data_sets('./MNIST_data/', one_hot=True)

    num_classes = 10  # 输出大小
    input_size = 784  # 输入大小
    hidden_units_size = 100  # 隐藏层节点数量
    batch_size = 100
    training_iterations = 30000
    REGULARIXZATION_RATE = 0.0001

    X = tf.placeholder(tf.float32, shape=[None, input_size])
    Y = tf.placeholder(tf.float32, shape=[None, num_classes])
    # tf.random_
    W1 = tf.Variable(tf.random_normal([input_size, hidden_units_size], stddev=1/math.sqrt(input_size)))
    B1 = tf.Variable(tf.constant(0.1), [hidden_units_size])
    W2 = tf.Variable(tf.random_normal([hidden_units_size, num_classes], stddev=1/math.sqrt(hidden_units_size)))
    B2 = tf.Variable(tf.constant(0.1), [num_classes])

    hidden_opt = tf.matmul(X, W1) + B1  # 输入层到隐藏层正向传播
    hidden_opt = tf.nn.sigmoid(hidden_opt)  # 激活函数，用于计算节点输出值
    final_opt = tf.matmul(hidden_opt, W2) + B2  # 隐藏层到输出层正向传播

    cross_entropy = tf.nn.sparse_softmax_cross_entropy_with_logits(
        logits=final_opt, labels=tf.argmax(Y, 1)
    )
    # 计算一个batch中所有样例的交叉熵平均值。
    cross_entropy_mean = tf.reduce_mean(cross_entropy)
    # 计算l2正则化损失函数
    # regularizer = tf.contrib.layers.l2_regularizer(REGULARIXZATION_RATE)
    # # 计算模型正则化损失。一般只计算神经网络边上权重的正则化损失，而不使用偏置;
    # regularization = regularizer(W1) + regularizer(W2)
    # # 总损失为交叉熵损失利正则化损失的和。
    # loss = cross_entropy_mean + regularization
    loss = cross_entropy_mean
    # 使用tf.train.GradientDescentOptimizer优化算法来优化损失函数。注意这里损失函数
    # 包含了交叉熵损失和12正则化损失。
    opt = tf.train.GradientDescentOptimizer(0.6).minimize(loss)



    # 初始化变量
    init = tf.global_variables_initializer()
    # 计算准确率
    correct_prediction =tf.equal(tf.argmax(Y, 1), tf.argmax(final_opt, 1))
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
    test_feed = {
        X: mnist.test.images,
        Y: mnist.test.labels
    }
    sess = tf.Session()
    sess.run(init)
    sum = 0
    train_accuracys = []
    test_accuracys = []
    for i in range(training_iterations):
        batch = mnist.train.next_batch(batch_size)
        batch_input = batch[0]
        batch_labels = batch[1]
        # 训练
        training_loss = sess.run([opt, loss], feed_dict={X: batch_input, Y: batch_labels})
        if i % 1000 == 0:
            # train_accuracy = accuracy.eval(session=sess, feed_dict={X: batch_input, Y: batch_labels})
            train_accuracy = sess.run(accuracy, feed_dict={X: batch_input, Y: batch_labels})
            train_accuracys.append(train_accuracy*100)
            print("step : %d, training accuracy = %g " % (i, train_accuracy))

            test_acc = sess.run(accuracy, feed_dict=test_feed)
            test_accuracys.append(test_acc*100)
            print("After %d training steps, test accuracy using average model"
                  "is %g " % (i, test_acc))
    print(filename)
    f = open(filename, 'w')
    json.dump([train_accuracys, test_accuracys], f)
    f.close()

if __name__ == '__main__':
    filename = input('Input the filename:')
    tensorflow_bp(filename)
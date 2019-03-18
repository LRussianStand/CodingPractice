import numpy as np
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['SimHei'] # 指定默认字体
plt.rcParams['axes.unicode_minus'] = False # 解决保存图像是负号'-'显示为方块的问题
X = []
Y = []
learning_rate=1
global_steps=3000
decay_steps=50
decay_rate=0.9
# 指数学习率衰减过程
for global_step in range(global_steps):
    decayed_learning_rate = learning_rate * decay_rate**(global_step / decay_steps)
    X.append(global_step / decay_steps)
    Y.append(decayed_learning_rate)
    #print("global step: %d, learning rate: %f" % (global_step,decayed_learning_rate))
plt.plot(X, Y, 'b')
plt.ylabel(u"learning_rate学习率")
plt.xlabel('global_step / decay_steps')
plt.show()

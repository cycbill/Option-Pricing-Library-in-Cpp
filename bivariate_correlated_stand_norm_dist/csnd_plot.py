import numpy as np
import matplotlib.pyplot as plt

z1, z2 = np.loadtxt('csnd.csv', unpack=True)

var_num = len(z1)
nums = np.arange(1, var_num+1, 1)

fig = plt.figure()
ax = fig.add_subplot(111)
ax.plot(nums, z1, label='z1')
ax.plot(nums, z2, label='z2')
plt.xticks(nums, nums)
ax.legend(loc='upper right')
plt.show()


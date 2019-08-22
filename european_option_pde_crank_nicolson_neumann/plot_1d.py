import matplotlib.pyplot as plt
import numpy as np

x, y, z = np.loadtxt('fdm.csv', unpack=True)

N = int(np.sqrt(len(x)))

X = np.reshape(x, (20,20))
Y = np.reshape(y, (20,20))
Z = np.reshape(z, (20,20))

spot = np.transpose(Y[:,0])

for i, row in enumerate(Z):
    #z0 = Z[-1,:]
    plt.plot(spot, row, '-')
plt.show()
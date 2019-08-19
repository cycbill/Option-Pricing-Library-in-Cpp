import matplotlib.pyplot as plt
import numpy as np

x, y, z = np.loadtxt('fdm.csv', unpack=True)

N = int(np.sqrt(len(x)))
print(len(x), N)

X = np.reshape(x, (20,20))
Y = np.reshape(y, (20,20))
Z = np.reshape(z, (20,20))


y0 = np.transpose(Y[:,0])
z0 = Z[-0,:]

print(y0)
print(z0)


plt.plot(y0, z0)
plt.show()
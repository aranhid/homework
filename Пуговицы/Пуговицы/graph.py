import matplotlib.pyplot as plt
import numpy as np


xs = []
ys = []

ax = plt.axes()

with open('superout.txt', 'rb') as f:
    n = int(f.readline())
    lines = f.readlines()
    print(n, len(lines))
    for i in range(1, n):
        x, y = map(int, lines[i].split())
        xs.append(x)
        ys.append(y)

x = np.array(xs)
y = np.array(ys)
ax.plot(x, y, color="red")

plt.show()
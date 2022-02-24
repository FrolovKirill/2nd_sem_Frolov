import matplotlib.pyplot as plt

n = 90
y_data = [1253, 643, 474, 370, 280, 245, 214, 178, 159, 135, 145, 114, 95, 90, 78, 79, 64, 63, 56, 59, 52, 53, 47, 39, 40, 45, 38, 33, 32, 26, 28, 26, 27, 25, 22, 23, 21, 22, 22, 18, 17, 16, 17, 16, 14, 13, 13, 13, 13, 12, 12, 12, 11, 10, 9, 11, 9, 10, 9, 8, 8, 7, 8, 8, 6, 6, 6, 6, 6, 6, 6, 5, 5, 6, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 4, 3, 3, 3, 2]
x_data = [1 + i for i in range(n)]

plt.figure()
plt.errorbar(x_data, y_data, fmt='.', color='red', linewidth=0.7)

plt.legend()

plt.grid(True)
plt.show()

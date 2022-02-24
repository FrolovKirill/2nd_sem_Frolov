import matplotlib.pyplot as plt
import numpy as np

n = 290
y_data = [15, 19, 24, 29, 34, 39, 47, 53, 63, 70, 77, 89, 100, 107, 121, 133, 143, 159, 166, 185, 203, 207, 218, 241, 248, 276, 295, 308, 323, 344, 363, 383, 402, 422, 446, 450, 485, 508, 530, 547, 569, 602, 635, 651, 685, 713, 736, 750, 772, 811, 837, 880, 890, 938, 921, 1013, 1036, 1035, 1088, 1081, 1174, 1195, 1228, 1204, 1336, 1373, 1338, 1406, 1442, 1476, 1486, 1545, 1655, 1591, 1703, 1733, 1782, 1809, 1804, 1902, 1929, 1987, 2051, 2043, 2105, 2142, 2234, 2195, 2366, 2420, 2446, 2436, 2509, 2554, 2625, 2574, 2712, 2748, 2761, 2897, 3017, 2951, 3126, 3077, 3166, 3225, 3363, 3398, 3314, 3338, 3468, 3574, 3662, 3758, 3679, 3781, 3976, 4037, 3879, 3958, 4107, 4248, 4283, 4271, 4233, 4421, 4675, 4608, 4671, 4821, 4639, 4773, 4816, 4782, 5056, 5044, 5217, 5241, 5349, 5370, 5401, 5413, 5707, 5713, 5791, 5755, 5948, 5910, 5987, 6186, 6157, 6633, 6470, 6571, 6830, 6666, 6984, 6697, 7012, 7002, 7041, 6957, 7340, 7160, 7433, 7520, 7553, 7715, 7888, 7651, 7516, 7927, 8351, 8074, 7874, 8244, 8508, 8553, 8597, 8862, 8760, 8734, 9049, 9066, 8906, 9215, 9473, 9562, 9676, 9594, 9776, 9577, 10081, 9832, 10324, 10502, 10286, 10478, 10764, 11236, 10984, 11189, 10711, 11136, 11259, 11110, 11203, 11057, 11240, 11317, 12323, 12051, 12087, 12296, 12052, 12618, 12131, 12839, 12588, 13099, 13342, 13155, 13164, 13027, 13279, 13634, 13460, 14119, 13987, 14277, 13973, 13919, 14665, 14798, 14588, 14390, 14814, 15036, 14817, 15591, 15373, 15492, 15280, 15877, 16630, 16396, 16067, 16381, 16507, 16715, 16776, 16931, 16518, 16955, 17072, 17845, 17263, 17434, 17377, 17865, 17992, 18408, 18623, 18015, 18122, 18448, 19176, 18728, 18292, 19336, 20234, 19914, 19439, 19133, 19640, 20354, 20005, 20678, 21368, 21102, 21053, 20374, 20866, 22092, 20709, 20742, 21641, 21873, 21662, 22068]
x_data = [10 + i for i in range(n)]

x_data = np.log(x_data)
y_data = np.log(y_data)

sumxy = sumx = sumy = sumxx = 0

for i in range(n):
    sumxy += x_data[i] * y_data[i]
    sumx += x_data[i]
    sumy += y_data[i]
    sumxx += x_data[i] ** 2

k = (sumxy / n - (sumx / n) * (sumy / n)) / (sumxx / n - (sumx / n) ** 2)
b = (sumy / n) - k * (sumx / n)

x1 = np.arange(2, 5.75, 0.01)

plt.figure()
plt.errorbar(x_data, y_data, fmt='.', color='red', linewidth=0.7)
plt.plot(x1, k * x1 + b, label=r'$y = 2.08 x - 1.81$', linewidth=1.2)

plt.legend()

plt.grid(True)
plt.show()

print(k, b)
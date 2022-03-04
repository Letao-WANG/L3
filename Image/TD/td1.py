import matplotlib.pyplot as plt
import matplotlib.image as mplimg
import numpy as np

# exo1
# img = mpimg.imread('../../test_images/doc1.jpg')
# fig = plt.figure()
# plt.imshow(img)
# plt.show()

# size = img.shape

# rows = size[0]
# cols = size[1]
# print(img[int(rows/4)][int(cols*3/4)])

# exo2
# array = np.zeros((128, 128, 3), dtype=int)
# for i in range(64, 72):
#     array[20][i] = 255
#     array[30][i] = 255
# for j in range(20, 31):
#     array[j][64] = 255
#     array[j][71] = 255
# plt.figure()
# plt.imshow(array)
# plt.show()

# exo3
# array = np.zeros((128, 128, 3), dtype=int)
# color = 0
# for i in range(len(array[0])):
#     array[i] = color
#     color = color + 2
#
# plt.imshow(array)
# plt.show()

# exo 4
# array = np.zeros((128, 128, 3), dtype=int)
# color = 0
# for i in range(len(array[0])):
#     for j in range(len(array[1])):
#         if i == j or i == 128-j:
#             array[i][j] = 255
#
# plt.imshow(array)
# plt.show()

# exo 5
array = np.zeros((128, 128, 3), dtype=int)
color = 0
for i in range(len(array[0])):
    for j in range(len(array[1])):
        if (j-50)**2 + (i-50)**2 == 200 or (j-50)**2 + (i-50)**2 == 201:
            array[i][j] = 255

plt.imshow(array)
plt.show()

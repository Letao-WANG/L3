import matplotlib.pyplot as plt
import matplotlib.image as mplimg
import numpy as np


# EXO 1
# img = (mplimg.imread('test_images/test.png').copy() * 255).astype(np.uint8)


# plt.figure()
# plt.imshow(img, cmap=plt.cm.gray)
# plt.show()

# seuil = 145
# def func_seuill(seuil, origin_image):
#     res = np.zeros(origin_image.shape)
#     num_aire = 0
#     for i in range(img.shape[0]):
#         for j in range(img.shape[1]):
#             if img[i, j] >= seuil:
#                 res[i, j] = 1
#                 num_aire += 1
#     return res, num_aire

#
# im, aire = func_seuill(seuil, img)
#
# print(f"pour seuil = {seuil}, aire = {aire} pixels (soit {aire / (img.shape[0] * img.shape[1]) * 100}  % de l'image")
# plt.figure()
# plt.imshow(im, cmap=plt.cm.gray)
# plt.show()


# Exo2
img = (mplimg.imread('test_images/landscape.png').copy() * 255).astype(np.uint8)


plt.figure()
plt.imshow(img, cmap=plt.cm.gray, vmin=0, vmax=255)
plt.show()

histogramme = [0]*256
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        histogramme[img[i, j]] += 1

for i, val in enumerate(histogramme):
    print(f"{i}: {val}")


def func_mul_seuill(s1, s2, origin_image):
    res = np.zeros([origin_image.shape[0], origin_image.shape[1], 3], dtype=np.uint8)
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            if img[i, j] >= s2:
                res[i, j] = 255
            elif s1 <= img[i, j] < s2:
                res[i, j] = 120
            elif img[i, j] <= s1:
                res[i, j] = 0
    return res


im = func_mul_seuill(110, 150, img)
plt.figure()
plt.imshow(im, cmap=plt.cm.gray)
plt.show()

img_out = np.zeros([img.shape[0], img.shape[1], 3], dtype=np.uint8)
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        if img[i, j] <= 80:
            img_out[i, j, 1] = 255
        else:
            img_out[i, j] = im[i, j]


plt.figure()
plt.imshow(img_out)
plt.show()


# Exo3

# def draw_square(row, col, origin_img):
#     for i in range(112):
#         for j in range(112):
#             origin_img[i, j] = 92
#     return origin_img
#
#
# img = np.zeros((630, 1345))
# index_row = 112
# index_col = 56
# for i in range(img.shape[0]):
#     for j in range(img.shape[1]):
#         img = draw_square(index_row, index_col)
#         index_row += 224
#         index_col += 224
#
# plt.figure()
# plt.imshow(img, cmap=plt.cm.gray)
# plt.show()

import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np

# Exo 1
# img = np.array([[12, 10, 8, 13, 25, 50, 46],
#                 [8, 7, 8, 10, 20, 23, 31],
#                 [11, 9, 10, 14, 28, 30, 37],
#                 [14, 11, 10, 26, 31, 28, 32],
#                 [12, 9, 11, 31, 35, 33, 41],
#                 [7, 12, 33, 35, 41, 50, 70],
#                 [13, 10, 35, 38, 75, 73, 72],
#                 [9, 14, 41, 45, 71, 76, 75]])
# #
# max_val = 100
# plt.imshow(image, cmap=plt.cm.gray, vmin=0, vmax=max_val)
# plt.title(f"image original")
# plt.show()


# amplitude 10
# max_val = 100
# list_histogram = []
# for i in range(10):
#     list_histogram.append(0)
#
# for i in range(img.shape[0]):
#     for j in range(img.shape[1]):
#         dec = img[i, j] % 10
#         list_histogram[dec] += 1
#
# print(list_histogram)

# amplitude = 1
# histogram = [0] * 100
# for i in range(img.shape[0]):
#     for j in range(img.shape[1]):
#         histogram[img[i, j]] += 1
#
# histogram_cumule = [0] * 100
# histogram_cumule[0] = histogram[0]
# for i in range(1, 100):
#     histogram_cumule[i] = histogram[i] + histogram_cumule[i - 1]

# print(histogram_cumule)

# Egalisation
# img_egalisation = np.zeros(img.shape, dtype=np.uint8)
# n = 100
# # N = histogram_cumule[len(histogram_cumule)-1]
# N = img.shape[0] * img.shape[1]
# for i in range(img.shape[0]):
#     for j in range(img.shape[1]):
#         c = histogram_cumule[img[i, j]]
#         img_egalisation[i, j] = max(0, (n/N) * c - 1)
#
# # plt.imshow(img, cmap=plt.cm.gray, vmin=0, vmax=max_val)
# # plt.show()
# plt.imshow(img_egalisation, cmap=plt.cm.gray, vmin=0, vmax=max_val)
# plt.show()

# Exo 3
# image = mpimg.imread('test_images/lena.jpeg')
#
# size = image.shape
# print(size)
# img_gris = np.zeros([size[0], size[1]], dtype=np.uint8)
# for i in range(size[0]):
#     for j in range(size[1]):
#         img_gris[i, j] = (image[i, j, 0] * 1.0 + image[i, j, 1]*1.0 + image[i, j, 2]*1.0)/3
#
# plt.figure()
# plt.imshow(image, cmap=plt.cm.gray, vmin=0, vmax=max_val)
# plt.imshow(img_gris, cmap=plt.cm.gray, vmin=0, vmax=255)
# plt.show()

# img_inverse = np.zeros(image.shape, dtype=np.uint8)
# for i in range(size[0]):
#     for j in range(size[1]):
#         img_inverse[i, j, 0] = 255 - img_inverse[i, j, 0]
#         img_inverse[i, j, 1] = 255 - img_inverse[i, j, 1]
#         img_inverse[i, j, 2] = 255 - img_inverse[i, j, 2]
#
# plt.figure()
# plt.imshow(img_inverse, cmap=plt.cm.gray, vmin=0, vmax=255)
# plt.show()
#
#
# def num_round(number, list_round: list[int]):
#     min_cost = 255
#     index = 0
#     for i in list_round:
#         if abs(number - i) < min_cost:
#             min_cost = abs(number - i)
#             index = i
#     return list_round[index]
#
#
# def en_niveau(img, niveau):
#     gap = 255/niveau
#     list_round = []
#     for i in range(niveau):
#         list_round.append(gap*i)
#
#     size = image.shape
#     img_gris = np.zeros([size[0], size[1]])
#     for i in range(size[0]):
#         for j in range(size[1]):
#             img_gris[i, j] = num_round(img[i, j], list_round)
#     return img_gris


# img_new = en_niveau(image, 10)
# plt.imshow(img_gris, cmap=plt.cm.gray, vmin=0, vmax=255)
# plt.show()


# ------------------- Exo2 ----------------------

img = (mpimg.imread('test_images/landscape.png').copy() * 255).astype(np.uint8)
max_val = 255
amplitude = 1
histogram = [0] * 255
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        histogram[int(img[i, j])] += 1

print(histogram)

histogram_cumule = [0] * 255
histogram_cumule[0] = histogram[0]
for i in range(1, 255):
    histogram_cumule[i] = histogram[i] + histogram_cumule[i - 1]

print(histogram_cumule)

# Egalisation

img_egalisation = np.zeros(img.shape, dtype=np.uint8)
n = 255
# N = histogram_cumule[len(histogram_cumule)-1]
N = img.shape[0] * img.shape[1]
for i in range(img.shape[0]):
    for j in range(img.shape[1]):
        c = histogram_cumule[img[i, j]]
        img_egalisation[i, j] = max(0, (n / N) * c - 1)


# plt.imshow(img, cmap=plt.cm.gray, vmin=0, vmax=max_val)
# plt.show()
# plt.imshow(img_egalisation, cmap=plt.cm.gray, vmin=0, vmax=max_val)
# plt.show()



def otsu(gray):
    pixel_number = gray.shape[0] * gray.shape[1]
    mean_weight = 1.0/pixel_number
    his, bins = np.histogram(gray, np.arange(0,257))
    final_thresh = -1
    final_value = -1
    intensity_arr = np.arange(256)
    for t in bins[1:-1]: # This goes from 1 to 254 uint8 range (Pretty sure wont be those values)
        pcb = np.sum(his[:t])
        pcf = np.sum(his[t:])
        Wb = pcb * mean_weight
        Wf = pcf * mean_weight

        mub = np.sum(intensity_arr[:t]*his[:t]) / float(pcb)
        muf = np.sum(intensity_arr[t:]*his[t:]) / float(pcf)
        #print mub, muf
        value = Wb * Wf * (mub - muf) ** 2

        if value > final_value:
            final_thresh = t
            final_value = value
    final_img = gray.copy()
    print(final_thresh)
    final_img[gray > final_thresh] = 255
    final_img[gray < final_thresh] = 0
    return final_img


final_image = otsu(img_egalisation)
plt.imshow(final_image, cmap=plt.cm.gray, vmin=0, vmax=max_val)
plt.show()


# ------------- OTSU
meilleur_seuil = 0
minimum = 10000000

for seuil in range(256):
    w1 = 0
    w2 = 0
    mu1 = 0
    mu2 = 0
    for i in range(0, seuil):
        w1 += histogram[i]
        mu1 += i + histogram[i]
    for i in range(seuil, 256):
        w2 += histogram[i]
        mu2 += i + histogram[i]

        if w1 == 0 or w2 == 0:
            continue

    mu1 /= w1
    mu2 /= w2
    w1 /= (img.shape[0] * img.shape[1])
    w2 /= (img.shape[0] * img.shape[1])

    #variance
    s1 = 0
    s2 = 0
    for i in range(0, seuil):
        s1 += (i)

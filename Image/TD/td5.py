import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np


def load_jpg(source):
    image = mpimg.imread(source)
    size = image.shape
    img_gris = np.zeros([size[0], size[1]], dtype=np.uint8)
    for i in range(size[0]):
        for j in range(size[1]):
            img_gris[i, j] = (image[i, j, 0] * 1.0 + image[i, j, 1] * 1.0 + image[i, j, 2] * 1.0) / 3
    return img_gris


img_gris = load_jpg('test_images/doc1.jpg')

max_val = 100


def get_histo_projection(img_gris):
    for i in range(img_gris.shape[0]):
        for j in range(img_gris.shape[1]):
            if img_gris[i, j] > 150:
                img_gris[i, j] = 100
            else:
                img_gris[i, j] = 0

    histo_projection = [0] * img_gris.shape[0]
    for i in range(img_gris.shape[0]):
        for j in range(img_gris.shape[1]):
            if img_gris[i, j] == 0:
                histo_projection[i] += 1
    return histo_projection


# histo_projection = get_histo_projection(img_gris)
# plt.figure()
# plt.barh(np.arange(img_gris.shape[0]), histo_projection[::-1])
# plt.show()
# print(histo_projection)


# Question 2
# 1:16, 2:36, 3:26, 4:16

def get_number_row(source):
    img = load_jpg(source)
    histo_projection = get_histo_projection(img)
    number_rows = 0
    count = 1
    while count < len(histo_projection) - 1:
        limit = 25
        if histo_projection[count] > limit and histo_projection[count - 1] > limit and histo_projection[count + 1] > limit:
            count += 20
            number_rows += 1
        count += 1
    return number_rows


numbers = []
for i in range(1, 5):
    numbers.append(get_number_row("test_images/doc" + str(i) + ".jpg"))

# print(numbers)

# Question 3

# 4 1
# 3 2


def get_paires_image(nombre_lignes_par_doc):
    paires = []
    for image_num in range(4):
        stop = False
        for paire in paires:
            if image_num == paire[0] or image_num == paire[1]:
                stop = True
        if stop:
            continue
        nombre_lignes = nombre_lignes_par_doc[image_num]
        min_diff = 100000
        meilleure_paire = -1
        for image_num2 in range(4):
            if image_num2 != image_num:
                diff = abs(nombre_lignes_par_doc[image_num2] - nombre_lignes)
                if diff < min_diff:
                    min_diff = diff
                    meilleure_paire = image_num2

        paires.append((image_num, meilleure_paire))
    return paires


def load_original_jpg(source):
    image = mpimg.imread(source)
    return image


docs = []
docs_gris = []
for i in range(1, 5):
    docs.append(load_original_jpg(("test_images/doc" + str(i) + ".jpg")))
    docs_gris.append(load_jpg(("test_images/doc" + str(i) + ".jpg")))

res = get_paires_image(numbers)

paire1 = res[0][0]
paire2 = res[0][1]

count_left, count_right = 0, 0
for j in range(200):
    if docs_gris[paire1][0+j][0] == 0:
        count_left += 1
    if docs_gris[paire2][0+j][0] == 0:
        count_right += 1

if count_left > count_right:
    tmp = paire1
    paire1 = paire2
    paire2 = tmp


h1 = docs[paire2].shape[0]
w1 = docs[paire2].shape[1] + docs[paire1].shape[1]
new_image = [[0 for x in range(w1)] for y in range(h1)]

for i in range(h1):
    for j in range(w1):
        if j < docs[paire2].shape[1]:
            new_image[i][j] = docs[paire2][i][j]
        else:
            new_image[i][j] = docs[paire1][i][j-250]

plt.figure()
plt.imshow(new_image, cmap=plt.cm.gray)
plt.show()

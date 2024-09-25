from PIL import Image
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np


def load_jpg(source):
    """
    For jpg to binary
    :param source:
    :return: gris
    """
    image = (mpimg.imread(source) * 255).astype(np.uint8)
    size = image.shape
    img_gris = np.zeros([size[0], size[1]], dtype=bool)
    for i in range(size[0]):
        for j in range(size[1]):
            if (image[i, j, 0] * 1.0 + image[i, j, 1] * 1.0 + image[i, j, 2] * 1.0) / 3 > 2:
                img_gris[i, j] = 1
    return img_gris


def structuring_element():
    radius = 11
    circle = np.zeros([radius, radius])
    center = (circle.shape[0] // 2, circle.shape[1] // 2)
    for i in range(circle.shape[0]):
        for j in range(circle.shape[1]):
            if np.sqrt((center[0]-i)**2 + (center[1] - j) ** 2) <= center[0]:
                circle[i, j] = 1
    return circle


def erosion_verify_element(content, element):
    for i in range(content.shape[0]):
        for j in range(content.shape[1]):
            if element[i, j] == 1:
                if not content[i, j] == 1:
                    return False
    return True


def dilation_verify_element(content, element):
    for i in range(content.shape[0]):
        for j in range(content.shape[1]):
            if element[i, j] == 1:
                if content[i, j] == 1:
                    return True
    return False


def erosion(image, element):
    size = image.shape
    size_element = element.shape
    img = np.zeros([size[0], size[1]], dtype=bool)
    for i in range(size_element[0], size[0]-size_element[0]):
        for j in range(size_element[1], size[1]-size_element[1]):
            content = image[i:i+size_element[0], j:j+size_element[1]]
            is_verify = erosion_verify_element(content, element)
            if is_verify:
                img[i+size_element[0]//2, j+size_element[1]//2] = 1
    return img


def dilation(image, element):
    size = image.shape
    size_element = element.shape
    img = np.zeros([size[0], size[1]], dtype=bool)
    for i in range(size_element[0], size[0]-size_element[0]):
        for j in range(size_element[1], size[1]-size_element[1]):
            content = image[i:i+size_element[0], j:j+size_element[1]]
            is_verify = dilation_verify_element(content, element)
            if is_verify:
                img[i+size_element[0]//2, j+size_element[1]//2] = 1
    return img


def opening(image, element):
    image_erosion = erosion(image, element)
    image_opening = dilation(image_erosion, element)
    return image_opening


def closing(image, element):
    image_dilatation = dilation(image, element)
    image_closing = erosion(image_dilatation, element)
    return image_closing


def main():
    image_gris = load_jpg('test_images/shapes2.png')
    plt.figure()
    plt.imshow(image_gris, cmap=plt.cm.gray)

    image_circle = structuring_element()
    # plt.figure()
    # plt.imshow(image_circle, cmap=plt.cm.gray)

    img = closing(image_gris, image_circle)
    plt.figure()
    plt.imshow(img, cmap=plt.cm.gray)

    img = opening(image_gris, image_circle)
    plt.figure()
    plt.imshow(img, cmap=plt.cm.gray)

    plt.show()


main()

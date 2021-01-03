
# CONVOLUTION OPERATION
# This program takes input a png image and a filter (box,gaussian,sharpen,edge)
# It applies the filter to the image and displays the output.

from PIL import Image, ImageDraw
import numpy as np
from matplotlib import pyplot as plt
import imageio


def get_image(image_path):
    im = imageio.imread(img_path)
    return im

def plotter(img):
    plt.imshow(img)
    plt.show()


def box_blur(img_path):
    # this applies box blur to an image
    # Load image:
    input_image = Image.open(img_path)
    input_pixels = input_image.load()

    # Box Blur kernel
    box_kernel = [[1 / 9, 1 / 9, 1 / 9],
                  [1 / 9, 1 / 9, 1 / 9],
                  [1 / 9, 1 / 9, 1 / 9]]


    kernel = box_kernel
    offset = len(kernel) // 2

    # Create output image
    output_image = Image.new("RGB", input_image.size)
    draw = ImageDraw.Draw(output_image)

    # Compute convolution between intensity and kernels
    for x in range(offset, input_image.width - offset):
        for y in range(offset, input_image.height - offset):
            acc = [0, 0, 0]
            for a in range(len(kernel)):
                for b in range(len(kernel)):
                    xn = x + a - offset
                    yn = y + b - offset
                    pixel = input_pixels[xn, yn]
                    acc[0] += pixel[0] * kernel[a][b]
                    acc[1] += pixel[1] * kernel[a][b]
                    acc[2] += pixel[2] * kernel[a][b]

            draw.point((x, y), (int(acc[0]), int(acc[1]), int(acc[2])))

    output_image.save("output.png")
    return output_image

def gaussian_blur(img_path):
    # this applies gaussain blur to an image

    # Load image:
    input_image = Image.open(img_path)
    input_pixels = input_image.load()

    # Gaussian kernel
    gaussian_kernel = [[1 / 256, 4 / 256, 6 / 256, 4 / 256, 1 / 256],
                       [4 / 256, 16 / 256, 24 / 256, 16 / 256, 4 / 256],
                       [6 / 256, 24 / 256, 36 / 256, 24 / 256, 6 / 256],
                       [4 / 256, 16 / 256, 24 / 256, 16 / 256, 4 / 256],
                       [1 / 256, 4 / 256, 6 / 256, 4 / 256, 1 / 256]]

    kernel = gaussian_kernel
    offset = len(kernel) // 2

    # Create output image
    output_image = Image.new("RGB", input_image.size)
    draw = ImageDraw.Draw(output_image)

    # Compute convolution between intensity and kernels
    for x in range(offset, input_image.width - offset):
        for y in range(offset, input_image.height - offset):
            acc = [0, 0, 0]
            for a in range(len(kernel)):
                for b in range(len(kernel)):
                    xn = x + a - offset
                    yn = y + b - offset
                    pixel = input_pixels[xn, yn]
                    acc[0] += pixel[0] * kernel[a][b]
                    acc[1] += pixel[1] * kernel[a][b]
                    acc[2] += pixel[2] * kernel[a][b]

            draw.point((x, y), (int(acc[0]), int(acc[1]), int(acc[2])))

    output_image.save("output.png")
    return output_image


def sharpen(img_path):
    # this applies the sharpen filter to an image

    # Load image:
    input_image = Image.open(img_path)
    input_pixels = input_image.load()

    # sharpening Kernel
    sharpen_kernel = [[0, -.5, 0],
                      [-.5, 3, -.5],
                      [0, -.5, 0]]

    kernel = sharpen_kernel
    offset = len(kernel) // 2

    # Create output image
    output_image = Image.new("RGB", input_image.size)
    draw = ImageDraw.Draw(output_image)

    # Compute convolution between intensity and kernels
    for x in range(offset, input_image.width - offset):
        for y in range(offset, input_image.height - offset):
            acc = [0, 0, 0]
            for a in range(len(kernel)):
                for b in range(len(kernel)):
                    xn = x + a - offset
                    yn = y + b - offset
                    pixel = input_pixels[xn, yn]
                    acc[0] += pixel[0] * kernel[a][b]
                    acc[1] += pixel[1] * kernel[a][b]
                    acc[2] += pixel[2] * kernel[a][b]

            draw.point((x, y), (int(acc[0]), int(acc[1]), int(acc[2])))

    output_image.save("output.png")
    return output_image


def edge_detect(img_path):
    # This applies the edge detection filter to an image

    # Load image:
    input_image = Image.open(img_path)
    input_pixels = input_image.load()

    # Calculate pixel intensity as the average of red, green and blue colors.
    intensity = [[sum(input_pixels[x, y]) / 3 for y in range(input_image.height)] for x in range(input_image.width)]

    # edge kernels

    # kernel for horizontal edges
    kernelx = [[-1, 0, 1],
               [-2, 0, 2],
               [-1, 0, 1]]
    # kernel for vertical edges
    kernely = [[-1, -2, -1],
               [0, 0, 0],
               [1, 2, 1]]

    # Create output image
    output_image = Image.new("RGB", input_image.size)
    draw = ImageDraw.Draw(output_image)

    # Compute convolution between intensity and kernels
    for x in range(1, input_image.width - 1):
        for y in range(1, input_image.height - 1):
            magx, magy = 0, 0
            for a in range(3):
                for b in range(3):
                    xn = x + a - 1
                    yn = y + b - 1
                    magx += intensity[xn][yn] * kernelx[a][b]
                    magy += intensity[xn][yn] * kernely[a][b]

            # Draw in black and white the magnitude
            #color = int(sqrt(magx ** 2 + magy ** 2))
            color = int((magx ** 2 + magy ** 2) ** 0.5)
            draw.point((x, y), (color, color, color))

    output_image.save("output.png")
    return output_image


def apply_filter(img_path , blur_type):

    # Load image:
    input_image = Image.open(img_path)
    input_pixels = input_image.load()

    # Select kernel here:
    if(blur_type == 'box'):
        output = box_blur(img_path)
        return output
    elif(blur_type == 'gaussian'):
        output = gaussian_blur(img_path)
        return output
    elif(blur_type == 'sharpen'):
        output = sharpen(img_path)
        return output
    elif(blur_type == 'edge'):
        output = edge_detect(img_path)
        return output
    else:
        print("please select one of the kernels <box,gaussian> ")


if __name__ == '__main__':

    # give the absolute path of the png image to the variable img_path
    img_path = 'C:\\Users\\Exile\\Desktop\\Sem2\\DL\\Assignment\\car.png'

    x = get_image(img_path)
    print(x.shape, "x shape")
    plotter(x)

    # mention the type of filter you want to apply on image
    # it can be 'box' , 'gaussian', 'sharpen', or 'edge'
    ba = apply_filter(img_path,'box')
    plotter(ba)







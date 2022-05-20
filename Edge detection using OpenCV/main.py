import cv2

#there is another image type flowerinrain.jpeg instead of the adele one
image = cv2.imread('adeleillusion.jpg')
proimage = cv2.Canny(image,100,200)

cv2.imshow('image',proimage)
cv2.waitKey(0)


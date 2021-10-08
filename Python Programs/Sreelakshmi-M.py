#archery board

#Run pip install opencv-python 
import cv2
import numpy as np

img=np.zeros((512,512,3),np.uint8)*255
img[:]=(0,255,255)
text="OpenCV"

cv2.putText(img,text,(10,250),cv2.FONT_HERSHEY_SIMPLEX,2,(0,0,0),5)
cv2.imshow("text",img)

cv2.waitkey(0)
cv2.destroyWindow("text")
cv2.imwrite("text.jpg",img)

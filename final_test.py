import argparse
import datetime
import imutils
import time
import cv2

# cnt to refresh frame reference
cnt = 0
# capture video from webcam
camera = cv2.VideoCapture(0)
time.sleep(0.25)
firstFrame = None

while True:
    cnt += 1
    # grab a frame from camera
    (grabbed, frame) = camera.read()

    # resizing and grayscaling
    frame = imutils.resize(frame, width=500)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    gray = cv2.GaussianBlur(gray, (21, 21), 0)

    # change reference frame(firstFrame) each 20 frames
    if firstFrame is None or cnt is 20:
        cnt = 0
        firstFrame = gray
        continue

    # frameDelta which will detect changes in the current frame with reference to firstFrame
    frameDelta = cv2.absdiff(firstFrame, gray)
    # Here we use THRESH_BINARY
    # http://docs.opencv.org/3.2.0/d7/d4d/tutorial_py_thresholding.html
    thresh = cv2.threshold(frameDelta, 25, 255, cv2.THRESH_BINARY)[1]

    # show the frame and record if the user presses a key
    cv2.imshow("WebCam Preview", frame)
    cv2.imshow("Thresholded Output", thresh)
    cv2.imshow("Difference in motion with reference to Referenced Frame", frameDelta)
    key = cv2.waitKey(1) & 0xFF
 
    # to stop the loop and terminate the program
    if key == ord("q"):
        break
 
# cleanup the camera and close any open windows
camera.release()
cv2.destroyAllWindows()

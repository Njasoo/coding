import cv2


def faceDetectPic(image):
    gray_image = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
    # cv2.imshow("img", gray_image)
    # 训练一组人脸
    faceDetector = cv2.CascadeClassifier(
        "C:/Users/Njaso/AppData/Local/Programs/Python/Python310/Lib/site-packages/cv2/data/haarcascade_frontalface_alt.xml")
    face_rect = faceDetector.detectMultiScale(
        gray_image, 1.1, 3)  # （图片，每次搜索之后扩大的倍数，至少检测到的次数）
    print("人脸矩阵坐标: ", face_rect)
    dst = image.copy()
    for x, y, w, h in face_rect:
        cv2.rectangle(dst, (x, y), (x + w, y + h), (0, 255, 0), 3)  # 画出矩形框
        # 分别是左上角的点和右下角的点，最后的3是字体粗细
    cv2.imshow("dst", dst)
    return dst


def faceDetectCam():
    capture = cv2.VideoCapture(0)  # 0：本地摄像头，1：外接摄像头
    while True:
        ret, frame = capture.read()  # frame为每一帧的影像
        frame = cv2.flip(frame, 1)  # 1左右翻转，0垂直翻转，-1水平垂直翻转
        result = faceDetectPic(frame)
        # waitkey返回按下的key的值，范围【0,255】，&上0XFF是为了不超出范围
        if cv2.waitKey(1) & 0XFF == ord("q"):
            break


if __name__ == '__main__':
    src = "photos/face.jpg"
    # img = cv2.imread(src)
    # faceDetectPic(img)
    faceDetectCam()
    cv2.waitKey()  # 照片imshow()的时候会闪退，加上这句就好了

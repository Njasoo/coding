import numpy as np
from sklearn import datasets
# from sklearn.cross_validation import train_test_split 找不到sklearn.cross_validation
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier  # 聚类算法吗

iris = datasets.load_iris()  # 花的数据？
iris_X = iris.data  # 花的属性
iris_y = iris.target  # 分类

print(iris_X)
print(iris_y)

print(iris_X[:2])
print(iris_y)

X_train, X_test, y_train, y_test = train_test_split(iris_X, iris_y, test_size=0.3)

print(y_train)  # 数据是打乱的

print(X_train.shape)
print(X_test.shape)
print(y_train.shape)
print(y_test.shape)

knn = KNeighborsClassifier()
knn.fit(X_train, y_train)  # 放入训练数据
# knn.fit(X_train)
print(knn.predict(X_test))  # 预测的值
print(y_test)

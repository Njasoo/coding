class Point:
    def __init__(self,x,y,z,h):
        self.x = x
        self.y = y
        self.z = z
        self.h = h
    def getPoint(self):
        return self.x,self.y,self.z,self.h
class Line(Point):
    # 请在下面填入覆盖父类getPoint()方法的代码，并在这个方法中分别得出x - y与z - h结果的绝对值
    ########## Begin ##########
    def getPoint(self):
        return abs(x-y),abs(z-h);

x=int(input())
print(x)
temp=input()
y=int(input())
print(y)
temp=input()
z=int(input())
print(z)
temp=input()
h=int(input())
obj=Line(x,y,z,h)
res=obj.getPoint()
length_one=res[0]
length_two=res[1]

    ########## End ##########
print(length_one,length_two)
    

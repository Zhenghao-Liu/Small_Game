import os
import random
from sys import exit

def clear():
    os.system('cls')
    #清屏函数

def pause():
    os.system('pause')
    #暂停函数

def shuchu(num):
	#输出游戏界面函数
    for i in range(0,4):
        for j in range(0,4):
            if num[i][j]==0:
                print("    _",end='')
            else:
                print("%5d" % num[i][j],end='')
        print()

def suijiweizhi(num):
    #生成随机数
    panduan=0
    for i in range(0,4):
        for j in range(0,4):
            if num[i][j]==0:
                panduan=1
    if panduan!=1:
        #代表全是数字没有新地方生成数字
        print(".........................")
        print("       game over")
        max=0
        for i in range(0,4):
            for j in range(0,4):
                if	max < num[i][j]:
                    max=num[i][j]
        print(f"the Biggest number is {max}")
        print("     congratulation")
        pause()
        exit(0)
    else:
        #有地方 随机生成2或者4
        panduan2=0
        while panduan2==0:
            i=random.randint(0,3)
            j=random.randint(0,3)
            k=random.randint(1,2)
            if num[i][j]==0:
                num[i][j]=k*2
                panduan2=1

#in + wasd代表键入后的程序操作函数
def inw(num):
	for a in range(0,4):
		for j in range(0,4):
			for i in range(0,4):
				if num[i][j]==0:
					if i==3:
						continue
					else:
						num[i][j]=num[i+1][j]
						num[i+1][j]=0

	for j in range(0,4):
		a=0
		for i in range(0,3):
			if num[i][j]!=num[i+1][j]:
				a=1 #a=0代表这列1234行全相等
		if a==0:#4个数全相等
			num[0][j]=num[0][j]*2
			num[1][j]=num[0][j]
			num[2][j]=num[3][j]=0
			continue
		if num[0][j]==num[1][j] and num[2][j]==num[3][j] and num[1][j]!=num[2][j]:#1和2相等 3和4相等
			num[0][j]=num[0][j]*2
			num[1][j]=num[2][j]*2
			num[2][j]=num[3][j]=0
			continue
		if num[0][j]==num[1][j]:#1和2相等
			num[0][j]=num[0][j]*2
			num[1][j]=num[2][j]
			num[2][j]=num[3][j]
			num[3][j]=0
			continue
		if num[1][j]==num[2][j]:#2和3相等
			num[1][j]=num[1][j]*2
			num[2][j]=num[3][j]
			num[3][j]=0
			continue
		if num[2][j]==num[3][j]:#3和4相等
			num[2][j]=num[2][j]*2
			num[3][j]=0
			continue

def ina(num):
	for a in range(0,4):
		for i in range(0,4):
			for j in range(0,4):
				if num[i][j]==0:
					if j==3:
						continue
					else:
						num[i][j]=num[i][j+1]
						num[i][j+1]=0

	for i in range(0,4):#求和
		a=0;
		for j in range(0,3):
			if num[i][j]!=num[i][j+1]:
				a=1#a=0代表这列1234列全相等
		if a==0:#4个数全相等
			num[i][0]=num[i][0]*2
			num[i][1]=num[i][0]
			num[i][2]=num[i][3]=0
			continue
		if num[i][0]==num[i][1] and num[i][2]==num[i][3] and num[i][1]!=num[i][2]:#1列和2列相等 3列和4列相等
			num[i][0]=num[i][0]*2
			num[i][1]=num[i][2]*2
			num[i][2]=num[i][3]=0
			continue
		if num[i][0]==num[i][1]:#1和2相等
			num[i][0]=num[i][0]*2
			num[i][1]=num[i][2]
			num[i][2]=num[i][3]
			num[i][3]=0
			continue
		if num[i][1]==num[i][2]:#2和3相等
			num[i][1]=num[i][1]*2
			num[i][2]=num[i][3]
			num[i][3]=0
			continue
		if num[i][2]==num[i][3]:#3和4相等
			num[i][2]=num[i][2]*2
			num[i][3]=0
			continue

def ins(num):
	for a in range(0,4):#先移动
		for j in range(0,4):
			for i in range(3,-1,-1):
				if num[i][j]==0:
					if i==0:
						continue
					else:
						num[i][j]=num[i-1][j]
						num[i-1][j]=0
	for j in range(0,4):#求和
		a=0
		for i in range(0,3):
			if num[i][j]!=num[i+1][j]:
				a=1#a=0代表这列1234行全相等
		if a==0:#4个数全相等
			num[3][j]=num[3][j]*2
			num[2][j]=num[3][j]
			num[1][j]=num[0][j]=0
			continue
		if num[0][j]==num[1][j] and num[2][j]==num[3][j] and num[1][j]!=num[2][j]:#1和2相等 3和4相等
			num[3][j]=num[3][j]*2
			num[2][j]=num[1][j]*2
			num[0][j]=num[1][j]=0
			continue
		if num[2][j]==num[3][j]:#3和4相等
			num[3][j]=num[3][j]*2
			num[2][j]=num[1][j]
			num[1][j]=num[0][j]
			num[0][j]=0
			continue
		if num[1][j]==num[2][j]:#2和3相等
			num[2][j]=num[2][j]*2
			num[1][j]=num[0][j]
			num[0][j]=0
			continue
		if num[0][j]==num[1][j]:#1和2相等
			num[1][j]=num[1][j]*2
			num[0][j]=0
			continue

def ind(num):
	for a in range(0,4):#先移动
		for i in range(0,4):
			for j in range(3,-1,-1):
				if num[i][j]==0:
					if j==0:
						continue
					else:
						num[i][j]=num[i][j-1]
						num[i][j-1]=0

	for i in range(0,4):#求和
		a=0
		for j in range(0,3):
			if num[i][j]!=num[i][j+1]:
				a=1#a=0代表这列1234列全相等
		if a==0:#4个数全相等
			num[i][3]=num[i][3]*2
			num[i][2]=num[i][2]
			num[i][0]=num[i][1]=0
			continue
		if num[i][0]==num[i][1] and num[i][2]==num[i][3] and num[i][1]!=num[i][2]:#1列和2列相等 3列和4列相等
			num[i][3]=num[i][3]*2
			num[i][2]=num[i][1]*2
			num[i][0]=num[i][1]=0
			continue
		if num[i][2]==num[i][3]:#3和4相等
			num[i][3]=num[i][3]*2
			num[i][2]=num[i][1]
			num[i][1]=num[i][0]
			num[i][0]=0
			continue
		if num[i][1]==num[i][2]:#2和3相等
			num[i][2]=num[i][2]*2
			num[i][1]=num[i][0]
			num[i][0]=0
			continue
		if num[i][0]==num[i][1]:#1和2相等
			num[i][1]=num[i][1]*2
			num[i][0]=0
			continue


#main部分
num=[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
clear()
while 1:
    print("-------------------------")
    print(" welcome to 4x4 2048 game")
    print("     made by Yves")
    print("输入wasd其中一个来决定移动方向(大小写都可以)")
    print("-------------------------")
    print("      after move")
    shuchu(num)
    print("      new number")
    suijiweizhi(num)
    shuchu(num)
    print("-------------------------")
    panduan3=0
    while panduan3==0:
        shuru=input(">>your direction is(wasd):")
        shuru=shuru.lower()
        if shuru=="w" or shuru=="a" or shuru=="s" or shuru=="d":
            panduan3=1
            if shuru=="w":
                inw(num)
            elif shuru=="a":
                ina(num)
            elif shuru=="s":
                ins(num)
            elif shuru=="d":
                ind(num)
        else:
            print("wrong,please input again\n")
    clear()

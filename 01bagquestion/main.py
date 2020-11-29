#!/usr/bin/env python
# -*- coding:utf-8 -*-
# @Time  : 25/11/2020 下午 5:32
# @Author: xiaoni
# @File  : main.py
import json
import datetime
import time
import matplotlib.pyplot as plt


class form:
    def __init__(self, setting, W):

        self.setting = setting
        self.num = len(setting)
        self.W = int(W)
        self.matrix = [[0 for ii in range(self.W + 1)] for ii in range(self.num)]  # 创建临接矩阵

        for i in range(self.num):
            for w in range(1, self.W + 1):
                if setting[i]["weight"] <= w:
                    if (setting[i]["value"] + self.matrix[i][w - setting[i]["weight"]]) > self.matrix[i - 1][w]:
                        self.matrix[i][w] = setting[i]["value"] + self.matrix[i][w - setting[i]["weight"]]
                    else:
                        self.matrix[i][w] = self.matrix[i - 1][w]
                else:
                    self.matrix[i][w] = self.matrix[i - 1][w]
        self.maxValue = self.matrix[self.num - 1][self.W]

    def check(self):
        self.remainSpace = self.W
        print("最大value：" + str(self.maxValue))
        for i in range(self.num - 1, -1, -1):
            while self.matrix[i][self.remainSpace] - self.matrix[i][self.remainSpace - self.setting[i]["weight"]] == \
                    self.setting[i]["value"]:
                setting[i]["count"] = setting[i]["count"] + 1
                # with open(r"test.json", 'w') as fw:
                #     json.dump(setting, fw)
                print("第" + str(i + 1) + "个产品被选中，现在数量为" + str(setting[i]["count"]) + "个")
                self.remainSpace = self.remainSpace - self.setting[i]["weight"]
        print("李之龙 18061225 2020/11/24")

        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                print(str(self.matrix[i][j]) + " ", end="")
            print("")


class form1:
    def __init__(self, setting, W):

        self.setting = setting
        self.num = len(setting)
        self.W = int(W)
        self.array = [0 for ii in range(self.W + 1)]  # 创建滚动数组
        self.thingsArray = []
        self.allArray = []

        for i in range(self.num):
            if i == 0:
                for w in range(1, self.W + 1):
                    if setting[i]["weight"] <= w:
                        if (setting[i]["value"] + self.array[w - setting[i]["weight"]]) > self.array[w]:
                            self.array[w] = setting[i]["value"] + self.array[w - setting[i]["weight"]]
                            if i in self.thingsArray:
                                pass
                            else:
                                self.thingsArray.append(i)
                                self.allArray.append([setting[i]["weight"], setting[i]["value"]])
                        else:
                            self.array[w] = self.array[w]
                    else:
                        self.array[w] = self.array[w]
            else:
                for ii in range(len(self.allArray)):
                    if setting[i]["weight"] == self.allArray[ii][0] and setting[i]["value"] < self.allArray[ii][1]:
                        pass
                    else:
                        for w in range(1, self.W + 1):
                            if setting[i]["weight"] <= w:
                                if (setting[i]["value"] + self.array[w - setting[i]["weight"]]) > self.array[w]:
                                    self.array[w] = setting[i]["value"] + self.array[w - setting[i]["weight"]]
                                    if i in self.thingsArray:
                                        pass
                                    else:
                                        self.thingsArray.append(i)
                                        self.allArray.append([setting[i]["weight"], setting[i]["value"]])
                                else:
                                    self.array[w] = self.array[w]
                            else:
                                self.array[w] = self.array[w]


        self.maxValue = self.array[-1]

    def check(self):
        self.remainSpace = self.W
        print("最大value：" + str(self.maxValue))
        for i in self.thingsArray:
            while self.array[self.remainSpace] - self.array[self.remainSpace - self.setting[i]["weight"]] == \
                    self.setting[i]["value"]:
                setting[i]["count"] = setting[i]["count"] + 1
                # with open(r"test.json", 'w') as fw:
                #     json.dump(setting, fw)
                print("第" + str(i + 1) + "个产品被选中，现在数量为" + str(setting[i]["count"]) + "个")
                self.remainSpace = self.remainSpace - self.setting[i]["weight"]
        print("李之龙 18061225 2020/11/24")
        for i in range(len(self.array)):
            print(str(self.array[i]) + " ", end="")
            print()


if __name__ == '__main__':
    f = open(r"test.json", encoding='UTF-8')
    setting = json.load(f)

    fig = plt.figure()
    W = input("请输入背包容量:")

    found1 = []
    found2 = []
    start = time.clock()
    for i in range(100):
        Forms1 = form(setting, W)
        end = time.clock()
        found1.append(end - start)
    Forms1.check()

    start1 = time.clock()
    for i in range(100):
        Forms2 = form1(setting, W)
        end1 = time.clock()
        found2.append(end1 - start1)
    Forms2.check()

    times1 = []
    for i in range(100):
        times1.append(i * 0.001)

    plt.xlabel("The amount of data(*10^3)")
    # Y轴的文字
    plt.ylabel("Time")
    plt.title("Generalized backpack problem")

    plt.plot(times1, found1, label="$Not optimized$", color='red', linewidth=2)
    plt.plot(times1, found2, label="$The optimized$", color='blue', linewidth=2)
    plt.legend()
    plt.xlim(0.001, 0.1)
    plt.show()

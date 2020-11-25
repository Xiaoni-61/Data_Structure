#!/usr/bin/env python
# -*- coding:utf-8 -*-
# @Time  : 25/11/2020 下午 5:32
# @Author: xiaoni
# @File  : main.py
import json


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


if __name__ == '__main__':
    f = open(r"test.json", encoding='UTF-8')
    setting = json.load(f)
    W = input("请输入背包容量:")
    Forms1 = form(setting, W)
    Forms1.check()

# -*- coding: utf-8 -*-
"""
Created on Sun Aug 16 11:17:17 2020

@author: KayDee
"""

def fact(n):
    cache = {}
    def f(n):
        if n == 0:
            return 1
        if n not in cache:
            cache[n] = n*f(n-1)
        return cache[n]
    return f(n)



T = int(input())
while T:
    
    n = int(input())
    print(fact(n))
    T-=1
#!/usr/bin/env python
# coding: utf-8

# In[5]:


a=int(input("Enter a number: "))
sum = 0
temp = a
while temp > 0:
    digit = temp % 10
    sum += digit ** 3
    temp //= 10
if a == sum:
    print(a,"is an Armstrong number")
else:
    print(a,"is not an Armstrong number")


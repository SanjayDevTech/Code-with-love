#!/usr/bin/env python
# coding: utf-8

# In[10]:


a=input("Enter a string :")
if a==a[::-1]:
    print("Input string",a ," is a palindrome")
else:
    print("It is not a palindrome")


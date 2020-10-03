'''
 Patter printing program

author : @sb19
'''

def pattern(row,column):
    for i in range(0,row):
        
        for j in range(0,column):
            print("*", end=" ")
        
        print()


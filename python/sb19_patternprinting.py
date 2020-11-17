'''
 Patter printing program
 n*m  strik(*) pattren printing where n=no. of rows and m= no. of columns

author : @sb19
'''

def pattern(row,column):
    for i in range(0,row):
        
        for j in range(0,column):
            print("*", end=" ")
        
        print()



# Python regex to find sequences of one upper case letter 
# followed by lower case letters
# and Number associated with it

import re

NameAge = '''
Janice is 22 and Thanos is 33
ishan is 20 and Some 33
'''

#regex 
ages = re.findall(r'\d{1,3}', NameAge)
names = re.findall(r'[A-Z][a-z]*',NameAge)

#store result
ageDict =dict()
x=0
for eachname in names:
	ageDict[eachname]=ages[x]
	x+=1
print(ageDict)	

# OUTPUT WILL BE
# {'Janice': '22', 'Thanos': '33', 'Some': '20'}

#by :- kishanpython

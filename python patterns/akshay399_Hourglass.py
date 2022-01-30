def evenGlassHour(target):
 jsp=1
 jtop=target
 jbot=2
 jbotspace=int(target/2)
 eventarget=int(target/2)
 temp=""
 for i in range(eventarget):
     for j in range(i):
         temp+=" "
     for jsp in range(jtop):
         temp+="*"
     jtop-=2
     temp+="\n"
 for i in range(eventarget-1):
     for j in range(jbotspace-2):
         temp+=" "
     for j in range(jbot+2):
         temp+="*"
     jbot+=2
     jbotspace-=1
     temp+="\n"

 print(temp)

def oddGlassHour(target):

 jtop=target
 jbot=1
 jbotspace=int(target/2)
 oddtarget=int(target/2)
 temp=""
 for i in range(oddtarget):
     for j in range(i):
         temp+=" "
     for jsp in range(jtop):
         temp+="*"
     jtop-=2
     temp+="\n"
 for i in range(oddtarget+1):
     for j in range(jbotspace):
         temp+=" "
     for j in range(jbot):
         temp+="*"
     jbot+=2
     jbotspace-=1
     temp+="\n"

 print(temp)

target=int(input("Enter the number of rows: "))

if(target%2==0):
 evenGlassHour(target)
else:
 oddGlassHour(target)
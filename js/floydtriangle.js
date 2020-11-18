var tempStr = "",prevNumber=1,i,depth=10;
for(i=0;i<depth;i++){
  tempStr = "";j=0;
  while(j<= i){
        tempStr = tempStr + "    " + prevNumber;
        j++;
        prevNumber++;
}
console.log(tempStr);
}

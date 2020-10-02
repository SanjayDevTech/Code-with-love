let yyyy = 2020; //Year in yyyy format

let leapyear = function(year){
 let leap = null;
  if(year % 4 === 0)
   if(year % 100 === 0)
    if(year % 400 === 0) leap = true;
    else leap = false;
   else leap = true;
  else leap = false;
	
  if(leap) console.log(year + " is a leap year")
  else console.log(year + " is not leap year")
}

leapyear(yyyy)

function clock(){
    const hours=document.querySelector(".hours")
    const minutes=document.querySelector(".minutes")
    const seconds=document.querySelector(".seconds")

    hours.innerHTML=new Date().getHours();
    minutes.innerHTML=new Date().getMinutes();
    seconds.innerHTML=new Date().getSeconds();

    if(minutes.innerHTML.toString().length==1){
        minutes.innerHTML="0"+minutes.innerHTML;

    }

   

    if(seconds.innerHTML.toString().length==1){
        seconds.innerHTML="0"+seconds.innerHTML;
        
    }
    if(hours.innerHTML.toString().length==1){
        hours.innerHTML="0"+hours.innerHTML;
        
    }

}
const interval =setInterval(clock,1000)

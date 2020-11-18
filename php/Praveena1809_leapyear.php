<?php  
function isLeap($year)  
{  
    return (date('L', mktime(0, 0, 0, 1, 1, $year))==1);  
}  
//For testing  
for($year=1991; $year<2016; $year++)  
{  
    If (isLeap($year))  
    {  
        echo "$year : LEAP YEAR<br />\n";  
    }  
    else  
    {  
        echo "$year : Not leap year<br />\n";  
    }  
}  
?>  

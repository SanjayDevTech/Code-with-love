<?php
    echo "Enter an year: ";
    $year = intval(fgets(STDIN));
    $isLeap = "Leap";
    if($year % 100 == 0){
        if($year % 400){
            $isLeap = "Non Leap";
        }
    }
    else if($year % 4){
        $isLeap = "Non Leap";
    }
    echo "{$year} is a {$isLeap} year"
?>
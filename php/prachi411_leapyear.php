<html>
<head>
<title>Leap year or not</title></head>
<body>
<h1>This page will show the leap year</h1>
</body>
</html>

<?php
function year_check($my_year)
{
    echo $my_year;
    echo "";
   if ($my_year % 400 == 0)
      print("It is a leap year");
   else if ($my_year % 4 == 0)
      print("It is a leap year");
   else if ($my_year % 100 == 0)
      print("It is not a leap year");
   else
      print("It is not a leap year");
}
$my_year = 2024;
year_check($my_year);
?>
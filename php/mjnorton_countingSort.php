<?php
function counting_sort($my_array, $min, $max)
{
  $count = array();
  for($i = $min; $i <= $max; $i++)
  {
    $count[$i] = 0;
  }
 
  foreach($my_array as $number)
  {
    $count[$number]++; 
  }
  $z = 0;
  for($i = $min; $i <= $max; $i++) {
    while( $count[$i]-- > 0 ) {
      $my_array[$z++] = $i;
    }
  }
  return $my_array;
}
?>
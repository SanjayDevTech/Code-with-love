<?php
function shell_Sort($array)
{
	$count = round(count($array)/2);
	while($count > 0)
	{
		for($i = $count; $i < count($array);$i++){
			$temp = $array[$i];
			$j = $i;
			while($j >= $count && $array[$j-$count] > $temp)
			{
				$array[$j] = $array[$j - $count];
				$j -= $count;
			}
			$array[$j] = $temp;
		}
		$count = round($count/2.2);
	}
	return $array;
}
?>
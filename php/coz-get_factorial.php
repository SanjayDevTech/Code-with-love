<?php
  $n = $_POST['input'];
  $x = 1;
  for($i=1;$i<=$n-1;$i++) {
    $x*=($i+1); 
  }
?>

<?php if(!empty($x)) : ?>
  <div class="col-md-8">
    <h4>Faktor : <?= $x ?></h4>
  </div>
<?php endif ?>

<?php
    if($_POST) {
        $input = $_POST['text'];
        $text = strtolower(str_replace(' ', '', $input));
        $converArray = str_split($text);
    
        foreach ($converArray as $row => $value) {
            if(preg_match('/^[aiueo]/', $value)) {
                $vokal[] = $value;
                sort($vokal);
            } else {
                $konsonan[] = $value;
                sort($konsonan);
            }
        }
    }
?>

<?php if(!empty($vokal)) : ?>
  <div class="col-md-8">
    <h4>Huruf Vokal : <?= implode($vokal) ?></h4>
    <h4>Huruf Non Vokal : <?= implode($konsonan) ?></h4>
  </div>
<?php endif ?>

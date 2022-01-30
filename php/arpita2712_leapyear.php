<!Doctype html>
<html>
    <head>
        <title>Check Leap Year in PHP</title>
    </head>
    
    <body>
        <form action="" method="post">
            Enter a year:
            <input type="text" name="year" />
            <input type="submit"    name="submit"    value="Check" />
        </form>
    
        <?php
            if(isset($_POST['submit']))    {
                $year = $_POST['year'];
                if(((($year%4) == 0) && (($year%100) != 0)) || (($year%400) == 0)){
                    echo "$year IS a Leap Year";
                }  
                else
                echo "$year is NOT a Leap Year";
            }
        ?>
    </body>
</html>


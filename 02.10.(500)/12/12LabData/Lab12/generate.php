<?php
function gen_number($number) {
    for ($i = 1; $i <= $number; $i++) {

        yield rand(0,1000000);                        
    }
}
function gen_array($number) {
    $generator = gen_number($number);
    $arr = array();
    foreach  ($generator as $value) {
        $arr[] = $value;   
    }
    return $arr;
}
function viev_generated(){   
    $d  = gen_array(intval($_POST['textfield']));
    if ($_POST['select'] == "ASC"){
        sort($d);
    } else if ($_POST['select'] == "DASC"){
        rsort($d);
    }
    echo "<table class=\"rundom_table\">";
    echo "<tr>";
    echo "<th class=\"rundom_th\">Index</th>";
    echo "<th class=\"rundom_th\">Element</th>";
    echo "</tr>";
    $index = 1;
    foreach ($d as $v){
        echo "<tr>";       
        echo "<td class=\"rundom_td\">$index</td>";
        echo "<td class=\"rundom_td\" width=\"250%\">$v</td>";
        echo "</tr>";
        $index += 1;
    }
    echo "</table>";
}
?>
<div>
    <p>Це форма для генерування таблиці з випадковими числами<br><br>
        ASC - сортує числа у порядку зростяання<br> 
        DASC - сортує числа у порядку зростяання<br><br><br></p>
    <form name="form1" method="post" action="rundomForm.php">
    <p><label>Введіть кількість чисел<input type="text" name="textfield" id="textfield"></label></p>
    <p><label>Виберіть тип сортування  
        <select name="select"> <!--Supplement an id here instead of using 'name'-->
            <option value="ASC" selected>ASC</option>
            <option value="DASC">DASC</option>
        </select>
    </label></p>
    <p><label><input type="submit" name="button_generate" id="button" value="Згенерувати"></label></p>
    </form>
</div>
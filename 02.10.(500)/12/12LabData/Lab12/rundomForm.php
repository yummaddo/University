<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="content-type" content="text/html; charset=utf-8" />
        <title>Rundom number</title>
        <link href="css/default.css" rel="stylesheet" type="text/css" />
    </head>

<style>
    body {
  background-color: #66769A;
}
    .rundom_table {
        font-family: "Lucida Sans Unicode", "Lucida Grande", Sans-Serif;
        font-size: 14px;
        border-radius: 10px;
        border-collapse: collapse;
        text-align: center;
    }
    .rundom_th, .rundom_td:first-child {
        background: #AF4226;
        color: white;
        padding: 10px 20px;
    }
    .rundom_th, .rundom_td {
        border-style: solid;
        border-width: 0 1px 1px 0;
        border-color: white;
    }
    .rundom_td {
        background: #CE4D2D;
    }
    .rundom_th:first-child, .rundom_td:first-child {
        text-align: center;
    }
    .rundom_th:first-child {
        border-top-left-radius: 10px;
    }
    .rundom_th:last-child {
        border-top-right-radius: 10px;
        border-right: none;
    }  

    .workzone {
        display: block;
        background-color: #EC8950:
        height: 250;
    }

    .main {
        display: block;
        background-color: #FAA472;
        padding-top: 8%;
        padding-bottom: 15%;
        padding-left: 10%;
        padding-right: 10%;
        margin-left: 5%;
        margin-right: 5%;

    }
</style>

    <body>
        <div class="workzone">
            <div class="main">
            <?php include 'generate.php'; 
                if (isset($_POST['button_generate'])){
                    $text = $_POST['textfield'];
                    $type =  $_POST['select'];
                    if ($text != ""){
                        viev_generated();
                    }
                }
            ?>
            </div>
        </div>
    </body>
</html>

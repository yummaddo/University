<?php
    session_start();
    include("conf/conf.php");
    $dbConf = new AAConf();
    $databaseURL = $dbConf->get_databaseURL();
    $databaseUName = $dbConf->get_databaseUName();
    $databasePWord = $dbConf->get_databasePWord();
    $databaseName = $dbConf->get_databaseName();
    
        //Set DB Info. in-session
    $_SESSION['databaseURL']=$databaseURL; 
    $_SESSION['databaseUName']=$databaseUName; 
    $_SESSION['databasePWord']=$databasePWord; 
    $_SESSION['databaseName']=$databaseName;   
    

    //$connection = mysqli_connect($databaseURL,$databaseUName,$databasePWord);
        // or die ("Error while connecting to localhost");
    //$db = mysqli_select_db($databaseName,$connection);
        //or die ("Error while connecting to database");
        $mysqli = new mysqli($databaseURL,$databaseUName,$databasePWord,$databaseName);

        /*
         * This is the "official" OO way to do it,
         * BUT $connect_error was broken until PHP 5.2.9 and 5.3.0.
         */
        if ($mysqli->connect_error) {
            die('Connect Error (' . $mysqli->connect_errno . ') '
                    . $mysqli->connect_error);
        }
    $rowArray;
    $rowID = 1;
    $query = "SELECT * FROM Sectors";
    $result = mysqli_query($mysqli,$query);
    while($row = mysqli_fetch_array($result)){    
            $rowArray[$rowID] = $row['Sector'];   
            $rowID = $rowID +1;
        }  
        
        //Update the session with the sectors.
    $_SESSION['sectors']=$rowArray;    

    mysqli_close($mysqli);        
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta http-equiv="content-type" content="text/html; charset=utf-8" />
        <title>AirAlliance</title>
        <meta name="keywords" content="itinerary, list" />
        <meta name="description" content="This page provides a list of all itineraries" />
        <link href="css/default.css" rel="stylesheet" type="text/css" />
    </head>
    
    
    <body>
        <div id="wrapper">
        <?php include 'include/header.php'; ?>
            <!-- end div#header -->
            <div id="page">
                <div id="content">
                    <div id="welcome">
                        <h1>Ласкаво просимо до AirAlliance</h1>
                        <!--body-->
                        <p>
                            AirAlliance has evolved into one of the 
                            most respected travel brands around the world. 
                            We have one of the world's youngest fleet in the air,
                            a network spanning five continents.
                            Customers, investors, partners, and staff 
                            — everyone expects excellence of us. And so, in 
                            our lounges, our conferences, working relationships, 
                            and in the smallest details of flight, we rise to 
                            each occasion and deliver the AirAlliance 
                            experience. 
                        </p>
                        <p>
                            The airline operates over 370 flights daily 
                            across 44 destinations within  India and also 
                            operates flights to  United Kingdom,  United States 
                            of America,  Canada, Belgium,  Singapore, Thailand, 
                            Malaysia,  Nepal, Sri Lanka,  Bangladesh,  Bahrain,  
                            Kuwait,  Oman &  Qatar on one of the youngest and 
                            best maintained fleets. AirAlliance plans to extend 
                            its international operations further in North America, 
                            Europe, Africa & Asia in the coming years with the 
                            induction of wide-body aircraft into its fleet. 
                        </p>
                        
                        <p>
                            Feel the AirAlliance Experience!
                        </p>
               
                        
                        <!--body ends-->
                    </div>
                    
                    <!-- end div#welcome -->			
                    
                </div>
                <!-- end div#content -->
                <div id="sidebar">
                    <ul>
                    <?php include 'include/nav.php'; ?>
                        <!-- end navigation -->
                        <?php include 'include/updates.php'; ?>
                        <!-- end updates -->
                    </ul>
                </div>
                <!-- end div#sidebar -->
                <div style="clear: both; height: 1px"></div>
            </div>
            <?php include 'include/footer.php'; ?>
        </div>
        <!-- end div#wrapper -->
    </body>
</html>



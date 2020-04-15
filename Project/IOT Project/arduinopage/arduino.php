<!DOCTYPE html>
<html>
<head>
<style>

h1,h2{
  font-size: 30px;
  color: #fff;
  text-transform: uppercase;
  font-weight: 300;
  text-align: center;
  margin-bottom: 15px;
}
table{
  width:100%;
  table-layout: fixed;
}
.tbl-header{
  background-color: rgba(255,255,255,0.3);
 }
.tbl-content{
  height:385px;
  overflow-x:auto;
  margin-top: 0px;
  border: 1px solid rgba(255,255,255,0.3);
}
th{
  padding: 20px 15px;
 text-align: left;
  font-weight: 500;
  font-size: 12px;
  color: #fff;
  text-transform: uppercase;
}
td{
  padding: 15px;
  text-align: left;
  vertical-align:middle;
  font-weight: 300;
  font-size: 15px;
  color: #fff;
  border-bottom: solid 2px rgba(255,255,255,0.1);
}


/* demo styles */

@import url(https://fonts.googleapis.com/css?family=Roboto:400,500,300,700);
body{
  background: -webkit-linear-gradient(left, #25c481, #25b7c4);
  background: linear-gradient(to right, #25c481, #25b7c4);
  font-family: 'Roboto', sans-serif;
}
section{
  margin: 50px;
}


/* follow me template */
.made-with-love {
  margin-top: 40px;
  padding: 10px;
  clear: left;
  text-align: center;
  font-size: 10px;
  font-family: arial;
  color: #fff;
}
.made-with-love i {
  font-style: normal;
  color: #F50057;
  font-size: 14px;
  position: relative;
  top: 2px;
}
.made-with-love a {
  color: #fff;
  text-decoration: none;
}
.made-with-love a:hover {
  text-decoration: underline;
}


/* for custom scrollbar for webkit browser*/

::-webkit-scrollbar {
    width: 6px;
} 
::-webkit-scrollbar-track {
    -webkit-box-shadow: inset 0 0 6px rgba(0,0,0,0.3); 
} 
::-webkit-scrollbar-thumb {
    -webkit-box-shadow: inset 0 0 6px rgba(0,0,0,0.3); 
}

   img {
   border-radius: 50%;
   height: 60px;
   width: 60px;
}

</style>
<script>
// '.tbl-content' consumed little space for vertical scrollbar, scrollbar width depend on browser/os/platfrom. Here calculate the scollbar width .
$(window).on("load resize ", function() {
  var scrollWidth = $('.tbl-content').width() - $('.tbl-content table').width();
  $('.tbl-header').css({'padding-right':scrollWidth});
}).resize();
</script>
<meta http-equiv="refresh" content="3">
</head>
<body>
<?php
include_once 'ardconnect.php';
?>
<section>
  <!--for demo wrap-->
  <h1>BMS College Of Engineering </h1>
  <h2>Department of CSE</h2>
  <div class="tbl-header">
    <table cellpadding="0" cellspacing="0" border="0">
      <thead>
        <tr>
          <th>Faculty</th>
          <th>Name</th>
          <th>Designation</th>
          <th>Present At</th>
          <th>Status</th>
		  
        </tr>
      </thead>
    </table>
  </div>
  <div class="tbl-content">
    <table cellpadding="0" cellspacing="0" border="0">
      <tbody>
        <tr>
          <td><img src="Pani.png" alt="" /></td>
          <td>Dr. K Panimozhi</td>
          <td>Assistant Professor</td>
		 <?php
		   $result = mysqli_query($con, "SELECT `present_in`, `status` FROM `employee` WHERE tag_id='2700223092A7'") or die('Error');
		    while($row = mysqli_fetch_array($result)){
				$present = $row['present_in'];
				$status = $row['status'];
			 echo'<td>'. $present.'</td>';
             echo'<td>'. $status.'</td>';
			}
				?>  
         
		  
        </tr>
        <tr>
		  <td><img src="Nandini.png" alt="" /></td>
          <td>Nandhini vineeth</td>
          <td>Assistant Professor</td>
        <?php
		   $result = mysqli_query($con, "SELECT `present_in`, `status` FROM `employee` WHERE tag_id='2700195CA4C6'") or die('Error');
		    while($row = mysqli_fetch_array($result)){
				$present = $row['present_in'];
				$status = $row['status'];
			 echo'<td>'. $present.'</td>';
             echo'<td>'. $status.'</td>';
			}
				?>  
        </tr>
        <tr>
		  <td><img src="pradeep.png" alt="" /></td>
          <td>Pradeep Sadanand</td>
          <td>Assistant Professor</td>
          <?php
		   $result = mysqli_query($con, "SELECT `present_in`, `status` FROM `employee` WHERE tag_id='270022306257'") or die('Error');
		    while($row = mysqli_fetch_array($result)){
				$present = $row['present_in'];
				$status = $row['status'];
			 echo'<td>'. $present.'</td>';
             echo'<td>'. $status.'</td>';
			}
				?>  
          
        </tr>
        <tr>
          <td><img src="kavitha.png" alt="" /></td>
		  <td>Dr.Kavitha Sooda</td>
          <td>Assistant Professor</td>
         <?php
		   $result = mysqli_query($con, "SELECT `present_in`, `status` FROM `employee` WHERE tag_id='2700222DD4FC'") or die('Error');
		    while($row = mysqli_fetch_array($result)){
				$present = $row['present_in'];
				$status = $row['status'];
			 echo'<td>'. $present.'</td>';
             echo'<td>'. $status.'</td>';
			}
				?>  
          
        </tr>
        
      </tbody>
    </table>
  </div>
</section>
</body>
</html>

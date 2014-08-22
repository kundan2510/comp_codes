#! /bin/perl
$script="sc_yard.cpp";
$match_no=0;
'g++ $script';
@det1_tic=(25, 12, 5 , 3);
@det2_tic=(25, 12, 5 , 3);
@det3_tic=(25, 12, 5 , 3);
@thief_tic=(30 , 15 , 5 , 3);
print "Give initial Det1:";
$det1= <>;
chomp($det1);
print "Give initial Det2:";
$det2= <>;
chomp($det2);
print "Give initial Det3:";
$det3= <>;
chomp($det3);
print "Give initial thief:";
$thief= <>;
chomp($thief);

#Inintial positions are given now, now let us start the game.
$p=2; #Here thief one is playing
while (1==1){
	if ($p==1)
	{
		$input="$p $thief $det1 $det2 $det3 $thief_tic[0] $thief_tic[1] $thief_tic[2]" ;
		print $input."\n";
		$output=`echo $input | .\/a.out`;
		print "Thief tried to move  as $output";
		$i = substr($output , -2);
		@pos=split("$i",$output);
		chop($pos[0]);
		$thief=$pos[0];
		chomp($i);
		if($thief_tic[$i] == 0)
		{print "Sorry the $i tickets have expired. Thief looses. Fuck You!\n";exit;}
		$thief_tic[$i]--;
		$p=2;
	}
	else
	{
		$match_no = $match_no + 1;
		if ($match>=5)
		{$input="$p $thief $det1 $det2 $det3 $det1_tic[0] $det1_tic[1] $det1_tic[2] $det2_tic[0] $det2_tic[1] $det2_tic[2] $det3_tic[0] $det3_tic[1] $det3_tic[2]";}
		else
		{$input="$p 0 $det1 $det2 $det3 $det1_tic[0] $det1_tic[1] $det1_tic[2] $det2_tic[0] $det2_tic[1] $det2_tic[2] $det3_tic[0] $det3_tic[1] $det3_tic[2]";}
		
		print $input."\n";
		$output=`echo $input | .\/a.out`;
		@moves=split('\n',$output);
		for($j=1 ; $j<=3; $j++)
		{
			print "detetective$j tried to move as $moves[$j-1]\n";
			$i= substr($moves[$j-1] , -1);
			@pos1= split("$i" , $moves[$j-1]);
			$pos=$pos1[0];
			if($j==1)
			{
			if($det1_tic[$i] == 0)
		{print "Sorry the $i tickets have expired. det1 looses. Fuck You!\n";exit;}
			$det1=$pos;
			$det1_tic[$i]--;}
			elsif($j==2)
			{
			if($det2_tic[$i] == 0)
		{print "Sorry the $i tickets have expired. det2 looses. Fuck You!\n";exit;}
			$det2=$pos;
			$det2_tic[$i]--;
			}
			else
			{
			if($det3_tic[$i] == 0)
		{print "Sorry the $i tickets have expired. det3 looses. Fuck You!\n";exit;}
			$det3=$pos;
			$det3_tic[$i]--;}
		}
		$p=1;
	}
}

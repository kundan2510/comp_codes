#multiply.asm 
.text
 .globl main
 main:
 	li $a0, 8 			#allocating memory for first value in linked list for first number
 	li $v0, 9
 	syscall
 	li $s0 , 0			#length of first input 
 	move $t0, $v0 		#$t0 is pointer to first entry of linked list
 	move $t1, $v0 		#$t1 is head of the linked list
	read_input_1:
		addi $s0 , $s0 , 1
		li $v0, 5		#read input 
	 	syscall
	 	move $t2, $v0	#storing value of input in temporart variable $t2 
	 	sw $v0, 0($t1)	#storeing input in linked list
	 	li $a0, 8 		#allocating memory for next entry of linked list 
	 	li $v0, 9
	 	syscall
	 	sw $v0, 4($t1)	#updating current pointer so that it points to next entry of linked list
	 	move $t1, $v0
	 	bgt $t2,9, end_input_1 	#stop taking input when current entry element was 0
	 	j read_input_1
	end_input_1:
		li $a0, 8 			#allocating memory for first value in linked list
	 	li $v0, 9
	 	syscall
	 	li $s1 , 0
	 	move $t3, $v0 		#$t3 is pointer to first entry of second linked list
	 	move $t1, $v0 		#$t1 is head of the linked list
		read_input_2:
			addi $s1, $s1 , 1
			li $v0, 5		#read input 
		 	syscall
		 	move $t2, $v0	#storing value of input in temporart variable $t2 
		 	sw $v0, 0($t1)	#storeing input in linked list
		 	li $a0, 8 		#allocating memory for next entry of linked list 
		 	li $v0, 9
		 	syscall
		 	sw $v0, 4($t1)	#updating current pointer so that it points to next entry of linked list
		 	move $t1, $v0
		 	bgt $t2,9, end_input_2 	#stop taking input when current entry element was 0
		 	j read_input_2
	end_input_2:
		add $s2 , $s0 , $s1
		li $a0, 12 			#allocating memory for first value in linked list
	 	li $v0, 9
	 	syscall
	 	li $t5 , 0
	 	move $t2, $v0 		#$t2 is pointer to first entry of resultant linked list
	 	move $t1, $v0		#($t2 , $t0 and $t3 are not free)
	 	#fill s0 + $s1 zeros in this linked list
	 	#PUT EXIT HERE EVERTHING RUNS FINE
	 	fill_zero:
	 		li $t4 , 0
	 		sw $t4 , 0($t1)
	 		li $a0, 12 			
	 		li $v0, 9
	 		syscall				#find the error here :/
	 		sw $v0, 4($t1)
	 		sw $t1 , 8($v0)
	 		move $t1 , $v0
	 		addi $t5 , $t5 , 1
	 		bgt $t5 , $s2 , end_fill_zero
	 		j fill_zero
	 	end_fill_zero: #this function initialises the result linked list
	 	move $a0 , $t0		#pointer to 1st digit of 1st argument
	 	move $a1 , $t3		#pointer to 1st digit of 2nd argument
	 	move $a2 , $t2		#pointer to 1st digit of result 
	 	move $t8 , $t1		#$t8 stores the last digit of answer , lentgh of all these lists are in $s0 , $s2 , $s3 repectively
	 	jal multiply     #jumping to multiply function
	 	#updating $a0 to 1st non zero element in result
	 	move $t3 , $a2
	 	li $t4 , 10
	 	li $t5 , 0
	 	carry:    #initially in multiply we didn't care about the carry. we just put number according to their appropriate place value
	 				#this function makes a pass over the resulting array and adjust carry
	 		lw $t2 , 0($t3)
	 		add $t2 , $t2 , $t5
	 		div $t2, $t4  #dividing the value of $a0 by $a1 and storing dividend in lo and remainder in hi
			mfhi $t2     #transfering the value of remainder to a temp register
	 		mflo $t1
	 		move $t5 , $t1
	 		sw $t2 , 0($t3)
	 		add $t6 , $t5 , $t2
	 		beqz $t6 , end_carry
	 		lw $t3 , 4($t3)
	 		j carry
	 	end_carry: #when we are done with carry adjustment, we go to print the result
	 		lw $t8 , 8($t3)
	 		j print_result

	 	print_result:
	 		lw $a0 , 0($t8)		
		    li $v0, 1
			syscall	
			beq $a2 , $t8 , exit
			lw $t8 , 8($t8)
			j print_result

exit:
	li $v0, 10
	syscall

multiply:
	move $t9 , $ra 			#return address for multiply 
	li $t0 , 1              #
	loop_first:          #this loop iterates over the digits of a multiplicand with $t0 containing the position of the digit from the most significant digit
		bge $t0 , $s0 , return_multiply
		li $t1 , 1
		loop_second: # #this loop iterates over the digits of a multiplier with $t1 containing the position of the digit from the most significant digit
			bge $t1 , $s1 , return_loop_second

			sub $t2 , $s0 , $t0
			move $a3 , $a0
			jal find_addr 
			lw $t3 , 0($v0)				# $t3 will contain input1[t0] 

			sub $t2 , $s1 , $t1
			move $a3 , $a1
			jal find_addr
			lw $t4 , 0($v0)				#$t3 will contain input2[t1]

			add $t2 , $t0 , $t1
			add $t2 , $t2 , -1
			move $a3 , $a2
			jal find_addr
			mul $t3 , $t3 , $t4			#now $t3=input1[t0]*input2[t1]
			lw $t4 , 0($v0)				
			add $t3 , $t3 , $t4 
			sw $t3 , 0($v0)				#result[t0+t1]+=$t3

			addi $t1 ,$t1 , 1
			j loop_second
		return_loop_second:
			addi $t0 ,$t0 , 1
			j loop_first

return_multiply:
	j $t9	

find_addr:			#return the pointer to $t2 location in linked list with start point $a3 in registor $v0
	li $t5 , 1
	move $v0 , $a3
	loop_find:
		bge $t5 , $t2 , return_find_addr
		lw $v0 , 4($v0)  #offset is 4 because in each input and result address to next pointer is stored at an offset 4
		addi $t5 ,$t5 , 1
		j loop_find
return_find_addr:
	j $ra
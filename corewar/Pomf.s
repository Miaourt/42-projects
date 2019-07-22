.name "Pomf"
.comment "Wah! What we gonna do on the bed?"
		st r1, 44			#5
		st r1, 34			#5
		st r1, 11			#5
		st r2, -4			#5
live:	live %1				#5
		zjmp %:live			#2
		and r2, %0, r16 	#8
forky:	fork %:live			#3
		live %1				#5
		st r1, -255			#5
		st r1, 256			#5
		fork %:forky		#3
		live %1				#5
		st r1, -255			#5
		st r1, 256			#5
		zjmp %:forky		#2

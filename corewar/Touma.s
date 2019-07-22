.name "Touma"
.comment "C'est TOUMA!"
		st r1, 44			#5
		st r1, 34			#5
		st r1, 11			#5
		st r2, -4			#5
live:	live %1				#5
		zjmp %:live			#2
		and r2, %0, r16 	#8

		fork %:live			#3
		live %1				#5

		st	r2, 256
		st	r2, 256
		ldi	%:gun, %0, r2
gun: 	st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256
		st	r2, 256

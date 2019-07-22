class dalek =
	object
		initializer print_endline ("Blap, creation d'un dalek.")

		val _name:string = "Dalek" ^ String.make 1 (String.get "ABCDEFGHIJKLMNOPQRSTUVWXYZ" (Random.int 26)) ^ 
						String.make 1 (String.get "abcdefghijklmnopqrstuvwxyz" (Random.int 26)) ^ 
						String.make 1 (String.get "abcdefghijklmnopqrstuvwxyz" (Random.int 26))
		val mutable _hp:int = 100
		val mutable _shield:bool = true
		
		method to_string = ("Zap, I'm " ^ _name ^ ", my shield is " ^ string_of_bool _shield ^ " and I have " ^ string_of_int _hp ^ " health points !")
		method talk = match Random.int 4 with
			| 0 -> print_endline "Explain! Explain!"
			| 1 -> print_endline "Exterminate! Exterminate!"
			| 2 -> print_endline "I obey!"
			| _ -> print_endline "You are the Doctor! You are the enemy of the Daleks!"
		method exterminate (tokill : People.people) = tokill#die
		method die = print_endline "Emergency Temporal Shift!"
		
	end
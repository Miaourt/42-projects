class doctor sonNomDeSesMords sonAgeDeSesMords sonSidekickDeSesMords =
	object
		initializer print_endline ("Zup, creation d'un docteur de type \"Doctor\".")

		val _name:string = sonNomDeSesMords
		val mutable _age:int = sonAgeDeSesMords
		val _sidekick:People.people = sonSidekickDeSesMords
		val mutable _hp:int = 100

		method to_string = ("Zap, I'm " ^ _name ^ " a Doctor, I'm " ^ string_of_int _age ^ " years old and I have " ^ string_of_int _hp ^ " health points !")
		method talk = print_endline "Hi! I’m the Doctor!"
		method travel_in_time start arrival =
			_age <- _age + (arrival - start);
			print_endline "        ___\n_______(_@_)_______\n| POLICE      BOX |\n|_________________|\n | _____ | _____ |\n | |###| | |###| |\n | |###| | |###| | \n | _____ | _____ |\n | || || | || || |\n | ||_|| | ||_|| |\n | _____ |$_____ |\n | || || | || || |\n | ||_|| | ||_|| |\n | _____ | _____ |\n | || || | || || | \n | ||_|| | ||_|| | \n |       |       | \n *****************"
		method use_sonic_screwdriver = print_endline "Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii";
		method hurt = _hp <- _hp - 10;
		method regenerate = _hp <- 100
	end
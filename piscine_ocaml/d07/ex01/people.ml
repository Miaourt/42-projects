class people sonNomDeSesMords =
    object
        initializer print_endline ("Bip boup, creation d'un humain de type \"people\".")

        val _name:string = sonNomDeSesMords
        val mutable _hp:int = 100

        method to_string = ("Boup bip, I'm " ^ _name ^ " an Human and I have " ^ string_of_int _hp ^ " health points !")
        method talk = print_endline ("I’m " ^ _name ^ "! Do you know the Doctor?")
        method die = print_endline "Aaaarghh!"
    end
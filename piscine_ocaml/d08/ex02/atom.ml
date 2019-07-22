class virtual atom n s a =
    object (self)
        method name : string = n
        method symbol : string = s 
        method atomic_number : int = a

        method to_string = (self#name ^ "[" ^ string_of_int self#atomic_number ^ "]")
        method print_endline = print_endline self#to_string
        method equals (x : atom) = compare self#atomic_number x#atomic_number
    end

class hydrogen =
    object
        inherit atom "Hydrogen" "H" 1
    end

class carbon =
    object
        inherit atom "Carbon" "C" 6
    end

class oxygen =
    object
        inherit atom "Oxygen" "O" 8
    end

class nitrogen =
    object
        inherit atom "Nitrogen" "N" 7
    end

class lithium =
    object
        inherit atom "Lithium" "Li" 3
    end

class potassium =
    object
        inherit atom "Potassium" "K" 19
    end

class titanium =
    object
        inherit atom "Titanium" "Ti" 22
    end

class tungsten =
    object
        inherit atom "Tungsten" "W" 74
    end

class rutherfordium =
    object
        inherit atom "Rutherfordium" "Rf" 104
    end

class ununpentium =
    object
        inherit atom "Ununpentium" "Uup" 115
    end
class virtual alkane n =
    object (self)

        method formula = match n with
                    | 1 -> "C1H4" 
                    | 2 -> "C2H6"
                    | 4 -> "C8H18"
                    | _ -> "C99999999H99999999"

        method name = match n with
                    | 1 -> "Methane" 
                    | 2 -> "Ethane"
                    | 4 -> "Octane"
                    | _ -> "Wtftane"
        
        method to_string = self#name ^ " " ^ self#formula

        method equals (x : alkane) = compare (self#formula) (x#formula)
    end

class methane =
    object
        inherit alkane 1
    end

class ethane =
    object
        inherit alkane 2
    end

class octane =
    object
        inherit alkane 4
    end

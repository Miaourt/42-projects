let () =
    let rec print_list = function 
        [] -> ()
        | e::l -> print_string (Value.toStringVerbose e) ; print_string " " ; print_list l
    in
    print_string "Value.all = [ "; print_list (Value.all) ; print_endline "]";
    print_string "Value.toInt of T6 = "; print_endline (string_of_int (Value.toInt Value.T6));
    print_string "Value.toString of Jack = "; print_endline (Value.toString Value.Jack);
    print_string "Value.toStringVerbose of T10 = "; print_endline (Value.toStringVerbose Value.T10);
    print_string "Value.previous of Queen = "; print_endline (Value.toStringVerbose (Value.previous Value.Queen));
    print_string "Value.next of Jack = "; print_endline (Value.toStringVerbose (Value.next Value.Queen));
    print_string "Value.next of As = "; print_endline (Value.toStringVerbose (Value.next Value.As))
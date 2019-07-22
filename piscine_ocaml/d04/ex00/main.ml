let () =
    let rec print_list = function 
        [] -> ()
        | e::l -> print_string (Color.toStringVerbose e) ; print_string " " ; print_list l
    in
    print_string "Color.all = [ "; print_list (Color.all) ; print_endline "]";
    print_string "Color.toString of Heart = "; print_endline (Color.toString Color.Heart);
    print_string "Color.toStringVerbose of Diamond = "; print_endline (Color.toStringVerbose Color.Diamond)
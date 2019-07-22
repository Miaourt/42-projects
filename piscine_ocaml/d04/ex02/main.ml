let () =
    let rec printList = function 
        [] -> ()
        | e::l -> print_string (Card.toString e) ; print_string " " ; printList l
    in
    let rec printListVerbose = function 
        [] -> ()
        | e::l -> print_string (Card.toStringVerbose e) ; print_string " " ; printListVerbose l
    in
    print_endline "";
    print_string "Card.allSpades = [ "; printList (Card.allSpades) ; print_endline "]";
    print_endline "";
    print_string "Card.allHearts = [ "; printList (Card.allHearts) ; print_endline "]";
    print_endline "";
    print_string "Card.allDiamonds = [ "; printList (Card.allDiamonds) ; print_endline "]";
    print_endline "";
    print_string "Card.allClubs = [ "; printList (Card.allClubs) ; print_endline "]";
    print_endline "";
    print_string "Card.all = [ "; printList (Card.all) ; print_endline "]";
    print_endline "";
    print_string "Card.all (Verbose) = [ "; printListVerbose (Card.all) ; print_endline "]";
    print_endline "";
    print_endline "";
    print_string "Card.compare of 2S & 5H = "; print_endline (string_of_int (Card.compare (Card.newCard Card.Color.Spade Card.Value.T2) (Card.newCard Card.Color.Heart Card.Value.T5)));
    print_string "Card.compare of QS & 5H = "; print_endline (string_of_int (Card.compare (Card.newCard Card.Color.Spade Card.Value.Queen) (Card.newCard Card.Color.Heart Card.Value.T5)));
    print_string "Card.compare of 5D & 5H = "; print_endline (string_of_int (Card.compare (Card.newCard Card.Color.Diamond Card.Value.T5) (Card.newCard Card.Color.Heart Card.Value.T5)));
    print_endline "";
    print_string "Card.max of 4D & 5H = "; print_endline (Card.toStringVerbose (Card.max (Card.newCard Card.Color.Diamond Card.Value.T4) (Card.newCard Card.Color.Heart Card.Value.T5)));
    print_string "Card.min of 4D & 5H = "; print_endline (Card.toStringVerbose (Card.min (Card.newCard Card.Color.Diamond Card.Value.T4) (Card.newCard Card.Color.Heart Card.Value.T5)));    print_endline "";
    print_string "Card.best of QS, KH, 4D & 5H = "; print_endline (Card.toStringVerbose (Card.best ([(Card.newCard Card.Color.Spade Card.Value.Queen); (Card.newCard Card.Color.Heart Card.Value.King); (Card.newCard Card.Color.Diamond Card.Value.T4); (Card.newCard Card.Color.Heart Card.Value.T5)])));
    print_endline "";
    print_string "Card.isOf QS & Color.Spade = "; print_endline (string_of_bool (Card.isOf (Card.newCard Card.Color.Spade Card.Value.Queen) Card.Color.Spade));
    print_string "Card.isOf QS & Color.Heart = "; print_endline (string_of_bool (Card.isOf (Card.newCard Card.Color.Spade Card.Value.Queen) Card.Color.Heart))



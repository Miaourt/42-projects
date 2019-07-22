let fibonacci n =
    let rec runner ?(a = 0) ?(b = 1) n =
        if n < 0 then -1
        else if n = 0 then a
        else if n = 1 then b
        else runner ~a:b ~b:(a + b) (n - 1)
    in
    runner n

let tests () =
	print_endline ("Test with -42 : " ^ string_of_int (fibonacci (-42)));
	print_endline ("Test with 1 : " ^ string_of_int (fibonacci 1));
	print_endline ("Test with 3 : " ^ string_of_int (fibonacci 3));
	print_endline ("Test with 6 : " ^ string_of_int (fibonacci 6));
	print_endline ("Test with 1000 : " ^ string_of_int (fibonacci 1000));
	print_endline ("Test with 1000000 : " ^ string_of_int (fibonacci 1000000))

let () = tests ()
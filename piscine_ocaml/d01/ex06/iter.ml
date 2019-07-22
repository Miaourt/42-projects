let iter f x n =
    let rec runner f x n =
        if n = 1 then f (x)
        else runner f (f x) (n - 1)
    in
    if n < 0 then -1
    else if n = 0 then x
    else runner f x n

let tests () =
	print_endline ("Test with (fun x -> x * x ) 2 4 : " ^ string_of_int (iter (fun x -> x * x ) 2 4));
	print_endline ("Test with (fun x -> x * 2 ) 2 4 : " ^ string_of_int (iter (fun x -> x * 2 ) 2 4));
	print_endline ("Test with (fun x -> x * x ) 5 5 : " ^ string_of_int (iter (fun x -> x * x ) 5 5))

let () = tests ()
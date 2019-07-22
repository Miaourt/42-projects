let rec converges f x n =
    if n <= 0 then f x = x
    else if f x = x then true
    else converges f (f x) (n - 1)

let tests () =
	print_endline ("Test with (( * ) 2) 2 5 : " ^ string_of_bool (converges (( * ) 2) 2 5));
	print_endline ("Test with (fun x -> x / 2) 2 3 : " ^ string_of_bool (converges (fun x -> x / 2) 2 3));
	print_endline ("Test with (fun x -> x / 2) 2 2 : " ^ string_of_bool (converges (fun x -> x / 2) 2 2))

let () = tests ()
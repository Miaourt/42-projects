let rec repeat_x n =
    if n < 0 then "Error"
    else if n = 0 then ""
    else "x" ^ (repeat_x (n - 1))

let tests () =
	print_string ("Test with 0 : " ^ (repeat_x 0) ^ "\n");
	print_string ("Test with 1 : " ^ (repeat_x 1) ^ "\n");
	print_string ("Test with 5 : " ^ (repeat_x 5) ^ "\n");
	print_string ("Test with 100 : " ^ (repeat_x 100) ^ "\n");
	print_string ("Test with -1 : " ^ (repeat_x (-1)) ^ "\n");
	print_string ("Test with -5 : " ^ (repeat_x (-5)) ^ "\n")

let () = tests ()
let rec repeat_string ?(str="x") n =
    if n < 0 then "Error"
    else if n = 0 then ""
    else str ^ (repeat_string ~str:str (n - 1))

let tests () =
	print_string ("Test with 0 : " ^ (repeat_string 0) ^ "\n");
	print_string ("Test with 1 : " ^ (repeat_string 1) ^ "\n");
	print_string ("Test with 5 : " ^ (repeat_string 5) ^ "\n");
	print_string ("Test with 100 : " ^ (repeat_string 100) ^ "\n");
	print_string ("Test with -1 : " ^ (repeat_string (-1)) ^ "\n");
	print_string ("Test with -5 : " ^ (repeat_string (-5)) ^ "\n");
	print_string ("Test with \"Miaouh\" 0 : " ^ (repeat_string ~str:"Miaouh" 0) ^ "\n");
	print_string ("Test with \"Miaouh\" 1 : " ^ (repeat_string ~str:"Miaouh" 1) ^ "\n");
	print_string ("Test with \"Miaouh\" 5 : " ^ (repeat_string ~str:"Miaouh" 5) ^ "\n");
	print_string ("Test with \"Miaouh\" -1 : " ^ (repeat_string ~str:"Miaouh" (-1)) ^ "\n");
	print_string ("Test with \"Miaouh\" -5 : " ^ (repeat_string ~str:"Miaouh" (-5)) ^ "\n")

let () = tests ()